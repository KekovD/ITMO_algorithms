#include <iostream>
#include <string>
#include <cstring>

class Node {
public:

    int data;
    Node* next,* previous;

    Node(int data = 0, Node* next = nullptr, Node* previous = nullptr)
    {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

};

class List {
public:

    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr){}
    ~List() = default;

    void pushBack(int data);
    void delete_node();
    void operation(std::string op);
};

void List::pushBack(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr || tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = tail;

    newNode->previous = temp;
    temp->next = newNode;
    tail = newNode;

}

void List::delete_node() {

    for (int i = 0; i < 2; i++)
    {
        Node *temp = tail;

        tail = tail->previous;

        delete temp;
    }
}

void List::operation(std::string op) {
    int temp1 = tail->data, temp2 = tail->previous->data;

    if (op == "-")
    {
        delete_node();
        pushBack(temp2 - temp1);
    }
    else if (op == "+")
    {
        delete_node();
        pushBack(temp2 + temp1);
    }
    else
    {
        delete_node();
        pushBack(temp2 * temp1);
    }
}


int main() {
    char str[128];
    std::string input;
    List Stack;

    std::cin.getline(str, 128, '\n');

    char* in = strtok (str," ");

    while (in != nullptr)
    {
        input = in;

        if (input == "-" || input == "+" || input == "*")
        {
            Stack.operation(input);
        }
        else
        {
            Stack.pushBack(stoi(input));
        }

        in = strtok (nullptr, " ");
    }

    std::cout << Stack.tail->data;

    Stack.~List();

    return 0;
}
