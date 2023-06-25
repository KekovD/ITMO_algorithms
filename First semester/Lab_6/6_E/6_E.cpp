#include <iostream>
#include <string>

class Node
{
public:
    explicit Node (int data = 0, int height = 0, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->height = height;
        this->left = left;
        this->right = right;
    }

    Node* insert (Node*, int);
    Node* del (Node*, int);
    bool search (Node*, int);
    int balance (Node*);

private:
    int data;
    int height;
    Node* left;
    Node* right;

    Node* previous (Node*, int);
    int root_height (Node*);
    Node* minimum (Node*);
    Node* maximum (Node*);
    Node* rotate_right (Node*);
    Node* rotate_left (Node* root);
    void fix_height (Node*);
    Node* new_balance (Node*);
    Node* big_rotate_right (Node*);
    Node* big_rotate_left (Node*);
};

Node* Node::previous (Node *root, int key)
{
    Node* current = root;
    Node* successor = nullptr;

    while (current)
    {
        if (current->data < key)
        {
            successor = current;
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return successor;
}

int Node::root_height (Node* h)
{
    if (!h)
    {
        return 0;
    }

    return h->height;
}

Node* Node::minimum (Node* root)
{
    if (!root->left)
    {
        return root;
    }

    return minimum (root->left);
}

Node* Node::maximum (Node* root)
{
    if (!root->right)
    {
        return root;
    }

    return maximum (root->left);
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


Node* Node::big_rotate_right (Node* root)
{
    rotate_left (root->left);
    rotate_right (root);
}

Node* Node::big_rotate_left (Node* root)
{
    rotate_right (root->right);
    rotate_left (root);
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

Node* Node::del (Node* root, int val)
{
    if (!root)
    {
        return root;
    }

    if (val < root->data)
    {
        root->left = del (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = del (root->right, val);
    }
    else if (root->left && root->right)
    {
        root->data = previous (root->left, val)->data;
        root->left = del (root->left, root->data);
    }
    else
    {
        if (root->left)
        {
            Node* tmp = root;
            root = root->left;
            delete tmp;
            return new_balance (root);
        }
        else if (root->right)
        {
            Node* tmp = root;
            root = root->right;
            delete tmp;
            return new_balance (root);
        }
        else
        {
            delete root;
            root = nullptr;
            return nullptr;
        }
    }

    return new_balance (root);
}

bool Node::search (Node* root, int val)
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
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    std::string operation;
    int number, n;
    Node* tree = nullptr;
    std::cin >> n;

    while (std::cin >> operation)
    {
        if (operation.empty ()) break;

        std::cin >> number;

        if (operation == "A")
        {
            if (!tree->search (tree, number))
            {
                tree = tree->insert (tree, number);
                std::cout << tree->balance (tree) << "\n";
            }
            else
            {
                std::cout << tree->balance (tree) << "\n";
            }
        }
        else if (operation == "D")
        {
            if (tree->search (tree, number))
            {
                tree = tree->del (tree, number);
            }

            tree ? std::cout << tree->balance (tree) << '\n' : std::cout << 0 << '\n';

        }
        else if (operation == "C")
        {
            tree->search (tree, number) ? std::cout << 'Y' << '\n' : std::cout << 'N' << '\n';

        }
    }

    return 0;
}
