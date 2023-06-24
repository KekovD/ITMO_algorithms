#include <iostream>
#include <vector>

int search;
std::vector<int> array;

int Binary_Search_Left(int left, int right)
{
    if (right > left + 1)
    {
        int mid = (left + right) / 2;

        if (array[mid] < search)
        {
            return Binary_Search_Left(mid, right);
        }
        else
        {
            return Binary_Search_Left(left, mid);
        }
    }

    if (right < array.size() && array[right] == search)
    {
        return right;
    }
    else
    {
        return -1;
    }
}

int Binary_Search_Right(int left, int right)
{
    if (right > left + 1)
    {
        int mid = (left + right) / 2;

        if (array[mid] <= search)
        {
            return Binary_Search_Right(mid, right);
        }
        else
        {
            return Binary_Search_Right(left, mid);
        }
    }

    if (left < array.size() && array[left] == search)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, number, m, output_left, output_right;

    std::cin >> n;
    
    array.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    std::cin >> m;

    for (int i = 0; i < m; i++)
    {
        std::cin >> search;
        output_left = Binary_Search_Left(-1, array.size());
        output_right = Binary_Search_Right(-1, array.size());

        if (output_left > -1)
        {
            std::cout << output_left + 1 << " " << output_right + 1 << "\n";
        }
        else
        {
            std::cout << output_left << " " << output_right << "\n";
        }
    }

    return 0;
}
