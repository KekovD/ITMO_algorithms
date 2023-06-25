using System;

class Program
{
    static void Main()
    {
        string[] nm = Console.ReadLine().Split();
        int n = int.Parse(nm[0]);
        int m = int.Parse(nm[1]);
        char[][] floorPlan = new char[n][];

        for (int i = 0; i < n; i++)
        {
            floorPlan[i] = Console.ReadLine().ToCharArray();
        }

        int roomCount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (floorPlan[i][j] == '.')
                {
                    DFS(floorPlan, i, j);
                    roomCount++;
                }
            }
        }

        Console.WriteLine(roomCount);
    }

    static void DFS(char[][] floorPlan, int i, int j)
    {
        floorPlan[i][j] = '#';
        int n = floorPlan.Length;
        int m = floorPlan[0].Length;

        if (i > 0 && floorPlan[i - 1][j] == '.')
        {
            DFS(floorPlan, i - 1, j);
        }

        if (j > 0 && floorPlan[i][j - 1] == '.')
        {
            DFS(floorPlan, i, j - 1);
        }

        if (i < n - 1 && floorPlan[i + 1][j] == '.')
        {
            DFS(floorPlan, i + 1, j);
        }

        if (j < m - 1 && floorPlan[i][j + 1] == '.')
        {
            DFS(floorPlan, i, j + 1);
        }
    }
}
