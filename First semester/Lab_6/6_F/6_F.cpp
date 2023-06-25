#include <iostream>
#include <vector>

class Node
{
public:
    explicit Node(std::string data = nullptr, char data_ch = 0, int height = 1, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->data_ch = data_ch;
        this->height = height;
        this->left = left;
        this->right = right;
    }

    Node* insert (Node*, std::string);
    bool search (Node*, std::string);
    Node* insert_second (Node*, char);
    bool search_second (Node*, char);

private:
    std::string data;
    char data_ch;
    int height;
    Node* left;
    Node* right;

    int root_height (Node*);
    void fix_height (Node*);
    Node* rotate_right (Node*);
    Node* rotate_left (Node*);
    int balance (Node*);
    Node* minimum (Node*);
    Node* del_root (Node*, std::string);
};

Node* Node::insert_second (Node* root, char value)
{
    if (!root)
    {
        root = new Node (" ", value);
    }
    else if (value == root->data_ch)
    {
        return root;
    }
    else if (root->data_ch < value)
    {
        root->right = insert_second (root->right, value);
    }
    else if (root->data_ch > value)
    {
        root->left = insert_second (root->left, value);
    }

    return root;
}

bool Node::search_second (Node* root, char value)
{
    if (!root)
    {
        return false;
    }
    if (value == root->data_ch)
    {
        return true;
    }
    if (root->data_ch < value)
    {
        return search_second (root->right, value);
    }
    else if (root->data_ch > value)
    {
        return search_second (root->left, value);
    }
}

int Node::root_height (Node* element)
{
    if (!element)
    {
        return 0;
    }

    return element->height;
}

void Node::fix_height (Node* root)
{
    root->height = (root_height (root->left) > root_height (root->right)
            ? root_height (root->left) : root_height (root->right)) + 1;
}

Node* Node::rotate_right (Node* root)
{
    Node* root1 = root->left;
    root->left = root1->right;
    root1->right = root;
    fix_height (root);
    fix_height (root1);

    return root1;
}

Node* Node::rotate_left (Node* root)
{
    Node* root1 = root->right;
    root->right = root1->left;
    root1->left = root;
    fix_height (root);
    fix_height (root);

    return root1;
}

int Node::balance (Node* element)
{
    if (!element)
    {
        return 0;
    }

    return root_height (element->left) - root_height (element->right);
}

Node* Node::insert (Node* root, std::string value)
{
    if (!root)
    {
        root = new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert (root->right, value);
    }
    else
    {
        return root;
    }

    root->height = 1 + std::max (root_height (root->left), root_height (root->right));

    if (balance (root) > 1)
    {
        if (value < root->left->data)
        {
            return rotate_right (root);
        }
        else if (value > root->left->data)
        {
            root->left = rotate_left (root->left);
            return rotate_right (root);
        }
    }

    if (balance (root) < -1)
    {
        if (value > root->right->data)
        {
            return rotate_left (root);
        }
        else if (value < root->right->data)
        {
            root->right = rotate_right (root->right);
            return rotate_left (root);
        }
    }

    return root;
}

Node* Node::minimum (Node* root)
{
    if (!root->left)
    {
        return root;
    }

    return minimum (root->left);
}

Node* Node::del_root (Node* root, std::string value)
{
    if (!root)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = del_root (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = del_root (root->right, value);
    }
    else
    {
        if (!root->left || !root->right)
        {
            Node* temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
        }
        else
        {
            Node* temp = minimum (root->right);
            root->data = temp->data;
            root->right = del_root (root->right, temp->data);
        }
    }

    if (!root)
    {
        return root;
    }

    root->height = 1 + std::max (root_height (root->left), root_height (root->right));

    if (balance (root) > 1)
    {
        if (balance (root->left) >= 0)
        {
            return rotate_right (root);
        }
        else
        {
            root->left = rotate_left (root->left);
            return rotate_right (root);
        }
    }

    if (balance (root) < -1)
    {
        if (balance (root->right) <= 0)
        {
            return rotate_left (root);
        }
        else
        {
            root->right = rotate_right (root->right);
            return rotate_left (root);
        }
    }
    return root;
}

bool Node::search (Node* root, std::string value)
{
    if (!root)
    {
        return false;
    }
    if (value == root->data)
    {
        return true;
    }
    if (root->data < value)
    {
        return search (root->right, value);
    }
    else if (root->data > value)
    {
        return search (root->left, value);
    }
}

void number (int it, std::vector<std::vector<std::string>> &array, int &counter)
{
    Node* second = nullptr;
    std::string element = array[1][it];

    if (array[1][it].length () == 1)
    {
        counter++;
    }
    else
    {
        for (int i = 0; i < array[1][it].length (); i++)
        {
            if (!second->search_second (second, element[i]))
            {
                second =  second->insert_second (second, element[i]);
                counter++;
            }
        }
    }
}

int main ()
{
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int n, count = 0;;
    Node* tree = nullptr;

    std::cin >> n;
    std::vector<std::vector<std::string>> array (2, std::vector<std::string> (n));

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[0][i];
    }

    for (int i = 0; i < n; i++)
    {
        if (!tree->search (tree, array[0][i]))
        {
            tree = tree->insert (tree, array[0][i]);
        }
        else
        {
            array[1][i] = array[0][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        number (i, array, count);
    }

    std::cout << count;

    return 0;
}
