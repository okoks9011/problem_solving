#include <iostream>
using namespace std;

long long min_vertices(long long m) {
  long long v = 0;
  while (v * (v - 1) / 2 < m)
    ++v;
  return v;
}

long long max_vertices(long long m) {
  return m * 2;
}

int main() {
  long long n, m;
  cin >> n >> m;
  cout << max(static_cast<long long>(0), n - max_vertices(m)) << " ";
  cout << n - min_vertices(m) << endl;
}
