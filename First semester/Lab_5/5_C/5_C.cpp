#include <iostream>
#include <vector>

int number;

void build_tree(std::vector <std::vector<int>> &heap, int i)
{
    if (heap[i][1] > 0)
    {
        if (!heap[heap[i][1] - 1][0] && !heap[heap[i][1] - 1][1])
        {
            heap[heap[i][1] - 1][2] = number--;
        }
        else
        {
            build_tree (heap, heap[i][1] - 1);
        }
    }

    heap[i][2] = number--;

    if (heap[i][0] > 0)
    {
        if (!heap[heap[i][0] - 1][0] && !heap[heap[i][0] - 1][1])
        {
            heap[heap[i][0] - 1][2] = number--;
        }
        else
        {
            build_tree (heap, heap[i][0] - 1);
        }
    }
}

int main ()
{
    int n;

    std::cin >> n;

    std::vector <std::vector <int>> heap (n, std::vector <int> (3));
    number = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> heap[i][j];
            heap[i][2] = 0;
        }
    }

    build_tree (heap, 0);

    for (int i = 0; i < n; i++)
    {
        std::cout << heap[i][2] << ' ';
    }

    return 0;
}
