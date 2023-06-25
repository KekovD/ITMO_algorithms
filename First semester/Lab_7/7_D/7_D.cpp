#include <iostream>
#include <string>
#include <cstring>

void BestScreenshot (int N, int M)
{
    int length = 0, coordinates1 = 0, coordinates2 = 0, prev = 0, tmp;
    int answerSearch[M + 1];
    char matrix[M];
    std::string input;

    memset (answerSearch, 0, sizeof (answerSearch));
    memset (matrix, 0, sizeof (matrix));


    for (int i = 1; i <= N; i++)
    {
        std::cin >> input;
        for (int i = 0; i < M; i++)
        {
            matrix[i] = input[i];
        }

        for (int j = 1; j <= M; j++)
        {
            tmp = answerSearch[j];

            if (matrix[j - 1] == '5')
            {
                answerSearch[j] = std::min (answerSearch[j], std::min (answerSearch[j - 1], prev)) + 1;

                if (length < answerSearch[j] || length == answerSearch[j])
                {
                    length = answerSearch[j];
                    coordinates1 = i - length + 1;
                    coordinates2 = j - length + 1;
                }
            }
            else
            {
                answerSearch[j] = 0;
            }
            prev = tmp;
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

    BestScreenshot (N, M);

    return 0;
}
