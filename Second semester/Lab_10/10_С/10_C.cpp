#include <iostream>
#include <vector>

bool dfs (int curr, int end, std::vector<std::vector<int>>& adj_list, std::vector<bool>& visited) {
    if (curr == end) {
        return true;
    }

    visited[curr] = true;

    for (auto neighbor: adj_list[curr]) {
        if (!visited[neighbor] && dfs (neighbor, end, adj_list, visited))
            return true;
    }

    return false;
}


int main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int num_vertices, num_edges, num_queries;
    std::cin >> num_vertices >> num_edges >> num_queries;

    std::vector<std::vector<int>> adj_list (num_vertices + 1);

    for (int i = 0; i < num_edges; i++) {
        int start_vertex, end_vertex;
        std::cin >> start_vertex >> end_vertex;
        adj_list[start_vertex].push_back (end_vertex);
    }

    auto reach = [&] (int start, int target, std::vector<std::vector<int>>& adj_list) -> bool {
        std::vector<bool> visited (adj_list.size (), false);
        return dfs (start, target, adj_list, visited);
    };

    for (int i = 0; i < num_queries; i++) {
        int start_vertex, end_vertex;
        std::cin >> start_vertex >> end_vertex;

        if (reach (start_vertex, end_vertex, adj_list) && reach (end_vertex, start_vertex, adj_list)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
