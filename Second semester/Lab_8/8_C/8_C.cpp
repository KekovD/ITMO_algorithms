#include <iostream>
#include <vector>
#include <string>
#include <functional>

std::string Decoder (std::string str)
{
    std::function<int (std::string, int, int)> mistake = [&mistake] (std::string str, int size, int result)
    {
        if (str[size - 1] == '1')
            result ^= size;
        if (str[size - 1] > 0)
            return mistake (str, size - 1, result);
        return result;
    };

    std::string tmpStr;
    int index = 1;

    if (str.size () > 1)
    {
        if (int bit = mistake (str, str.length (), 0))
        {
            if (str[bit - 1] == '0') str[bit - 1] = '1';
            else str[bit - 1] = '0';
        }
    }

    for (int j = 0; j < str.size (); j++)
    {
        if (j == str.size () - 1)
        {
            tmpStr += str[j];
        }
        else if (j != index - 1)
        {
            tmpStr += str[j];
        }
        else
        {
            index *= 2;
        }
    }
    return tmpStr;
}

int main ()
{
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    std::vector<std::string> result;
    int k;

    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        std::string str;
        std::cin >> str;
        result.push_back (Decoder (str));
    }

    for (auto i: result)
    {
        std::cout << i << '\n';
    }

    return 0;
}
