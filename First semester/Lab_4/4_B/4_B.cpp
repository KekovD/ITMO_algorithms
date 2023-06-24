#include <iostream>
#include <vector>

void built (std::vector<int> &mass, int n, int i)
{
    int max, left, right;

    max = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && mass[left] > mass[max])
    {
        max = left;
    }

    if (right < n && mass[right] > mass[max])
    {
        max = right;
    }

    if (max != i) {
        std::swap(mass[i], mass[max]);

        built(mass, n, max);
    }
}

void heapSort(std::vector<int> &mass, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        built(mass, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {

        std::swap(mass[0], mass[i]);

        built(mass, i, 0);
    }
}

int main()
{
   int n;
   std::vector<int> array;

   std::cin >> n;
   array.resize(n);

   for (int i = 0; i < n; i++)
   {
       std::cin >> array[i];
   }

   heapSort(array, n);

   for (int i = 0; i < n; i++)
   {
       std::cout << array[i] << " ";
   }

    return 0;
}
