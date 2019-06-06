#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cassert>

using namespace std;

string Decompress(stringstream& ss) {
    string tmp;
    ss >> tmp;

    if (tmp.empty())
        return {};
    if (!isdigit(tmp[0]))
        return tmp;

    int cnt = stoi(tmp);
    string remain = Decompress(ss);
    string result;
    for (int i = 0; i < cnt; ++i)
        result += remain;
    return result;
}

string Solve(string s) {
    for (auto& c : s) {
        if (c == '[' || c == ']')
            c = ' ';
    }

    stringstream ss(s);
    return Decompress(ss);
}

int main() {
    assert(Solve("10[a]") == "aaaaaaaaaa");
    assert(Solve("2[3[a]b]") == "aaabaaab");
    assert(Solve("3[abc]4[ab]c") == "abcabcabcababababc");
}
