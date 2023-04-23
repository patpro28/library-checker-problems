#include <iostream>
#include "../params.h"
#include "random.h"

using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = N_AND_Q_MAX;
    int q = N_AND_Q_MAX;
    printf("%d %d\n", n, q);
    for (int i = 0; i < n; i++) {
        printf("%d", gen.uniform<int>(0, A_AND_X_MAX));
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    vector<int> u(n - 1), v(n - 1);
    for (int i = 0; i < n - 1; i++) {
        u[i] = i;
        v[i] = i + 1;
    }
    //shuffle u, v
    {
        auto perm = gen.perm<int>(n);
        for (int i = 0; i < n - 1; i++) {
            u[i] = perm[u[i]];
            v[i] = perm[v[i]];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d %d\n", u[i], v[i]);
    }

    for (int i = 0; i < q; i++) {
        int t = gen.uniform(0, 1);
        printf("%d ", t);
        if (t == 0) {
            int p = gen.uniform(0, n - 1);
            int x = gen.uniform<int>(0, A_AND_X_MAX);
            printf("%d %d\n", p, x);
        } else {
            int u = gen.uniform(0, n - 1);
            int v = gen.uniform(0, n - 1);
            printf("%d %d\n", u, v);
        }
    }
    return 0;
}
