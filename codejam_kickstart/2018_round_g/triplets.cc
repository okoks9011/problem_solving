#include <iostream>
#include <vector>

using namespace std;

int triplets(int n, const vector<long long>& A) {
  int result = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = a+1; b < n; ++b) {
      for (int c = b+1; c < n; ++c) {
        if ((A[a] * A[b] == A[c]) ||
            (A[b] * A[c] == A[a]) ||
            (A[c] * A[a] == A[b]))
            ++result;
      }
    }
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<long long> A(n);
    for (int j = 0; j < n; ++j)
      cin >> A[j];

    cout << "Case #" << i+1 << ": " << triplets(n, A) << endl;
  }
}
