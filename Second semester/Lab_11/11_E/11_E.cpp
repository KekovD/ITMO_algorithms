#include <iostream>
#include <vector>
#include <queue>

int main () {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

    std::vector<std::vector<std::pair<int, int>>> adj (n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        std::cin >> a >> b >> w;
        adj[a].emplace_back (b, w);
    }

    std::vector<int> dist (n + 1, INT32_MAX);
    dist[s] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.emplace (0, s);

    while (!q.empty ()) {
        int v = q.top ().second;
        int d = q.top ().first;
        q.pop ();

        if (d > dist[v]) continue;

        for (auto edge: adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                q.push ({dist[u], u});
            }
        }
    }

    if (dist[t] == INT32_MAX) std::cout << -1 << '\n';
    else std::cout << dist[t] << '\n';

    return 0;
}
