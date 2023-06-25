using System;
using System.Collections.Generic;

class Program
{
    private const int MaxN = 100000;
    private static int[] _answer = new int[MaxN], _trap = new int[MaxN];
    private static bool[] _visited = new bool[MaxN];
    private static List<int>[] _adjacencyList = new List<int>[MaxN];

    private static void Dfs(int vertex, int component)
    {
        _visited[vertex] = true;
        _answer[vertex] = component;
        foreach (var adjacentVertex in _adjacencyList[vertex])
        {
            if (!_visited[adjacentVertex])
            {
                Dfs(adjacentVertex, component);
            }
        }
    }

    private static void Main()
    {
        var tokens = Console.ReadLine().Split();
        var n = int.Parse(tokens[0]);
        var m = int.Parse(tokens[1]);
        var count = 0;

        for (var i = 1; i <= n; i++)
        {
            _adjacencyList[i] = new List<int>();
        }

        for (var i = 0; i < m; i++)
        {
            tokens = Console.ReadLine().Split();
            var u = int.Parse(tokens[0]);
            var v = int.Parse(tokens[1]);
            _adjacencyList[u].Add(v);
            _adjacencyList[v].Add(u);
        }

        tokens = Console.ReadLine().Split();
        for (var i = 1; i <= n; i++)
        {
            _trap[i] = tokens[i - 1][0] - '0';
        }

        for (var i = 1; i <= n; i++)
        {
            if (!_visited[i])
            {
                count++;
                Dfs(i, count);
            }
        }

        Console.WriteLine(count);
        for (var i = 1; i <= n; i++)
        {
            Console.Write(_answer[i] + " ");
        }

        Console.WriteLine();

        var flag = false;
        for (var i = 1; i <= count; i++)
        {
            var ok = true;
            for (var j = 1; j <= n; j++)
            {
                if (_answer[j] == i && _trap[j] == 1)
                {
                    ok = false;
                    break;
                }
            }

            if (!ok)
            {
                flag = true;
                Console.Write("1 ");
            }
            else
            {
                Console.Write("0 ");
            }
        }

        if (flag)
        {
            Console.WriteLine();
        }
    }
}
