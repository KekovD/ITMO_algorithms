using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var nAndM = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var graph = new int[nAndM[0] + 1, nAndM[0] + 1];
        
        for (int i = 0; i < nAndM[1]; ++i)
        {
            var uAndV = Console.ReadLine().Split().Select(int.Parse).ToArray();
            graph[uAndV[0], uAndV[1]] = graph[uAndV[1], uAndV[0]] = 1;
        }

        var startAndFinish = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var distances = new int[nAndM[0] + 1];

        for (var i = 0; i < distances.Length; i++)
        {
            distances[i] = int.MaxValue;
        }

        distances[startAndFinish[0]] = 0;
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(startAndFinish[0]);

        while (queue.Any())
        {
            var u = queue.Dequeue();
            for (var v = 1; v <= nAndM[0]; ++v)
            {
                if (graph[u, v] == 1 && distances[v] > distances[u] + 1)
                {
                    distances[v] = distances[u] + 1;
                    queue.Enqueue(v);
                }
            }
        }

        Console.WriteLine(distances[startAndFinish[1]] != int.MaxValue ? distances[startAndFinish[1]] : -1);
    }
}
