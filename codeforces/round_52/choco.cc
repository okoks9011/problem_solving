#include <iostream>
using namespace std;

long long max_choco(int s, int a, int b, int c) {
  long long buy = s / c;
  buy += (buy / a) * b;
  return buy;
}

int main() {
  int t, s, a, b, c;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> s >> a >> b >> c;
    cout << max_choco(s, a, b, c) << endl;
  }
}
