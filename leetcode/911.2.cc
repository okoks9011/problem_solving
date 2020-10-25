#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;


class TopVotedCandidate {
  private:
    vector<int> lead;
    vector<int> ts;

  public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        ts = vector<int>(times);
        lead = vector<int>(times.size());
        int n = persons.size();
        vector<int> votes(n);

        int max_p = -1;
        for (int i = 0; i < n; ++i) {
            auto p = persons[i];
            ++votes[p];
            if (max_p == -1 || votes[max_p] <= votes[p])
                max_p = p;
            lead[i] = max_p;
        }
    }

    int q(int t) {
        auto it = upper_bound(ts.begin(), ts.end(), t);
        assert(it != ts.begin());
        --it;
        return lead[it-ts.begin()];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
