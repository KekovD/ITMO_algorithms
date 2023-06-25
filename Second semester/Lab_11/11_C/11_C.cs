using System;
using System.Collections.Generic;

namespace Facecontol
{
    struct Edge
    {
        public int U, V, W;
    }

    class Program
    {
        static bool HasNegativeCycle(int n, List<Edge> edges, int k)
        {
            var dist = new int[n];
            for (var i = 0; i < n; i++)
            {
                dist[i] = 0;
            }

            bool relaxed;
            for (var i = 0; i < n; i++)
            {
                relaxed = false;
                foreach (var edge in edges)
                {
                    if (dist[edge.U] != int.MaxValue && dist[edge.U] + edge.W < dist[edge.V])
                    {
                        dist[edge.V] = dist[edge.U] + edge.W;
                        relaxed = true;
                    }
                }

                if (!relaxed)
                {
                    break;
                }
            }

            foreach (var edge in edges)
            {
                if (dist[edge.U] != int.MaxValue && dist[edge.U] + edge.W < dist[edge.V] &&
                    dist[edge.U] + edge.W - k <= dist[edge.V])
                {
                    return true;
                }
            }

            return false;
        }

        static void Main()
        {
            int n, k;
            var input = Console.ReadLine().Split();
            n = int.Parse(input[0]);
            k = int.Parse(input[1]);

            for (var i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split();
                var vertices = int.Parse(input[0]);
                var edgesCount = int.Parse(input[1]);

                var edges = new List<Edge>();
                for (var j = 0; j < edgesCount; j++)
                {
                    input = Console.ReadLine().Split();
                    var u = int.Parse(input[0]) - 1;
                    var v = int.Parse(input[1]) - 1;
                    var w = int.Parse(input[2]);
                    edges.Add(new Edge() { U = u, V = v, W = w });
                }

                Console.WriteLine(HasNegativeCycle(vertices, edges, k) ? "NO" : "YES");
            }
        }
    }
}
