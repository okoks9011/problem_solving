#include <list>
#include <unordered_map>
#include <cassert>
#include <iterator>


using namespace std;


class LRUCache {
private:
    int c = 0;
    list<int> recent;
    unordered_map<int, int> store;
    unordered_map<int, list<int>::iterator> recent_loc;

public:
    LRUCache(int capacity) : c(capacity) {}

    void recent_refresh(int key) {
        auto it = recent_loc.find(key);
        assert(it != recent_loc.end());
        recent.erase(it->second);
        recent_loc.erase(it);
        recent_add(key);
    }

    void recent_add(int key) {
        recent.emplace_back(key);
        auto loc = recent.end();
        --loc;
        recent_loc[key] = loc;
    }

    int get(int key) {
        auto it = store.find(key);
        if (it == store.end())
            return -1;
        recent_refresh(key);
        return it->second;
    }

    void put(int key, int value) {
        auto it = store.find(key);
        if (it != store.end()) {
            recent_refresh(key);
            it->second = value;
            return;
        }
        store[key] = value;
        recent_add(key);

        if (store.size() > c) {
            int t = recent.front();
            store.erase(t);
            recent_loc.erase(t);
            recent.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
