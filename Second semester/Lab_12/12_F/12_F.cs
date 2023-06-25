using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    private static void Main()
    {
        var ans1 = 0;
        var ans2 = int.MaxValue;

        var edges = new List<Tuple<Tuple<int, int>, int>>();

        var input = Console.ReadLine().Split();
        var m = int.Parse(input[1]);

        for (var i = 0; i < m; i++)
        {
            input = Console.ReadLine().Split();
            var a = int.Parse(input[0]) - 1;
            var b = int.Parse(input[1]) - 1;
            var c = int.Parse(input[2]);
            edges.Add(Tuple.Create(Tuple.Create(a, b), c));
        }

        var mst = Kruskal(edges);

        foreach (var edge in mst)
        {
            var mstWE = KruskalWE(edges, edge);
            var s = mstWE.Sum(e => e.Item2);
            if (s < ans2)
            {
                ans2 = s;
            }
        }

        foreach (var edge in mst)
        {
            ans1 += edge.Item2;
        }

        Console.WriteLine($"{ans1} {ans2}");
    }

    static List<Tuple<Tuple<int, int>, int>> Kruskal(List<Tuple<Tuple<int, int>, int>> edges)
    {
        var result = new List<Tuple<Tuple<int, int>, int>>();
        var uf = new UnionFind(edges.Count);
        edges.Sort((a, b) => a.Item2.CompareTo(b.Item2));

        foreach (var edge in edges)
        {
            if (uf.Find(edge.Item1.Item1) != uf.Find(edge.Item1.Item2))
            {
                result.Add(edge);
                uf.Union(edge.Item1.Item1, edge.Item1.Item2);
            }
        }

        return result;
    }

    static IEnumerable<Tuple<Tuple<int, int>, int>> KruskalWE(List<Tuple<Tuple<int, int>, int>> edges,
        Tuple<Tuple<int, int>, int> excludedEdge)
    {
        var ans = new List<Tuple<Tuple<int, int>, int>>();
        var uf = new UnionFind(edges.Count);
        edges.Sort((a, b) => a.Item2.CompareTo(b.Item2));

        foreach (var edge in edges)
        {
            if (edge.Equals(excludedEdge))
            {
                continue;
            }

            if (uf.Find(edge.Item1.Item1) != uf.Find(edge.Item1.Item2))
            {
                ans.Add(edge);
                uf.Union(edge.Item1.Item1, edge.Item1.Item2);
            }
        }

        return ans;
    }
}

public class UnionFind
{
    private List<long> _parent;
    private List<long> _rank;

    public UnionFind(long n)
    {
        _parent = new List<long>();
        _rank = new List<long>();

        for (long i = 0; i < n; i++)
        {
            _parent.Add(i);
            _rank.Add(0);
        }
    }

    public long Find(long x)
    {
        if (_parent[(int)x] == x)
        {
            return x;
        }

        _parent[(int)x] = Find(_parent[(int)x]);
        return _parent[(int)x];
    }

    public void Union(long x, long y)
    {
        var X = Find(x);
        var Y = Find(y);

        if (X == Y)
        {
            return;
        }

        if (_rank[(int)X] < _rank[(int)Y])
        {
            _parent[(int)X] = Y;
        }
        else if (_rank[(int)X] > _rank[(int)Y])
        {
            _parent[(int)Y] = X;
        }
        else
        {
            _parent[(int)X] = Y;
            _rank[(int)Y]++;
        }
    }
}
