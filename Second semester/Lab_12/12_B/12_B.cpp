#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> parent;

long long find (long long x) {
    if (parent[x] != x) {
        parent[x] = find (parent[x]);
    }
    return parent[x];
}

void unite (long long x, long long y) {
    long long px = find (x);
    long long py = find (y);
    parent[py] = px;
}

int main () {
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    long long n, m;
    std::cin >> n >> m;
    parent.resize (n);

    for (long long i = 0; i < n; i++) {
        parent[i] = i;
    }

    std::vector <std::tuple<long long, long long, long long>> edges (m);

    for (long long i = 0; i < m; i++) {
        long long a, b, w;
        std::cin >> a >> b >> w;
        edges[i] = std::make_tuple (w, a - 1, b - 1);
    }

    sort (edges.begin (), edges.end ());
    long long ans = 0;
    
    for (long long i = 0; i < m; i++) {
        long long w, a, b;
        std::tie (w, a, b) = edges[i];

        if (find (a) != find (b)) {
            ans += w;
            unite (a, b);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
