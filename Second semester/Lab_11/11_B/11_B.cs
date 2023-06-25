using System;

public class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split();
        var n = int.Parse(input[0]);
        var m = int.Parse(input[1]);

        var dist = new int[n, n];
        const int inf = 1000000000;
        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                dist[i, j] = inf;
            }

            dist[i, i] = 0;
        }

        for (var i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            var u = int.Parse(input[0]) - 1;
            var v = int.Parse(input[1]) - 1;
            var w = int.Parse(input[2]);
            dist[u, v] = w;
            dist[v, u] = w;
        }

        for (var k = 0; k < n; k++)
        {
            for (var i = 0; i < n; i++)
            {
                for (var j = 0; j < n; j++)
                {
                    dist[i, j] = Math.Min(dist[i, j], dist[i, k] + dist[k, j]);
                }
            }
        }

        var maxDist = 0;
        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                if (dist[i, j] != inf && dist[i, j] > maxDist)
                {
                    maxDist = dist[i, j];
                }
            }
        }

        if (maxDist == inf)
        {
            Console.WriteLine(0);
        }
        else
        {
            Console.WriteLine(maxDist);
        }
    }
}
