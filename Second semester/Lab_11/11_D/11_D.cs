using System;
using System.Collections.Generic;

class MainClass
{
    public static void Main(string[] args)
    {
        var input = Console.ReadLine().Split();
        var n = int.Parse(input[0]);
        var m = int.Parse(input[1]);
        var q = int.Parse(input[2]);
        var start = int.Parse(input[3]);

        var adj = new List<Tuple<int, int>>[n];
        
        for (var i = 0; i < n; i++)
        {
            adj[i] = new List<Tuple<int, int>>();
        }

        for (var i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            var u = int.Parse(input[0]) - 1;
            var v = int.Parse(input[1]) - 1;
            var w = int.Parse(input[2]);
            adj[u].Add(new Tuple<int, int>(v, w));
            adj[v].Add(new Tuple<int, int>(u, w));
        }

        var dist = new int[n];
        
        for (var i = 0; i < n; i++)
        {
            dist[i] = -1;
        }

        var queue = new Queue<int>();
        queue.Enqueue(start - 1);
        dist[start - 1] = 0;
        
        while (queue.Count > 0)
        {
            var u = queue.Dequeue();
            foreach (var edge in adj[u])
            {
                var v = edge.Item1;
                var w = edge.Item2;
                if (dist[v] == -1 || dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    queue.Enqueue(v);
                }
            }
        }

        for (var i = 0; i < q; i++)
        {
            var query = int.Parse(Console.ReadLine()) - 1;
            Console.WriteLine(dist[query]);
        }
    }
}
