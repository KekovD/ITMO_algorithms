#include <iostream>
#include <string>

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    explicit Node (int data = 0, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    Node* minimum (Node* root);
    Node* insert (Node *root, int num);
    Node* deleteNode (Node *root, int key);
    bool exist (Node* root, int key);
    Node* next (Node* root, int key);
    Node* previous (Node* root, int key);
};

Node* Node::insert (Node *root, int num)
{
    if (!root)
    {
        Node* newNode = new Node(num);
        return newNode;
    }
    else if (root->data == num)
    {
        return root;
    }
    else if (root->data > num)
    {
        root->left = insert (root->left, num);
    }
    else if (root->data < num)
    {
        root->right = insert (root -> right, num);
    }

    return root;
}

Node *Node::minimum (Node *root)
{
    if (!root->left) {
        return root;
    }
    return minimum(root->left);
}

Node *Node::deleteNode (Node *root, int key)
{
    if (!root)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode (root->right, key);
    }
    else if (root->left && root->right)
    {
        root->data = minimum (root->right)->data;
        root->right = deleteNode (root->right, root->data);
    }
    else
    {
        if (root->left)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

bool Node::exist (Node *root, int key)
{
    if (!root)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
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

Node* Node::next (Node *root, int key)
{
    Node *current = root;
    Node *successor = nullptr;

    while (current)
    {
        if (current->data > key)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return successor;
}

Node* Node::previous (Node *root, int key)
{
    Node *current = root;
    Node *successor = nullptr;

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

int main ()
{
    std::string operation;
    int key;
    Node* tree = nullptr;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (std::cin >> operation)
    {
        if (operation.empty ()) break;

        std::cin >> key;

        if (operation == "insert")
        {
            tree = tree->insert (tree, key);
        }

        if (operation == "delete")
        {
            tree = tree->deleteNode (tree, key);
        }

        if (operation == "exists")
        {
            tree->exist (tree, key) ? std::cout << "true\n" : std::cout << "false\n";
        }

        if (operation == "next")
        {
            Node* temp = tree->next(tree, key);
            temp == nullptr ? std::cout << "none\n" : std::cout << temp->data << "\n";
        }

        if (operation == "prev")
        {
            Node* temp = tree->previous (tree, key);
            temp == nullptr ? std::cout << "none\n" : std::cout << temp->data << "\n";
        }
    }
    return 0;
}
