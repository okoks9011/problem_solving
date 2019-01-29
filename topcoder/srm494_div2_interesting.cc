#include <vector>
#include <string>

using namespace std;

class InterestingParty {
  public:
    int bestInvitation(vector<string> first, vector<string> second) {
        int result = 0;
        for (int i = 0; i < first.size(); ++i) {
            for (int j = 0; j < first.size(); ++j) {
                if (i != j && (first[i] == first[j] ||
                               first[i] == second[j] ||
                               second[i] == first[j] ||
                               second[i] == second[j])) {
                    ++result;
                    break;
                }
            }
        }

        if (result == 0)
            ++result;
        return result;
    }
};
