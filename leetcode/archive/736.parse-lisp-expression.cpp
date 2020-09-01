#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <cctype>
#include <utility>
#include <algorithm>

using namespace std;

enum ExprType {
    kInt = 0,
    kVar,
    kAdd,
    kMult,
    kLet,
};

struct Expr {
    ExprType t = kInt;
    int val = 0;
    string var;
    vector<Expr> args;
};

class Solution {
  public:
    vector<string> tokenize(const string& exp) {
        stringstream ss(exp);
        vector<string> result;
        string tmp;
        while (ss >> tmp) {
            int i = 0;
            for (; i < tmp.size(); ++i) {
                if (tmp[i] == '(' || tmp[i] == ')')
                    result.emplace_back(1, tmp[i]);
                else
                    break;
            }

            int j = i;
            while (j < tmp.size() && (tmp[j] != '(' && tmp[j] != ')'))
                ++j;
            result.emplace_back(tmp.substr(i, j-i));

            for (; j < tmp.size(); ++j) {
                if (tmp[j] == '(' || tmp[j] == ')')
                    result.emplace_back(1, tmp[j]);
                else
                    break;
            }
        }
        return result;
    }

    Expr parse(vector<string>::iterator* it_ptr) {
        auto& it = *it_ptr;
        if (*it == "(") {
            ++it;
            ExprType t;
            if (*it == "add") {
                t = kAdd;
            } else if (*it == "mult") {
                t = kMult;
            } else if (*it == "let") {
                t = kLet;
            } else {
                assert(false);
            }
            ++it;

            vector<Expr> args;
            while (*it != ")") {
                args.emplace_back(parse(it_ptr));
            }
            ++it;

            Expr result;
            result.t = t;
            result.args = args;
            return result;
        }

        if (isdigit((*it)[0]) || (*it)[0] == '-') {
            Expr result;
            result.t = kInt;
            result.val = stoi(*it);
            ++it;
            return result;
        }

        Expr result;
        result.t = kVar;
        result.var = *it;
        ++it;
        return result;
    }

    int evalExpr(Expr e, vector<pair<string, int>>* context_ptr) {
        auto& context = *context_ptr;
        switch (e.t) {
            case kInt: {
                return e.val;
                break;
            }
            case kVar: {
                auto it = find_if(context.rbegin(), context.rend(),
                                  [&](const pair<string, int>& p){ return p.first == e.var; });
                assert(it != context.rend());
                return it->second;
                break;
            }
            case kAdd: {
                int result = 0;
                for (auto& arg : e.args)
                    result += evalExpr(arg, context_ptr);
                return result;
            }
            case kMult: {
                int result = evalExpr(e.args[0], context_ptr);
                for (int i = 1; i < e.args.size(); ++i)
                    result *= evalExpr(e.args[i], context_ptr);
                return result;
            }
            case kLet: {
                int val_size = e.args.size() / 2;
                for (int i = 0; i < val_size; ++i) {
                    string cur_var = e.args[2*i].var;
                    int cur_val = evalExpr(e.args[2*i+1], context_ptr);
                    context.emplace_back(cur_var, cur_val);
                }
                int result = evalExpr(e.args.back(), context_ptr);
                context.erase(context.end()-val_size, context.end());
                return result;
            }
            default: {
                assert(false);
                break;
            }
        }
        assert(false);
    }

    int evaluate(string exp) {
        vector<string> tokens = tokenize(exp);
        auto it = tokens.begin();
        auto e = parse(&it);

        vector<pair<string, int>> context;
        return evalExpr(e, &context);
    }
};
