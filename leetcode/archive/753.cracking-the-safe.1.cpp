#include <unordered_set>
#include <string>

using namespace std;

class Solution {
  public:
    void dfs(const string& cur, int k, unordered_set<string>* visited_ptr, string* result_ptr) {
        auto& visited = *visited_ptr;
        auto& result = *result_ptr;
        for (int i = 0; i < k; ++i) {
            string next(cur);
            next += static_cast<char>(i+'0');
            if (visited.find(next) != visited.end())
                continue;

            visited.emplace(next);
            dfs(next.substr(1), k, visited_ptr, result_ptr);
            result += next.back();
        }
    }

    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string result;

        string start(n-1, '0');
        dfs(start, k, &visited, &result);
        result += start;

        return result;
    }
};
