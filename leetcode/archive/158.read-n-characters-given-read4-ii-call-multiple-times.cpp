#include <deque>
#include <algorithm>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    deque<char> inter;

    int read(char *buf, int n) {
        int result = 0;
        while (n) {
            if (inter.size() < min(4, n)) {
                char tmp[4];
                int read_cnt = read4(tmp);
                for (int i = 0; i < read_cnt; ++i)
                    inter.emplace_back(tmp[i]);
            }

            int write_cnt = min(static_cast<int>(inter.size()), n);
            if (write_cnt == 0)
                break;
            for (int i = 0; i < write_cnt; ++i) {
                buf[result+i] = inter.front();
                inter.pop_front();
            }
            result += write_cnt;
            n -= write_cnt;
        }
        return result;
    }
};
