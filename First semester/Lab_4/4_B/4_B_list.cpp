#include <iostream>
#include <vector>

class Node {
public:

    int data;
    Node* next,* previous;

    explicit Node(int data = 0, Node* next = nullptr, Node* previous = nullptr)
    {
        this->data = data;
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
    void built (int n, int i);
    void heap_sort(int n);
    void push_back(int number);
    void delete_node();
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

   if (right == tail)
   {
       tail = left;
   }
}

void List::built(int n, int i)
{
    int largest, left, right;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && index[left]->data > index[largest]->data)
    {
        largest = left;
    }

    if (right < n && index[right]->data > index[largest]->data)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(index[i], index[largest]);
        std::swap(index[i], index[largest]);
        built(n, largest);
    }
}

void List::heap_sort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        built(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(index[0], index[i]);
        std::swap(index[0], index[i]);
        built(i, 0);
    }
}

void List::push_back(int number)
{
    Node* newNode = new Node(number);

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
}

void List::delete_node()
{
    if (size == 1)
    {
        Node* temp = head;
        head->next = nullptr;
        head->previous = nullptr;
        tail->previous = nullptr;
        tail->next = nullptr;

        head = nullptr;
        tail = nullptr;
        size--;

        std::cout << temp->data << " ";

        delete temp;
    }
    else if (size > 1)
    {
        Node *temp = head;
        head = head->next;
        head->previous = nullptr;
        size--;

        std::cout << temp->data << " ";

        delete temp;
    }
}

int main()
{
    int n, number;

    List Heap;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> number;
        Heap.push_back(number);
    }

    Heap.heap_sort(n);

    for (int i = 0; i < n; i++)
    {
        Heap.delete_node();
    }

    return 0;
}
