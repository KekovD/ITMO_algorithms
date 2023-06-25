using System;
using System.Linq;

public class Program
{
    private static int[] _parent;

    static int Find(int x)
    {
        if (_parent[x] != x)
            _parent[x] = Find(_parent[x]);
        return _parent[x];
    }

    static void Union(int x, int y)
    {
        var px = Find(x);
        var py = Find(y);
        _parent[py] = px;
    }

    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var n = nm[0];
        var m = nm[1];
        _parent = Enumerable.Range(0, n).ToArray();
        
        var edges = new (int a, int b, int w)[m];
        
        for (var i = 0; i < m; i++)
        {
            var abc = Console.ReadLine().Split().Select(int.Parse).ToArray();
            edges[i] = (abc[0] - 1, abc[1] - 1, abc[2]);
        }

        Array.Sort(edges, (a, b) => a.w - b.w);
        
        var ans = 0;
        foreach (var e in edges)
        {
            if (Find(e.a) != Find(e.b))
            {
                ans += e.w;
                Union(e.a, e.b);
            }
        }

        Console.WriteLine(ans);
    }
}
