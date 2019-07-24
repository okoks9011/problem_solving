#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int min_j = 1;
    int max_j = m;
    while (min_j < max_j) {
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", i, min_j);
            printf("%d %d\n", n+1-i, max_j);
        }
        ++min_j;
        --max_j;
    }
    if (min_j == max_j) {
        int min_i = 1;
        int max_i = n;
        while (min_i < max_i) {
            printf("%d %d\n", min_i, min_j);
            printf("%d %d\n", max_i, min_j);
            ++min_i;
            --max_i;
        }
        if (min_i == max_i)
            printf("%d %d\n", min_i, min_j);
    }
}
