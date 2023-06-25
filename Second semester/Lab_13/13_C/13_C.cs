using System;

class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var p = 10005;
        int sum1 = 0, sum2 = 0;
        for (var i = 0; i < n; i++)
        {
            var x = int.Parse(Console.ReadLine());
            sum1 = (sum1 + x) % p;
        }
        for (var i = 0; i < n; i++)
        {
            var x = int.Parse(Console.ReadLine());
            sum2 = (sum2 + x) % p; 
        }
        if (sum1 == sum2)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}
