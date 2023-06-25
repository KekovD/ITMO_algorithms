#include <iostream>
#include <cmath>
#include <limits>

const int Inf = std::numeric_limits<int>::max ();

int main () {
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    int dist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = Inf;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        std::cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = w;
    }

    for (int c = 0; c < n; c++) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (dist[a][c] < Inf && dist[c][b] < Inf) {
                    int newDist = dist[a][c] + dist[c][b];
                    if (newDist < dist[a][b]) {
                        int diff1 = abs (a - c);
                        int diff2 = abs (b - c);
                        if (diff1 <= k && diff2 <= k) {
                            dist[a][b] = newDist;
                        }
                    }
                }
            }
        }
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] < Inf) {
            std::cout << dist[a][b] << '\n';
        } else {
            std::cout << "-1" << '\n';
        }
    }

    return 0;
}
