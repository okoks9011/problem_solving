#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cassert>


using namespace std;


class Solution {
  public:
    string GetFileName(string buf) {
        auto it = buf.find('(');
        if (it == string::npos)
            assert(false);
        return buf.substr(0, it);
    }

    string GetContents(string buf) {
        auto sit = buf.find('(');
        if (sit == string::npos)
            assert(false);
        auto eit = buf.find(')');
        if (eit == string::npos)
            assert(false);
        return buf.substr(sit+1, eit-sit-1);
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> group;
        for (auto& path : paths) {
            stringstream ss(path);
            string dir;
            ss >> dir;
            dir += "/";

            string buf;
            while (ss >> buf) {
                string file_name = GetFileName(buf);
                string contents = GetContents(buf);
                group[contents].emplace_back(dir + file_name);
            }
        }

        vector<vector<string>> result;
        for (auto& p : group) {
            if (p.second.size() >= 2)
                result.emplace_back(p.second);
        }
        return result;
    }
};
