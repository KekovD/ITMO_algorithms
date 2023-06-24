#include <iostream>
#include <vector>

bool check = true;

void check_correct (std::vector <std::vector<int>> &heap, int previous, int min, int max)
{
    if (heap[previous][0] <= min || heap[previous][0] >= max)
    {
        check = false;
        return;
    }

    if (heap[previous][1] > 0)
    {
        check_correct(heap, heap[previous][1] - 1, min, heap[previous][0]);
    }

    if (heap[previous][2] > 0)
    {
        check_correct(heap, heap[previous][2] - 1, heap[previous][0], max);
    }
}

int main()
{
    int n_nodes;

    std::cin >> n_nodes;

    if (n_nodes != 0)
    {
        std::vector<std::vector<int>> array(n_nodes, std::vector<int>(3));

        for (int i = 0; i < n_nodes; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> array[i][j];
            }
        }

        check_correct (array, 0, INT_MIN, INT_MAX);
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
