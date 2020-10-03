#include <string>
#include <vector>


using namespace std;


class Solution {
  public:
    int FindNextOpen(const string& line) {
        auto t1 = line.find("//");
        auto t2 = line.find("/*");
        return min(t1, t2);
    }

    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool block = false;
        for (auto& line : source) {
            bool compact = block;
            int del_start = 0;
            int search_start = 0;
            while (true) {
                if (!block) {
                    auto t = FindNextOpen(line);
                    if (t == string::npos)
                        break;
                    auto token = line.substr(t, 2);
                    if (token == "//") {
                        line.erase(t);
                        break;
                    } else if (token == "/*") {
                        del_start = t;
                        search_start = t + 2;
                        block = true;
                    }
                } else {
                    auto t = line.find("*/", search_start);
                    if (t != string::npos) {
                        line.erase(del_start, t - del_start + 2);
                        block = false;
                    } else {
                        line.erase(del_start);
                        break;
                    }
                }
            }

            if (!line.empty()) {
                if (compact)
                    result.back() += line;
                else
                    result.emplace_back(line);
            }
        }
        return result;
    }
};
