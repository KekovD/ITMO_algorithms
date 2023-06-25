using System;
using System.Collections.Generic;

class Program
{
    const int Maxn = 1000005;

    private static List<int>[] _adj = new List<int>[Maxn];
    private static int[] _color = new int[Maxn];
    private static int[] _parent = new int[Maxn];

    static bool Dfs(int u)
    {
        _color[u] = 1;
        foreach (int v in _adj[u])
        {
            if (_color[v] == 0)
            {
                _parent[v] = u;
                if (Dfs(v))
                {
                    return true;
                }
            }
            else if (_color[v] == 1 && _parent[u] != v)
            {
                return true;
            }
        }

        _color[u] = 2;
        return false;
    }

    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);

        for (int i = 1; i <= n; i++)
        {
            _adj[i] = new List<int>();
        }

        for (int i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            int u = int.Parse(input[0]);
            int v = int.Parse(input[1]);
            _adj[u].Add(v);
            _adj[v].Add(u);
        }

        bool hasCycle = false;
        for (int u = 1; u <= n; u++)
        {
            if (_color[u] == 0)
            {
                hasCycle |= Dfs(u);
            }
        }

        if (hasCycle)
        {
            for (int u = 1; u <= n; u++)
            {
                foreach (int v in _adj[u])
                {
                    if (v > u)
                    {
                        int w = v;
                        while (w != u)
                        {
                            w = _parent[w];
                        }

                        if (w != v)
                        {
                            Console.WriteLine("YES");
                            return;
                        }
                    }
                }
            }

            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}
