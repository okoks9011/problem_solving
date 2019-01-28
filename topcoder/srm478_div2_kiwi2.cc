#include <vector>
#include <algorithm>

using namespace std;

class KiwiJuiceEasy {
  public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
        for (int i = 0; i < fromId.size(); ++i) {
            int f = fromId[i];
            int t = toId[i];

            int sum = bottles[t] + bottles[f];
            bottles[t] = min(sum, capacities[t]);
            bottles[f] = sum - bottles[t];
        }
        return bottles;
    }
};
