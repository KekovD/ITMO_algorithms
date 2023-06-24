#include <iostream>

int n;
double eps, first, out = -1, mid, h1, h2, h3;
bool ground;

double Binary_Search(double left, double right)
{
    if ((right - left)  > eps)
    {
        mid = (left + right) / 2;
        h1 = first, h2 = mid;
        ground =  h2 > 0;

        for (int i = 3; i <= n; i++)
        {
            h3 = 2 * h2 - h1 + 2;
            ground &= h3 > 0;
            h1 = h2;
            h2 = h3;
        }

        if (ground)
        {
            out = h2;
            return Binary_Search(left, mid);
        }
        else
        {
            return Binary_Search(mid, right);
        }
    }

    return out;
}

int main() {

    std::cin >> n >> first;

    eps = 0.001 / n;

    printf ("%.2f", Binary_Search(0, first));

    return 0;
}
