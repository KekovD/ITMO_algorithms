using System;
using System.Collections.Generic;

class Program {
    private static List<int>[] _graph;
    private static bool[] _visited;
    private static List<bool> _answer;

    static void Main() {
        _answer = new List<bool>();
        var input = Console.ReadLine().Split();
        var  n = int.Parse(input[0]);
        var m = int.Parse(input[1]);
        var q = int.Parse(input[2]);
        
        _graph = new List<int>[n + 1];
        for (var i = 1; i <= n; i++) {
            _graph[i] = new List<int>();
        }

        for (var i = 0; i < m; i++) {
            var edge = Console.ReadLine().Split();
            var a = int.Parse(edge[0]);
            var b = int.Parse(edge[1]);
            _graph[a].Add(b);
            _graph[b].Add(a);
        }

        _visited = new bool[n + 1];
        for (var i = 0; i < q; i++) {
            var query = Console.ReadLine().Split();
            var type = query[0][0];
            var a = int.Parse(query[1]);
            var b = int.Parse(query[2]);

            if (type == '?') {
                _answer.Add(IsReachable(a, b));
            } else {
                _graph[a].Remove(b);
                _graph[b].Remove(a);
            }
        }

        foreach (var i in _answer)
        {
            Console.WriteLine(i ? "YES" : "NO");
        }
    }

    static bool IsReachable(int a, int b) {
        for (var i = 0; i < _visited.Length; i++)
        {
            _visited[i] = false;
        }
        return DFS(a, b);
    }

    static bool DFS(int current, int target) {
        _visited[current] = true;
        if (current == target) {
            return true;
        }
        foreach (var neighbor in _graph[current]) {
            if (!_visited[neighbor]) {
                if (DFS(neighbor, target)) {
                    return true;
                }
            }
        }
        return false;
    }
}
