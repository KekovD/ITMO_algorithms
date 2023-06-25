#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

struct pair
{
    char letter;
    int quantity;

    pair (char letter, int quantity = 1)
    {
        this->letter = letter;
        this->quantity = quantity;
    }
};

void parser (std::string str, std::vector<pair>& vec, int &length)
{
    std::string tmpDigit;
    int vecIndex = 0;
    char tmpCh = 0;

    for (auto ch : str)
    {
        if (isalpha (ch) && tmpDigit.empty())
        {
            vec.emplace_back (ch);
        }
        else if (isalpha (ch))
        {
            vec[vecIndex].quantity = stoi (tmpDigit);
            length += vec[vecIndex].quantity;
            tmpDigit.clear();
            vecIndex++;

            vec.emplace_back (ch);
        }
        else
        {
            tmpDigit += ch;
        }
    }

    if (!tmpDigit.empty())
    {
        vec[vecIndex].quantity = stoi (tmpDigit);
        length += vec[vecIndex].quantity;
    }
}

bool compare (std::vector<pair> &first, std::vector<pair> &second, int lengthFirst, int lengthSecond, int difference)
{
    if (difference - abs(lengthFirst - lengthSecond) < 0)
    {
        return false;
    }

    int it1 = 0, it2 = 0;

    while (it1 < first.size() && it2 < second.size())
    {
        if (first[it1].letter == second[it2].letter)
        {
            if (first[it1].quantity == second[it2].quantity)
            {
                it1++;
                it2++;
            }
            else if (first[it1].quantity > second[it2].quantity)
            {
                first[it1].quantity -= second[it2].quantity;
                it2++;
            }
            else
            {
                second[it2].quantity -= first[it1].quantity;
                it1++;
            }
        }
        else
        {
            if (first[it1].quantity == second[it2].quantity)
            {
                difference -= first[it1].quantity;
                it1++;
                it2++;
            }
            else if (first[it1].quantity > second[it2].quantity)
            {
                difference -= second[it2].quantity;
                first[it1].quantity -= second[it2].quantity;
                it2++;
            }
            else
            {
                difference -= first[it1].quantity;
                second[it2].quantity -= first[it1].quantity;
                it1++;
            }
        }
    }

    if (difference < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main ()
{
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    int n, m, k;
    int sizeFirst = 0, sizeSecond = 0;
    std::string strFirst, strSecond;
    std::vector<pair> first, second;

    std::cin >> n >> m >> k;
    std::cin >> strFirst;
    std::cin >> strSecond;

    parser (strFirst, first, sizeFirst);
    parser (strSecond, second, sizeSecond);

    if (compare (first, second, sizeFirst, sizeSecond, k))
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}
