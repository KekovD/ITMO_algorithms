#include <iostream>
#include <vector>

class Node
{
public:
    explicit Node (std::string data = nullptr, int height = 1, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->height = height;
        this->left = left;
        this->right = right;
    }

    Node* insert (Node*, std::string);
    bool search (Node*, std::string);

private:
    std::string data;
    int height;
    Node* left;
    Node* right;

    int root_height (Node*);
    void fix_height (Node*);
    Node* rotate_right (Node* root);
    Node* rotate_left (Node* root);
    int balance (Node*);
};

int Node::root_height (Node* h)
{
    if (!h)
    {
        return 0;
    }

    return h->height;
}

void Node::fix_height (Node* root)
{
    root->height = std::max (root_height (root->left), root_height (root->right)) + 1;
}

Node* Node::rotate_right (Node* root)
{
    Node* temp_root = root->left;
    root->left = temp_root->right;
    temp_root->right = root;
    fix_height (root);
    fix_height (temp_root);

    return temp_root;
}

Node* Node::rotate_left (Node* root)
{
    Node* temp_root = root->right;
    root->right = temp_root->left;
    temp_root->left = root;
    fix_height (root);
    fix_height (root);

    return temp_root;
}

int Node::balance (Node* h)
{
    if (!h)
    {
        return 0;
    }

    return root_height (h->left) - root_height (h->right);
}

Node* Node::insert (Node* root, std::string val)
{
    if (!root)
    {
        root = new Node (val);
    }

    if (val < root->data)
    {
        root->left = insert (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert (root->right, val);
    }
    else
    {
        return root;
    }

    root->height = 1 + std::max (root_height (root->left), root_height (root->right));

    if (balance (root) > 1)
    {
        if (val < root->left->data)
        {
            return rotate_right (root);
        }
        else if (val > root->left->data)
        {
            root->left = rotate_left (root->left);
            return rotate_right (root);
        }
    }

    if (balance (root) < -1)
    {
        if (val > root->right->data)
        {
            return rotate_left (root);
        }
        else if (val < root->right->data)
        {
            root->right = rotate_right (root->right);
            return rotate_left (root);
        }
    }

    return root;
}

bool Node::search (Node* root, std::string val)
{
    if (!root)
    {
        return false;
    }

    if (val == root->data)
    {
        return true;
    }

    if (root->data < val)
    {
        return search (root->right, val);
    }
    else if (root->data > val)
    {
        return search (root->left, val);
    }
}

int main ()
{
    int n, result1, result2, result3;
    int check1, check2, check3;
    std::string key;
    Node* first = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    std::cin >> n;
    std::vector<std::vector<std::string>> all_keys (3, std::vector<std::string> (n));
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
        check2 = second->search (second, all_keys[0][i]);
        check3 = third->search (third, all_keys[0][i]);

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
        check1 = first->search (first, all_keys[1][i]);
        check3 = third->search (third, all_keys[1][i]);

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
        check1 = first->search (first, all_keys[2][i]);
        check2 = second->search (second, all_keys[2][i]);

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
