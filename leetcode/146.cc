#include <list>
#include <unordered_map>
#include <cassert>


using namespace std;


class LRUCache {
  private:
    int capacity = 0;
    list<int> recent;
    unordered_map<int, int> store;
    unordered_map<int, list<int>::iterator> loc;

  public:
    LRUCache(int c) : capacity(c) {}

    int get(int key) {
        auto it = store.find(key);
        if (it != store.end()) {
            refresh(key);
            return it->second;
        }

        return -1;
    }

    void put(int key, int value) {
        auto it = store.find(key);
        if (it != store.end()) {
            refresh(key);
            it->second = value;
            return;
        }

        if (store.size() >= capacity)
            evict();
        store[key] = value;
        recent.emplace_front(key);
        loc[key] = recent.begin();
    }

    void refresh(int key) {
        auto it = loc.find(key);
        if (it == loc.end())
            return;

        recent.erase(it->second);
        recent.emplace_front(key);
        it->second = recent.begin();
    }

    void evict() {
        assert(store.size() > 0);

        int key = recent.back();
        recent.pop_back();
        loc.erase(key);
        store.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
