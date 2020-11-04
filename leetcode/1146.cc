#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>


using namespace std;


class SnapshotArray {
  private:
    vector<vector<pair<int, int>>> store;
    int snap_cnt = 0;

  public:
    SnapshotArray(int length) : store(length, {make_pair(0, 0)}) {
    }

    void set(int index, int val) {
        auto& cur_store = store[index];
        assert(!cur_store.empty());
        if (cur_store.back().first == snap_cnt) {
            cur_store.back().second = val;
        } else {
            if (cur_store.back().second != val)
                cur_store.emplace_back(snap_cnt, val);
        }
    }

    int snap() {
        return snap_cnt++;
    }

    int get(int index, int snap_id) {
        assert(snap_id < snap_cnt);
        auto& cur_store = store[index];
        auto it = upper_bound(cur_store.begin(), cur_store.end(), make_pair(snap_id, 1000000001));
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
