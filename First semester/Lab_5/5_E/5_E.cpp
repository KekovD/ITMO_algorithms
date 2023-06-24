#include <iostream>
#include <string>
#include <vector>

class Node
{
public:
    std::string data;
    Node* left;
    Node* right;

    explicit Node (std::string data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    Node* insert (Node *root, std::string key);
    int exist (Node* root, std::string key);
};

int Node::exist (Node *root, std::string key)
{
    if (!root)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    if (root->data > key)
    {
        return exist(root->left, key);
    }
    else
    {
        return exist(root->right, key);
    }
}

Node* Node::insert (Node *root, std::string key)
{
    if (!root)
    {
        Node* newNode = new Node(key);
        return newNode;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        root->left = insert (root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insert (root -> right, key);
    }
    return root;
}

int main ()
{
    int n, result1, result2, result3;
    int check1, check2, check3;
    std::string key;
    Node* first = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    std::vector <std::vector <std::string>> all_keys(3, std::vector <std::string> (n));
    result1 = result2 = result3 = 0;
    check1 = check2 = check3 = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> key;
        all_keys[0][i] = key;
        first = first->insert (first, key);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> key;
        all_keys[1][i] = key;
        second = second->insert (second, key);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> key;
        all_keys[2][i] = key;
        third = third->insert (third, key);
    }

    for (int i = 0; i < n; i++)
    {
        check2 = second->exist (second, all_keys[0][i]);
        check3 = third->exist (third, all_keys[0][i]);

        if (check2 && check3)
        {
            continue;
        }
        else if (check2 || check3)
        {
            result1++;
        }
        else
        {
            result1 += 3;
        }
    }

    for (int i = 0; i < n; i++)
    {
        check1 = first->exist (first, all_keys[1][i]);
        check3 = third->exist (third, all_keys[1][i]);

        if (check1 && check3)
        {
            continue;
        }
        else if (check1 || check3)
        {
            result2++;
        }
        else
        {
            result2 += 3;
        }
    }

    for (int i = 0; i < n; i++)
    {
        check1 = first->exist (first, all_keys[2][i]);
        check2 = second->exist (second, all_keys[2][i]);

        if (check1 && check2)
        {
            continue;
        }
        else if (check1 || check2)
        {
            result3++;
        }
        else
        {
            result3 += 3;
        }
    }

    std::cout << result1 << ' ' << result2 << ' ' << result3;

    return 0;
}
