#include <iostream>
#include <vector>

void find (std::vector <int> &tree, int n, int min, int max, int &i, std::vector <int> &result)
{
    bool check = (i == n || tree[i] < min || tree[i] > max);
    int val;

    switch (check)
    {
        case true:
            return;
        case false:
            val = tree[i++];
            find(tree, n, min, val, i, result);
            find(tree, n, val, max, i, result);
    }

    result.push_back (val);
}


int main ()
{
    int n;
    int index = 0;
    std::vector <int> input, output;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    input.resize (n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }

    find(input, n, INT_MIN, INT_MAX, index, output);

    for (int i = 0; i < n; i++)
    {
        std::cout << output[i] << ' ';
    }

    return 0;
}
