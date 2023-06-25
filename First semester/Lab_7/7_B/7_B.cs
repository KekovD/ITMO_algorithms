using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab_7.A
{
    internal class Program
    {
        static int Knapsack(int capacity, ref List<int> weight, int n)
        {
            int[,] backpack = new int[n + 1, capacity + 1];

            for(int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= capacity; j++)
                {
                    if (i == 0 | j == 0)
                    {
                        backpack[i, j] = 0;
                    }
                    else if (weight[i - 1] <= j)
                    {
                        backpack[i, j] = Math.Max(weight[i - 1] + backpack[i - 1, j - weight[i - 1]],  backpack[i - 1, j]);
                    }
                    else
                    {
                        backpack[i, j] = backpack[i - 1, j];
                    }
                }
            }

            return backpack[n, capacity];
        }
        
        public static void Main()
        {
            var temp = new List<int>();
            var gold = new List<int>();

            temp.AddRange(Console.ReadLine().Split(' ').Select(int.Parse).ToList());
            
            var capacity = temp[0];
            var n = temp[1];
            
            temp.Clear();
            
            gold.AddRange(Console.ReadLine().Split(' ').Select(int.Parse).ToList());
            
            Console.WriteLine(Knapsack(capacity, ref gold, n));
        }
    }
}
