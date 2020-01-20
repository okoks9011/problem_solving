class Solution {
  public:
    int countBits(int x) {
        int result = 0;
        while (x > 0) {
            result += x & 1;
            x = x >> 1;
        }
        return result;
    }

    int minFlips(int a, int b, int c) {
        int diff = (a | b) ^ c;
        int both = a & b;
        return countBits(diff) + countBits(both & diff);
    }
};
