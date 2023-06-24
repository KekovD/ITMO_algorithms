#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> mass;

void countingSort(int n, int rank)
{
    char temp;
    std::vector<int> count;
    std::vector<std::string> sort_temp;

    count.resize(26);
    sort_temp.resize(n);

    for (int i = 0; i < n; i++)
    {
        temp = mass[i][rank];
        count[temp - 97] += 1;
    }

    for (int i = 1; i < 26; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        temp = mass[i][rank];
        sort_temp[count[temp - 97] - 1] = mass[i];
        count[temp - 97] -= 1;
    }

    for (int i = 0; i < n; i++)
    {
        mass[i] = sort_temp[i];
    }

    sort_temp.clear();
    count.clear();
}

int main ()
{
    int n, m, k;

    std::cin >> n >> m >> k;
    mass.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> mass[i];
    }

    for (int i = 0; i < k; i++)
    {
        countingSort(n, m - (i + 1));
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << mass[i] << "\n";
    }

    return 0;
}
