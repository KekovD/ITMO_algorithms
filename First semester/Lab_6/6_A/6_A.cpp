#include <iostream>
#include <vector>

#define left_r array[j][1]
#define right_r array[j][2]

void height (int j, std::vector<std::vector<int>> &array)
{
    int left = 0;
    int right = 0;

    if (left_r)
    {
        height (left_r - 1, array);
        left = array[left_r - 1][3];
    }

    if (right_r)
    {
        height (right_r - 1, array);
        right = array[right_r - 1][3];
    }

    if (left > right)
    {
        array[j][3] = 1 + left;
    }
    else
    {
        array[j][3] = 1 + right;
    }
}

void balance (int left, int right, std::vector<std::vector<int>> &array, std::ostream &f)
{
    if (!left && !right)
    {
        f << 0 << '\n';
        return;
    }
    else if (right && !left)
    {
        f << array[right - 1][3] << '\n';
        return;
    }
    else if (left && !right)
    {
        f << 0 - array[left - 1][3] << '\n';
        return;
    }
    else if (left && right)
    {
        f << array[right - 1][3] - array[left - 1][3] << '\n';
        return;
    }
}

int main ()
{
    int n;

    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    std::cin >> n;
    std::vector<std::vector<int>> array (n, std::vector<int> (4));

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i][0] >> array[i][1] >> array[i][2];
    }

    height (0, array);

    for (int j = 0; j < n; j++)
    {
        balance (left_r, right_r, array, std::cout);
    }

    return 0;
}
