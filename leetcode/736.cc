#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <cctype>


using namespace std;


enum ExpType {
    kInt,
    kLet,
    kAdd,
    kMult,
    kVar
};

struct Exp {
    ExpType t = kInt;
    int value = 0;
    vector<pair<string, Exp>> env;
    vector<Exp> args;
    string var_name;
};

class Solution {
  public:
    Exp parseExp(vector<string>::iterator* it_ptr) {
        auto& it = *it_ptr;
        Exp result;

        if (*it == "(") {
            ++it;
            if (*it == "add" || *it == "mult") {
                if (*it == "add")
                    result.t = kAdd;
                else if (*it == "mult")
                    result.t = kMult;
                else
                    assert(false);
                ++it;

                result.args.emplace_back(parseExp(it_ptr));
                result.args.emplace_back(parseExp(it_ptr));
            } else if (*it == "let") {
                result.t = kLet;
                ++it;

                while (true) {
                    Exp tmp = parseExp(it_ptr);
                    if (*it == ")") {
                        result.args.emplace_back(tmp);
                        break;
                    } else if (tmp.t == kVar) {
                        result.env.emplace_back(tmp.var_name, parseExp(it_ptr));
                    } else {
                        assert(false);
                    }
                }
            } else {
                assert(false);
            }
            ++it;  // remove ')'
        } else if (islower((*it)[0])) {
            result.t = kVar;
            result.var_name = *it;
            ++it;
        } else if (isdigit((*it)[0]) || (*it)[0] == '-') {
            result.t = kInt;
            result.value = stoi(*it);
            ++it;
        } else {
            assert(false);
        }
        return result;
    }

    int EvalExp(Exp cur, vector<pair<string, int>> env) {
        switch (cur.t) {
            case kInt: {
                return cur.value;
            }
            case kLet: {
                for (auto& p : cur.env) {
                    int en = EvalExp(p.second, env);
                    env.emplace_back(p.first, en);
                }
                int v = EvalExp(cur.args[0], env);
                env.erase(env.end()-cur.env.size(), env.end());
                return v;
            }
            case kAdd: {
                int v1 = EvalExp(cur.args[0], env);
                int v2 = EvalExp(cur.args[1], env);
                return v1 + v2;
            }
            case kMult: {
                int v1 = EvalExp(cur.args[0], env);
                int v2 = EvalExp(cur.args[1], env);
                return v1 * v2;
            }
            case kVar: {
                for (auto rit = env.rbegin(); rit != env.rend(); ++rit) {
                    if (rit->first == cur.var_name)
                        return rit->second;
                }
                assert(false);
            }
            default: {
                assert(false);
            }
        }
        assert(false);
    }

    int evaluate(string expression) {
        string gap;
        for (auto& c : expression) {
            if (c == ')' || c == '(') {
                gap += ' ';
                gap += c;
                gap += ' ';
            } else {
                gap += c;
            }
        }

        stringstream ss(gap);
        vector<string> tokens;
        string buf;
        while (ss >> buf)
            tokens.emplace_back(buf);

        auto it = tokens.begin();
        Exp exp = parseExp(&it);
        return EvalExp(exp, {});
    }
};
