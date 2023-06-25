#include <iostream>
#include <vector>

class Node
{
public:
    explicit Node (int data = 0, int height = 1, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->height = height;
        this->left = left;
        this->right = right;
    }

    Node* insert (Node*, std::vector<std::vector<int>>&, int);
    void level_order (Node*);

private:
    int data;
    int height;
    Node* left;
    Node* right;

    int get_height (Node*);
    void fix_height (Node*);
    Node* right_rotate (Node*);
    Node* left_rotate (Node*);
    int balance_factor (Node*);
    Node* balance (Node*);
    void current_level (Node*, int, int&);
};

int Node::get_height (Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
}

void Node::fix_height (Node* root)
{
    if (!root)
    {
        return;
    }

    int h_left;
    int h_right;

    h_left = get_height (root->left);
    h_right = get_height (root->right);

    if (h_left > h_right)
    {
        root->height = h_left + 1;
    }
    else
    {
        root->height = h_right + 1;
    }
}

Node* Node::right_rotate (Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    fix_height (root);
    fix_height (temp);

    return temp;
}

Node* Node::left_rotate (Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    fix_height (root);
    fix_height (temp);

    return temp;
}

int Node::balance_factor (Node* root)
{
    if (!root)
    {
        return 0;
    }

    return get_height (root->right) - get_height (root->left);
}

Node* Node::balance (Node* root)
{
    fix_height (root);

    int balance = balance_factor (root);

    if (balance > 1)
    {
        if (balance_factor (root->right) < 0)
        {
            root->right = right_rotate (root->right);
        }

        return left_rotate (root);
    }

    if (balance < -1)
    {
        if (balance_factor (root->left) > 0)
        {
            root->left = left_rotate (root->left);
        }

        return right_rotate (root);
    }
    return root;
}

Node* Node::insert (Node* root, std::vector<std::vector<int>>& array, int index)
{
    root = new Node (array[index][0]);

    if (!array[index][1] && !array[index][2])
    {
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    if (array[index][1])
    {
        root->left = insert (root->left, array, array[index][1] - 1);
    }
    else
    {
        root->left = nullptr;
    }

    if (array[index][2])
    {
        root->right = insert (root->right, array, array[index][2] - 1);
    }
    else
    {
        root->right = nullptr;
    }

    return balance (root);
}

void Node::current_level (Node* root, int level, int& count)
{
    if (!root)
    {
        return;
    }

    if (level == 1 && root->left && root->right)
    {
        std::cout << root->data << ' ' << count++ << ' ' << count++ << '\n';
    }
    else if (level == 1 && root->left && !root->right)
    {
        std::cout << root->data << ' ' << count++ << ' ' << 0 << "\n";
    }
    else if (level == 1 && !root->left && root->right)
    {
        std::cout << root->data << ' ' << 0 << ' ' << count++ << "\n";
    }
    else if (level == 1 && !root->left && !root->right)
    {
        std::cout << root->data << ' ' << 0 << ' ' << 0 << "\n";
    }
    else if (level > 1)
    {
        current_level (root->left, level - 1, count);
        current_level (root->right, level - 1, count);
    }
}

void Node::level_order (Node* root)
{
    int h = get_height (root);

    int count = 2;

    for (int i = 1; i <= h; i++)
    {
        current_level (root, i, count);
    }
}

int main ()
{
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> array (n, std::vector<int> (4));

    Node* tree = nullptr;

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i][0] >> array[i][1] >> array[i][2];
        array[i][3] = 1;
    }

    tree = tree->insert (tree, array, 0);
    std::cout << n << "\n";
    tree->level_order (tree);

    return 0;
}
