#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <iterator>


using namespace std;


class FirstUnique {
  private:
    unordered_set<int> appeared;
    unordered_map<int, list<int>::iterator> loc;
    list<int> unique;

  public:
    FirstUnique(vector<int> nums) {
        for (auto& n : nums)
            add(n);
    }

    int showFirstUnique() {
        if (unique.empty())
            return -1;
        return unique.front();
    }

    void add(int value) {
        auto it = appeared.find(value);
        if (it == appeared.end()) {
            appeared.emplace(value);
            unique.emplace_back(value);
            loc[value] = prev(unique.end());
        } else {
            auto loc_it = loc.find(value);
            if (loc_it != loc.end()) {
                unique.erase(loc_it->second);
                loc.erase(loc_it);
            }
        }
    }
};


int main() {
    FirstUnique f({2, 3, 5});
    cout << f.showFirstUnique() << endl;
    f.add(5);
    cout << f.showFirstUnique() << endl;
    f.add(2);
    cout << f.showFirstUnique() << endl;
    f.add(3);
    cout << f.showFirstUnique() << endl;
}
