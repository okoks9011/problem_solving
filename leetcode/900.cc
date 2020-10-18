#include <vector>


using namespace std;


class RLEIterator {
  private:
    vector<int> buf;
    int idx = 0;
    long long cnt = 0LL;

  public:
    RLEIterator(vector<int>& A) : buf(A) {
    }

    int next(int n) {
        if (idx >= buf.size())
            return -1;

        cnt += n;
        while (cnt > buf[idx]) {
            cnt -= buf[idx];
            idx += 2;
            if (idx >= buf.size())
                return -1;
        }
        return buf[idx+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
