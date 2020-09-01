#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string normalize(const string& s) {
        auto it = find(s.begin(), s.end(), '@');

        string local(s.begin(), it);
        local.erase(find(local.begin(), local.end(), '+'), local.end());
        local.erase(remove(local.begin(), local.end(), '.'), local.end());

        string result(local);
        result.append(it, s.end());
        return result;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;
        for (auto& email : emails)
            uniq.emplace(normalize(email));
        return uniq.size();
    }
};
