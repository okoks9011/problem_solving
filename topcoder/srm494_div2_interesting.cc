#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class InterestingParty {
  public:
    int bestInvitation(vector<string> first, vector<string> second) {
        unordered_map<string, int> freq;
        for (int i = 0; i < first.size(); ++i) {
            ++freq[first[i]];
            ++freq[second[i]];
        }

        int result = 0;
        for (auto& p : freq)
            result = max(result, p.second);
        return result;
    }
};
