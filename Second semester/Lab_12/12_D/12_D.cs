using System;
using System.Collections.Generic;

class Program
{
    private const int Maxn = 110;
    private static int _n, _m, _q;
    private static bool[,] _vis = new bool[Maxn, Maxn];
    private static List<int>[] _g = new List<int>[Maxn * Maxn];
    private static int[] _linker = new int[Maxn * Maxn];
    private static bool[] _used = new bool[Maxn * Maxn];

    static int Id(int x, int y)
    {
        return (x - 1) * _m + y;
    }

    private static bool Dfs(int u)
    {
        foreach (var v in _g[u])
        {
            if (!_used[v])
            {
                _used[v] = true;
                if (_linker[v] == -1 || Dfs(_linker[v]))
                {
                    _linker[v] = u;
                    return true;
                }
            }
        }

        return false;
    }

    private static int Hungary()
    {
        var ans = 0;
        for (var i = 0; i < _linker.Length; i++)
        {
            _linker[i] = -1;
        }

        for (var u = 1; u <= _n * _m; u++)
        {
            if (!_vis[(u - 1) / _m + 1, u % _m == 0 ? _m : u % _m])
            {
                for (var i = 0; i < _used.Length; i++)
                {
                    _used[i] = false;
                }

                if (Dfs(u)) ans++;
            }
        }

        return ans;
    }

    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split();
        _n = int.Parse(input[0]);
        _m = int.Parse(input[1]);
        input = Console.ReadLine().Split();
        _q = int.Parse(input[0]);

        for (var i = 1; i <= _q; i++)
        {
            input = Console.ReadLine().Split();
            var x = int.Parse(input[0]);
            var y = int.Parse(input[1]);
            _vis[x, y] = true;
        }

        for (var i = 0; i < _g.Length; i++)
        {
            _g[i] = new List<int>();
        }

        for (var i = 1; i <= _n; i++)
        {
            for (var j = 1; j <= _m; j++)
            {
                if (!_vis[i, j] && j + 1 <= _m && !_vis[i, j + 1])
                {
                    _g[Id(i, j)].Add(Id(i, j + 1));
                    _g[Id(i, j + 1)].Add(Id(i, j));
                }

                if (!_vis[i, j] && i + 1 <= _n && !_vis[i + 1, j])
                {
                    _g[Id(i, j)].Add(Id(i + 1, j));
                    _g[Id(i + 1, j)].Add(Id(i, j));
                }
            }
        }

        Console.WriteLine(Hungary());
    }
}
