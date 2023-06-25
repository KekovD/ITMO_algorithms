#include <iostream>
#include <string>
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
    Node* insert (Node*, int);
    void level_order (Node*);

private:
    int data;
    int height;
    Node* left;
    Node* right;

    int root_height (Node*);
    Node* rotate_right (Node*);
    Node* rotate_left (Node* root);
    void fix_height (Node*);
    void current_level (Node*, int, int&);
    Node* new_balance (Node*);
    int balance (Node*);
    int get_height (Node*);
};

int Node::root_height (Node* h)
{
    if (!h)
    {
        return 0;
    }

    return h->height;
}

Node* Node::rotate_right (Node* root)
{
    Node* root2 = root->left;
    Node* tmp = root2->right;
    root2->right = root;
    root->left = tmp;
    root->height = std::max (root_height (root->left), root_height (root->right)) + 1;
    root2->height = std::max (root_height (root2->left), root_height (root2->right)) + 1;

    return root2;
}

Node* Node::rotate_left (Node* root)
{
    Node* root2 = root->right;
    Node* tmp = root2->left;
    root2->left = root;
    root->right = tmp;
    root->height = std::max (root_height (root->left), root_height (root->right)) + 1;
    root2->height = std::max (root_height (root2->left), root_height (root2->right)) + 1;

    return root2;
}

int Node::balance (Node* h)
{
    if (!h)
    {
        return 0;
    }
    else
    {
        return root_height (h->right) - root_height (h->left);
    }
}

void Node::fix_height (Node* root)
{
    root->height = std::max (root_height (root->left), root_height (root->right)) + 1;
}

Node* Node::new_balance (Node* root)
{
    fix_height (root);

    if (balance (root) > 1)
    {
        if (balance (root->right) < 0)
        {
            root->right = rotate_right (root->right);
        }

        return rotate_left (root);
    }
    if (balance (root) < -1)
    {
        if (balance (root->left) > 0)
        {
            root->left = rotate_left (root->left);
        }

        return rotate_right (root);
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

    return new_balance (root);
}

int Node::get_height (Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
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

Node* Node::insert (Node* root, int val)
{
    if (!root)
    {
        root = new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert (root->right, val);
    }

    return new_balance (root);
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

    int n, key = 0;

    std::cin >> n;

    if (!n)
    {
        std::vector<std::vector<int>> array (1, std::vector<int> (3));

        std::cin >> array[0][0] >> array[0][1] >> array[0][2];
        std::cout << ++n << '\n';
        std::cout << array[0][0] << ' ' << array[0][1] << ' ' << array[0][2];
    }
    else
    {
        std::vector<std::vector<int>> array (n, std::vector<int> (3));

        for (int i = 0; i < n; i++)
        {
            std::cin >> array[i][0] >> array[i][1] >> array[i][2];
        }

        Node* tree = nullptr;

        std::cin >> key;

        tree = tree->insert (tree, array, 0);

        if (key)
        {
            tree = tree->insert (tree, key);
            n++;
        }

        std::cout << n << "\n";

        tree->level_order (tree);
    }

    return 0;
}
