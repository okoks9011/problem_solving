// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  private:
    char tmp[4];
    int tmp_i = 0;
    int tmp_size = 0;

  public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cur = 0;
        while (cur < n) {
            if (tmp_i == 0)
                tmp_size = read4(tmp);
            if (tmp_size == 0)
                break;

            while (cur < n && tmp_i < tmp_size)
                buf[cur++] = tmp[tmp_i++];

            if (tmp_i >= tmp_size)
                tmp_i = 0;
        }
        return cur;
    }
};
