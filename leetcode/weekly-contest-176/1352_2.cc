#include <vector>


using namespace std;


class ProductOfNumbers {
  private:
    vector<int> acc;
  public:
    ProductOfNumbers() : acc(1, 1) {
    }

    void add(int num) {
        if (num) {
            int last = acc.back() * num;
            acc.emplace_back(last);
        } else {
            acc = vector<int>(1, 1);
        }
    }

    int getProduct(int k) {
        if (k >= acc.size())
            return 0;
        return acc.back() / acc[acc.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
