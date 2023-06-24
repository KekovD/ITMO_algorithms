#include <iostream>
#include <vector>

int main() {
    int n;
    bool check = true;
    std::vector<int> array;

    std::cin >> n;
    array.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        check &= !(2 * i + 1 < n && array[i] > array[2 * i + 1]) &&
                !(2 * i + 2 < n && array[i] > array[2 * i + 2]);
    }

    if (check)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
