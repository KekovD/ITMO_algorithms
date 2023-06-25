using System;
using System.Collections.Generic;

class Program
{
    private static void Main(string[] args)
    {
        var input = Console.ReadLine().Split();
        var n = int.Parse(input[0]);
        var m = int.Parse(input[1]);
        
        var adjacencyList = new List<int>[n + 1];
        for (var i = 1; i <= n; i++)
        {
            adjacencyList[i] = new List<int>();
        }

        for (var i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            var u = int.Parse(input[0]);
            var v = int.Parse(input[1]);
            adjacencyList[u].Add(v);
        }

        var newNames = new int[n + 1];

        var newName = n;
        var visited = new bool[n + 1];
        for (var i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                DFS(i, adjacencyList, visited, newNames, ref newName);
            }
        }

        for (var i = 1; i <= n; i++)
        {
            Console.Write(newNames[i] + " ");
        }
    }

    static void DFS(int u, List<int>[] adjacencyList, bool[] visited, int[] newNames, ref int newName)
    {
        visited[u] = true;
        foreach (var v in adjacencyList[u])
        {
            if (!visited[v])
            {
                DFS(v, adjacencyList, visited, newNames, ref newName);
            }
        }
        newNames[u] = newName--;
    }
}
