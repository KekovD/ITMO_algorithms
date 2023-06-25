#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const long long Inf = std::numeric_limits<long long>::max ();

int main () {
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    int n, s;
    std::cin >> n >> s;
    --s;
    std::vector<long long> a (n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> dist (n, Inf);
    dist[s] = 0;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>>> q;
    q.emplace (dist[s], s);

    while (!q.empty ()) {
        long long u = q.top ().second;
        long long d = q.top ().first;
        q.pop ();

        if (d != dist[u]) {
            continue;
        }

        for (int v = 0; v < n; ++v) {
            if (u != v) {
                long long w = a[u] * (v + 1) + a[v] * (u + 1);
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.emplace (dist[v], v);
                }
            }
        }
    }

    for (auto i: dist) {
        std::cout << i << " ";
    }

    return 0;
}
