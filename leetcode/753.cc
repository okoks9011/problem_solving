#include <unordered_set>
#include <string>


using namespace std;


class Solution {
  public:
    bool GenPass(string* result_ptr, unordered_set<string>* visited_ptr,
                 int n, int k, int total) {
        auto& visited = *visited_ptr;
        if (visited.size() == total)
            return true;

        auto& result = *result_ptr;
        string cur = result.substr(result.size()-n+1);
        cur += '0';
        for (int i = 0; i < k; ++i) {
            cur.back() = i + '0';
            if (visited.find(cur) != visited.end())
                continue;
            visited.emplace(cur);
            result += i + '0';
            if (GenPass(result_ptr, visited_ptr, n, k, total))
                return true;
            result.pop_back();
            visited.erase(cur);
        }
        return false;
    }

    string crackSafe(int n, int k) {
        string result(n, '0');
        unordered_set<string> visited{result};

        int total = 1;
        for (int i = 0; i < n; ++i)
            total *= k;

        GenPass(&result, &visited, n, k, total);
        return result;
    }
};
