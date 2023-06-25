using System;
using System.Collections.Generic;

class Program
{
    static long CountValidPairs(List<long> S, long N)
    {
        const int MAXN = 1000000;
        var cnt = new long[MAXN * 2 + 1];
        long answer = 0;

        for (long i = 0; i < N; i++)
        {
            var sum = i - S[(int)i] + MAXN;
            if (sum >= 0 && sum < cnt.Length)
            {
                answer += cnt[sum];
                cnt[sum]++;
            }
        }

        return answer;
    }

    static void Main()
    {
        var N = long.Parse(Console.ReadLine());
        var S = new List<long>(Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse));

        var result = CountValidPairs(S, N);
        Console.WriteLine(result);
    }
}
