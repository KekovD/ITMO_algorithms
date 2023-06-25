#include <iostream>
#include <string>

void BestScreenshot (int N, int M)
{
    int length = 0, coordinates1 = 0, coordinates2 = 0;
    int answerSearch[N][M];
    short int matrix[N][M];
    std::string temp;

    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = temp[j] - '0';
        }
    }

    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = M - 1; j >= 0; --j)
        {
            answerSearch[i][j] = 0;
            if (i == N - 1 || j == M - 1)
            {
                if (matrix[i][j] == 5)
                {
                    answerSearch[i][j] = 1;
                }
            }
            else
            {
                if (matrix[i][j] == 5)
                {
                    answerSearch[i][j] = std::min (answerSearch[i + 1][j], std::min (answerSearch[i][j + 1], answerSearch[i + 1][j + 1])) + 1;
                }
            }

            if (answerSearch[i][j] > length)
            {
                length = answerSearch[i][j];
                coordinates1 = i + 1;
                coordinates2 = j + 1;
            }
        }
    }
    std::cout << length << ' ' << coordinates1 << ' ' << coordinates2;
}

int main ()
{
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int N, M;

    std::cin >> N >> M;

    BestScreenshot(N, M);

    return 0;
}
