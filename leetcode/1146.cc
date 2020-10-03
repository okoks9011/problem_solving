#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
#include <unordered_map>


using namespace std;


class SnapshotArray {
  private:
    unordered_map<int, int> buf;
    vector<vector<pair<int, int>>> store;
    int snap_cnt = 0;

  public:
    SnapshotArray(int length) : store(length) {
        for (int i = 0; i < length; ++i)
            buf[i] = 0;
    }

    void set(int index, int val) {
        buf[index] = val;
    }

    int snap() {
        for (auto& p : buf) {
            auto& cur_store = store[p.first];
            int v = p.second;
            if (cur_store.empty() || cur_store.back().second != v)
                cur_store.emplace_back(snap_cnt, v);
        }
        buf.clear();
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
