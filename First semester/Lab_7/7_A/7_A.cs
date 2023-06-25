using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab._7.A
{
    internal class Program
    {
        static void FindLIS(ref List<int> array, ref List<int> answer)
        {
            int max = 0, max_index = 0;
            int n = array.Count;

            var lenght = new List<int>(Enumerable.Repeat(1, n).ToList());
            var previous = new List<int>(Enumerable.Repeat(-1, n).ToList());

            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (array[j] < array[i] && lenght[j] + 1 > lenght[i])
                    {
                        lenght[i] = lenght[j] + 1;
                        previous[i] = j;
                    }
                }
                
                if (lenght[i] > max)
                {
                    max = lenght[i];
                    max_index = i;
                }
            }

            var index = max_index;
            
            while (index != -1)
            {
                answer.Add(array[index]);
                index = previous[index];
            }
        }

        public static void Main()
        {
            var k = int.Parse(Console.ReadLine());

            var array = new List<int>();
            var answer = new List<int>();

            array.AddRange(Console.ReadLine().Split(' ').Select(int.Parse).ToList());

            FindLIS(ref array, ref answer);
            
            Console.WriteLine(answer.Count);
            
            for (int i = answer.Count - 1; i >= 0; i--)
            {
                Console.Write(answer[i] + " ");
            }
        }
    }
}
