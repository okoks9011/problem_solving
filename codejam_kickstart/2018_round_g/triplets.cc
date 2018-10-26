#include <iostream>
#include <vector>

using namespace std;

int triplets_complete_search(int n, const vector<long long>& A) {
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

long long triplets(int n, vector<long long>* A_ptr) {
    auto& A = *A_ptr;
    sort(A.begin(), A.end());
    long long zeros = 0;
    while (zeros < A.size() && A[zeros] == 0)
        ++zeros;

    vector<long long> cnt(200001);
    long long result = 0;
    for (int i = n-1; i >= zeros; --i) {
        for (int j = i-1; j >= zeros; --j) {
            if (A[i]*A[j] <= 200000 && cnt[A[i]*A[j]])
                result += cnt[A[i]*A[j]];
        }
        ++cnt[A[i]];
    }

    if (zeros >= 3)
        result += zeros * (zeros - 1) * (zeros - 2) / 6;
    if (zeros >= 2)
        result += (zeros * (zeros - 1) / 2) * (n - zeros);
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

        cout << "Case #" << i+1 << ": " << triplets(n, &A) << endl;
    }
}
