#include <vector>


using namespace std;


class ProductOfNumbers {
  private:
    vector<int> buf;
  public:
    ProductOfNumbers() {
    }

    void add(int num) {
        buf.emplace_back(num);
    }

    int getProduct(int k) {
        int result = 1;
        for (int i = buf.size()-1; k > 0; --i, --k) {
            result *= buf[i];
            if (!result)
                break;
        }
        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
