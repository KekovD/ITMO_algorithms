using System;
using System.Collections.Generic;

class Path
{
    private static List<int>[] _adjList;
    private static bool[] _isVisited;

    static bool DepthFirstSearch(int numVertices, int current, int count)
    {
        _isVisited[current] = true;
        count++;
        
        if (count == numVertices)
        {
            return true;
        } 
        
        foreach (var vertexU in _adjList[current])
        {
            if (!_isVisited[vertexU] && DepthFirstSearch(numVertices, vertexU, count))
            {
                return true;
            }
        }
        
        return false;
    }

    static int BreadthFirstSearch(int numVertices, int start)
    {
        _isVisited = new bool[numVertices];
        var dist = new int[numVertices];
        dist[start] = 0;
        _isVisited[start] = true;
        var q = new Queue<int>();
        q.Enqueue(start);
        var farthest = start;
        
        while (q.Count > 0)
        {
            int vertexU = q.Dequeue();
            foreach (var vertexV in _adjList[vertexU])
            {
                if (!_isVisited[vertexV])
                {
                    _isVisited[vertexV] = true;
                    dist[vertexV] = dist[vertexU] + 1;
                    if (dist[vertexV] > dist[farthest])
                    {
                        farthest = vertexV;
                    }
                    q.Enqueue(vertexV);
                }
            }
        }
        
        return farthest;
    }

    static bool HamiltonPath(int numVertices)
    {
        var farthest = BreadthFirstSearch(numVertices, 0);
        _isVisited = new bool[numVertices];
        
        if (DepthFirstSearch(numVertices, farthest, 0))
        {
            return true;
        }
        
        return false;
    }

    static void Main()
    {
        var input = Console.ReadLine().Split();
        var numVertices = int.Parse(input[0]);
        var numEdges = int.Parse(input[1]);

        _adjList = new List<int>[numVertices];
        for (var i = 0; i < numVertices; i++)
        {
            _adjList[i] = new List<int>();
        }
        
        for (var i = 0; i < numEdges; i++)
        {
            input = Console.ReadLine().Split();
            var vertexU = int.Parse(input[0]) - 1;
            var vertexV = int.Parse(input[1]) - 1;
            _adjList[vertexU].Add(vertexV);
            _adjList[vertexV].Add(vertexU);
        }
        
        Console.WriteLine(HamiltonPath(numVertices) ? "YES" : "NO");
    }
}
