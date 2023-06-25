#include <iostream>
#include <vector>

void update (int n, int root, int value, std::vector<int>& tree)
{
    tree[root + n] = value;
    root += n;

    for (int i = root; i > 1; i >>= 1)
    {
        tree[i >> 1] = tree[i] + tree[i ^ 1];
    }
}

int query (int n, int left, int right, std::vector<int>& tree)
{
    int answer = 0;

    for (left += n, right += n; left < right; left >>= 1, right >>= 1)
    {
        if (left & 1)
        {
            answer += tree[left++];
        }

        if (right & 1)
        {
            answer += tree[--right];
        }
    }

    return answer;
}

int main ()
{
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int cats, num_cmd, left, right;
    char command;

    std::cin >> cats >> num_cmd;

    std::vector<int> tree (cats << 1);
    std::vector<int> keys (cats);
    std::vector<int> answer;

    for (int i = 0; i < num_cmd; i++)
    {
        std::cin >> command >> left >> right;

        switch (command)
        {
            case '+':
                keys [left - 1] += right;
                update (cats, left - 1, keys[left - 1], tree);
                break;

            case '-':
                keys[left - 1] <= right ? keys[left - 1] = 0 : keys[left - 1] -= right;
                update (cats, left - 1, keys[left - 1], tree);
                break;

            case '?':
                answer.push_back (query (cats, left - 1, right, tree));
                break;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << '\n';
    }

    return 0;
}
