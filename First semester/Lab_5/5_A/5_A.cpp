#include <iostream>
#include <vector>

int max = 0;

void check_height(std::vector <std::vector<int>> &heap, int counter, int n)
{
    counter++;

    if (counter > max)
    {
        max = counter;
    }

    if (heap[n][1] > 0)
    {
        check_height(heap, counter, heap[n][1] - 1);
    }

    if (heap[n][2] > 0)
    {
        check_height(heap, counter, heap[n][2] - 1);
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

        check_height(array, 0, 0);
    }

    std::cout << max;

    return 0;
}
