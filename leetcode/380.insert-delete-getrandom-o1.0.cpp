#include <unorderd_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
  private:
    unordered_map<int, int> loc;
    vector<int> nums;
    mt19937 rng;

  public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        rng = mt19937(17);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = loc.find(val);
        if (it != loc.end())
            return false;

        nums.emplace_back(val);
        loc[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = loc.find(val);
        if (it == loc.end())
            return false;

        int t = it->second;
        if (t < nums.size()-1) {
            nums[t] = nums.back();
            loc[nums.back()] = t;
        }
        loc.erase(it);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> dis(0, nums.size()-1);
        return nums[dis(rng)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
