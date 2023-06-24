#include <iostream>
#include <string>
#include <vector>

class Node {
public:

    char data;
    Node* next,* previous;

    Node(char data, Node* next = nullptr, Node* previous = nullptr)
    {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

};

class List {
public:

    int list_size, open_brackets, close_brackets;

    List() : head(nullptr), tail(nullptr), list_size(0), open_brackets(0), close_brackets(0){}
    ~List() = default;

    void pushBack(char data);
    void delete_node();
    void compare_nodes(char input);

private:

    Node* head;
    Node* tail;

};

void List::pushBack(char data) {

    Node* newNode = new Node(data);

    list_size++;
    open_brackets++;

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

    Node* temp = tail;
    tail = tail->previous;
    list_size--;

    delete temp;
}

void List::compare_nodes(char input) {

    close_brackets++;

    if (tail)
    {
        if ((tail->data == '(' && input == ')') || (tail->data == '[' && input == ']'))
        {
            delete_node();
        } 
        else
        {
            return;
        }
    }
}

int main() {
    bool count;
    std::string input;
    std::vector <bool> output;

    while (std::getline(std::cin, input))
    {
        if (input.empty()) break;

        List Stack;

        count = true;

        for (int i = 0; i < input.size(); i++) {

            if ((input[i] == ')' || input[i] == ']') && i == 0)
            {
                output.push_back(false);
                count = false;
                break;
            }
            else if ((input[i] == ')' || input[i] == ']') && i > 0)
            {
                Stack.compare_nodes(input[i]);
            }
            else if (input[i] == '(' || input[i] == '[')
            {
                Stack.pushBack(input[i]);
            }
        }

        if (count)
        {
            if (Stack.open_brackets != Stack.close_brackets)
            {
                output.push_back(false);
            }
            else if (Stack.list_size)
            {
                output.push_back(false);
            }
            else if (Stack.list_size == 0)
            {
                output.push_back(true);
            }
        }

        while (Stack.list_size)
        {
            Stack.delete_node();
        }

        Stack.~List();
    }

    for (int i = 0; i < output.size(); i++)
    {
        if (output[i])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
