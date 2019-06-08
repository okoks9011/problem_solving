#include <unordered_set>
#include <random>

using namespace std;

class RandomizedSet {
  private:
    unordered_set<int> inner;
    unordered_set<int>::iterator it;
    mt19937 rng;
    uniform_int_distribution<int> dis;

  public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        random_device rd;
        rng = mt19937(rd());
        dis = uniform_int_distribution<int>(0, 1);
        it = inner.begin();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto res = inner.emplace(val);
        it = inner.begin();
        return res.second;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto res = inner.erase(val);
        it = inner.begin();
        return res == 1;
    }

    /** Get a random element from the set. */
    int getRandom() {
        while (dis(rng)) {
            ++it;
            if (it == inner.end())
                it = inner.begin();
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
