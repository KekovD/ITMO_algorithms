using System;
using System.Collections.Generic;
using System.Linq;

class FordFulkerson
{
    private static void Main()
    {
        var input = Console.ReadLine().Split();
        var n = int.Parse(input[0]);
        var m = int.Parse(input[1]);

        var graph = new int[n, n];

        for (var i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            var u = int.Parse(input[0]) - 1;
            var v = int.Parse(input[1]) - 1;
            var c = int.Parse(input[2]);

            graph[u, v] += c;
        }

        var maxFlow = FordFulkersonAlgorithm(graph, 0, n - 1);
        Console.WriteLine(maxFlow);
    }

    private static int FordFulkersonAlgorithm(int[,] graph, int source, int sink)
    {
        var n = graph.GetLength(0);
        var residualGraph = new int[n, n];

        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                residualGraph[i, j] = graph[i, j];
            }
        }

        var parent = new int[n];
        var maxFlow = 0;

        while (Bfs(residualGraph, source, sink, parent))
        {
            var pathFlow = int.MaxValue;

            for (var v = sink; v != source; v = parent[v])
            {
                var u = parent[v];
                pathFlow = Math.Min(pathFlow, residualGraph[u, v]);
            }

            for (var v = sink; v != source; v = parent[v])
            {
                var u = parent[v];
                residualGraph[u, v] -= pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

    private static bool Bfs(int[,] residualGraph, int source, int sink, int[] parent)
    {
        var n = residualGraph.GetLength(0);
        var visited = new bool[n];

        for (var i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        var queue = new Queue<int>();
        queue.Enqueue(source);
        visited[source] = true;
        parent[source] = -1;

        while (queue.Any())
        {
            var u = queue.Dequeue();

            for (var v = 0; v < n; v++)
            {
                if (!visited[v] && residualGraph[u, v] > 0)
                {
                    queue.Enqueue(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        return visited[sink];
    }
}
