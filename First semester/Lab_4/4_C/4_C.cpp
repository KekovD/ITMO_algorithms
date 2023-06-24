#include <iostream>
#include <string>
#include <vector>

class Node {
public:

    int data, counter;
    Node* next,* previous;

    explicit Node(int data = 0, int counter = 1, Node* next = nullptr, Node* previous = nullptr)
    {
        this->data = data;
        this->counter = counter;
        this->next = next;
        this->previous = previous;
    }
};

class List {
public:

    int size;
    std::vector<Node*> index;

    Node* head;
    Node* tail;

    List() : size(0), head(nullptr), tail(nullptr){}

    void swap (Node *left, Node* right);
    void siftUp(int i);
    void siftDown(int i);
    void push_back(int number, int counter);
    void delete_node();
    void built(int n, int i);
    void extractMin();
    void replace(int key, int number);
};

void List::swap(Node *left, Node* right)
{
    if (left->next == right)
    {
        Node *left_p = left->previous;

        if (right->next != nullptr)
        {
            right->next->previous = left;
        }

        if (left->previous != nullptr)
        {
            left->previous->next = right;
        }

        left->next = right->next;
        left->previous = right;
        right->next = left;
        right->previous = left_p;

    }
    else if (right->next == left)
    {
        Node* right_p = right->previous;

        if (left->next != nullptr)
        {
            left->next->previous = right;
        }

        if (right->previous != nullptr)
        {
            right->previous->next = left;
        }

        right->next = left->next;
        right->previous = left;
        left->next = right;
        left->previous = right_p;
    }
    else
    {
        Node* left_n = left->next,* left_p = left->previous;

        if (right->next != nullptr)
        {
            right->next->previous = left;
        }

        if (right->previous != nullptr)
        {
            right->previous->next = left;
        }

        if (left->next != nullptr)
        {
            left->next->previous = right;
        }

        if (left->previous != nullptr)
        {
            left->previous->next = right;
        }

        left->next = right->next;
        left->previous = right->previous;
        right->next = left_n;
        right->previous = left_p;
    }

    if (left == head)
    {
        head = right;
    }
    else if (right == head)
    {
        head = left;
    }

    if (right == tail)
    {
        tail = left;
    }
    else if (left == tail)
    {
        tail = right;
    }

}

void List::siftUp(int i)
{
    while (index[i]->data < index[(i - 1) / 2]->data)
    {
        swap(index[i], index[(i - 1) / 2]);
        std::swap(index[i], index[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void List::siftDown(int i)
{
    int left, right, j;

    while (2 * i + 1 < size)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;

        if (right < size && index[right]->data < index[left]->data)
        {
            j = right;
        }

        if (index[i]->data <= index[j]->data)
        {
            break;
        }

        swap(index[i], index[j]);
        std::swap(index[i], index[j]);

        i = j;
    }
}

void List::push_back(int number, int counter)
{
    Node* newNode = new Node(number, counter);

    size++;

    if (head == nullptr || tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        index.push_back(newNode);
        return;
    }

    Node* temp = tail;

    newNode->previous = temp;
    temp->next = newNode;
    tail = newNode;
    index.push_back(newNode);

    siftUp(size - 1);
}

void List::delete_node()
{
    if (size == 0)
    {
        std::cout << "*\n";
    }
    else if (size == 1)
    {
        Node* temp = head;
        head->next = nullptr;
        head->previous = nullptr;
        tail->previous = nullptr;
        tail->next = nullptr;

        head = nullptr;
        tail = nullptr;
        index.pop_back();
        size--;

        std::cout << temp->data << "\n";

        delete temp;
    }
    else if (size > 1)
    {
        Node *temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        index.pop_back();
        size--;

        std::cout << temp->data << "\n";

        delete temp;
    }
}

void List::built(int n, int i)
{
    int smallest, left, right;

    smallest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && index[left]->data < index[smallest]->data)
    {
        smallest = left;
    }

    if (right < n && index[right]->data < index[smallest]->data)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(index[i], index[smallest]);
        std::swap(index[i], index[smallest]);
        built(n, smallest);
    }
}

void List::extractMin()
{
    if (size > 1)
    {
        swap(index[0], index[size - 1]);
        std::swap(index[0], index[size - 1]);
    }
    
    delete_node();
    siftDown(0);
}

void List::replace(int key, int number)
{
    Node* tmp = head;

    for (int i = 0; i < size; i++)
    {
        if (tmp->counter == key)
        {
            tmp->data = number;

            for (int j = size / 2 - 1; j >= 0; j--)
            {
                built(size, j);
            }

            break;
        }
        tmp = tmp->next;
    }
}

int main()
{
    int number, key, counter = 1;
    std::string operation;
    const std::string decrease = "decrease-key", push = "push", min = "extract-min";

    List queue;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (std::cin >> operation)
    {
        if (operation.empty()) break;

        if (operation == min)
        {
            queue.extractMin();
            counter++;
        }

        if (operation == push)
        {
            std::cin >> number;
            queue.push_back(number, counter);
            counter++;
        }
        else if (operation == decrease)
        {
            std::cin >> key >> number;
            queue.replace(key, number);
            counter++;
        }
    }
    return 0;
}
