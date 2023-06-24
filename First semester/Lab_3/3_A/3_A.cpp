#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;

    Node(int data = 0, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }

};

class List {
public:

    List() : head(nullptr), tail(nullptr){}

    void pushBack(int data);
    int delete_node();

private:

    Node* head;
    Node* tail;

};

void List::pushBack(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = tail;

    temp->next = newNode;
    tail = newNode;

}

int List::delete_node() {
    int del;
    Node* temp = head;

    del = head->data;

    head = head->next;

    delete temp;
    return del;
}

int main() {
    int n, number;
    char operation;

    std::vector <int> out;

    List queue;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            if (j == 0) 
            {
                std::cin >> operation;

                if (operation == '-')
                {
                    out.push_back(queue.delete_node());
                    break;
                }

            }
            else if (j == 1 && operation == '+')
            {
                std::cin >> number;
                queue.pushBack(number);
            }
        }
    }

    for (int i = 0; i < out.size(); i++) 
    {
        std::cout << out[i] << "\n";
    }

    return 0;
}
