#include <deque>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  public:
    deque<char> inter;
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        while (inter.size() < n) {
            char tmp[4];
            int read_cnt = read4(tmp);
            if (read_cnt == 0)
                break;
            for (int i = 0; i < read_cnt; ++i)
                inter.emplace_back(tmp[i]);
        }

        int write_cnt = 0;
        while (inter.size() && n > 0) {
            buf[write_cnt] = inter.front();
            inter.pop_front();
            ++write_cnt;
            --n;
        }
        return write_cnt;
    }
};
