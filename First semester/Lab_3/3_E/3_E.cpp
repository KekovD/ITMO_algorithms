#include <iostream>
#include <cstring>
#include <vector>

class Node {
public:

    int data, max;
    Node* next,* previous;

    Node(int data = 0, int max = 0, Node* next = nullptr, Node* previous = nullptr)
    {
        this->data = data;
        this->max = max;
        this->next = next;
        this->previous = previous;

    }

};

class List {
public:

    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr){}

    void pushBack(int data);
    void delete_node();

};

void List::pushBack(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr || tail == nullptr)
    {
        newNode->max = data;
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = tail;

    newNode->previous = temp;
    temp->next = newNode;
    tail = newNode;

    if (tail->previous->max < data)
    {
        tail->max = data;
    }
    else
    {
        tail->max = tail->previous->max;
    }

}

void List::delete_node() {

    Node* temp = tail;

    tail = tail->previous;
    tail->next = nullptr;
    
    delete temp;
}

int main() {
    int n, number;
    char operation[4];
    const char minus[2] = "-", plus[2] = "+", max[4] = "max";

    std::vector <int> out;

    List stack;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            if (j == 0)
            {
                std::cin >> operation;

                if (!strncmp(operation, minus, 1))
                {
                    stack.delete_node();
                    break;
                }
                else if (!strncmp(operation, max, 3))
                {
                    out.push_back(stack.tail->max);
                    break;
                }

            }
            else if (j == 1 && !strncmp(operation, plus, 1))
            {
                std::cin >> number;
                stack.pushBack(number);
            }
        }
    }

    for (int i = 0; i < out.size(); i++)
    {
        std::cout << out[i] << "\n";
    }

    return 0;
}
