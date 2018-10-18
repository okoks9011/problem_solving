#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(200001);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ++v[t];
  }

  auto min_it = find_if(v.begin(), v.end(), [](int a){ return a != 0; });
  ++min_it;

  for (int i = 200000; i > 0; --i) {
    v[i-1] += v[i];
  }

  int slice = 0, acc = 0;
  for (auto it = min_it; it != v.end(); ++it) {
    if (acc + *it > k) {
      ++slice;
      acc = 0;
    }
    acc += *it;
  }
  if (acc != 0)
    ++slice;
  cout << slice;
}
