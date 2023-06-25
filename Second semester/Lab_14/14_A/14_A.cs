using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var T = Console.ReadLine();
        var X = Console.ReadLine();

        var count = 0;
        var indices = new List<int>();

        for (var i = 0; i <= T.Length - X.Length; i++)
        {
            var match = true;
            for (var j = 0; j < X.Length; j++)
            {
                if (T[i + j] != X[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                count++;
                indices.Add(i);
            }
        }

        Console.WriteLine(count);
        Console.WriteLine(string.Join(" ", indices));
    }
}
