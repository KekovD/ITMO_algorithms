using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split();
        var N = int.Parse(input[0]);
        var M = int.Parse(input[1]);

        var songText = Console.ReadLine();

        var count = 0;
        for (var i = 0; i < M; i++)
        {
            var question = Console.ReadLine().Split();
            var start1 = int.Parse(question[0]) - 1;
            var start2 = int.Parse(question[1]) - 1;
            var length = int.Parse(question[2]);

            if (start1 + length <= N && start2 + length <= N)
            {
                var word1 = GetSubstring(songText, start1, length);
                var word2 = GetSubstring(songText, start2, length);

                if (word1 == word2)
                {
                    count++;
                }
            }
        }

        Console.WriteLine(count);
    }

    static string GetSubstring(string text, int start, int length)
    {
        var substring = new char[length];
        for (var i = 0; i < length; i++)
        {
            substring[i] = text[start + i];
        }

        return new string(substring);
    }
}
