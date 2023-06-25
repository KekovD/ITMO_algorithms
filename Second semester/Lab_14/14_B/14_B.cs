using System;

class Program
{
    static void Main(string[] args)
    {
        var spell = Console.ReadLine();
        var result = CalculateAccentPositions(spell);
        Console.WriteLine(string.Join(" ", result));
    }

    static int[] CalculateAccentPositions(string spell)
    {
        var accentPositions = new int[spell.Length];

        for (var i = 1; i < spell.Length; i++)
        {
            var n = accentPositions[i - 1];
            while (n > 0 && spell[i] != spell[n])
            {
                n = accentPositions[n - 1];
            }
            accentPositions[i] = (spell[i] == spell[n]) ? n + 1 : 0;
        }

        return accentPositions;
    }
}
