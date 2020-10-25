#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <cassert>


using namespace std;


struct Elem {
    int votes = 0;
    int t = 0;
    int person = 0;

    Elem(int nv, int nt, int np) : votes(nv), t(nt), person(np) {}

    bool operator<(const Elem& other) const {
        return make_pair(votes, t) < make_pair(other.votes, other.t);
    }
};


class TopVotedCandidate {
  private:
    map<int, int> top_candi;

  public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();

        priority_queue<Elem> max_pq;
        vector<int> votes(n);

        for (int i = 0; i < n; ++i) {
            auto& t = times[i];
            auto& p = persons[i];
            ++votes[p];

            max_pq.emplace(votes[p], t, p);
            auto e = max_pq.top();

            top_candi[t] = e.person;
        }
    }

    int q(int t) {
        auto it = top_candi.upper_bound(t);
        assert(it != top_candi.begin());
        --it;
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
