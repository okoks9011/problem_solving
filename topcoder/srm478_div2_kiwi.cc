#include <vector>

using namespace std;

class KiwiJuiceEasy {
  public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
        for (int i = 0; i < fromId.size(); ++i) {
            int from = fromId[i];
            int to = toId[i];
            bottles[to] += bottles[from];
            bottles[from] = 0;

            if (bottles[to] > capacities[to]) {
                bottles[from] = bottles[to] - capacities[to];
                bottles[to] = capacities[to];
            }
        }
        return bottles;
    }
};
