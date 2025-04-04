#include <iostream>
using namespace std;

// Node class representing one element of the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkList {
private:
    Node* head; // Pointer to the first node

public:
    LinkList() : head(nullptr) {}

    // Function to add an item at the end of the list
    void additem(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the list
    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Destructor to clean up the memory
    ~LinkList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            cout << "Deleting node with value: " << temp->data << endl;
            delete temp;
        }
    }
};

int main() {
    LinkList list;
    list.additem(25);
    list.additem(36);
    list.additem(49);
    list.additem(64);

    cout << "Linked List contents:" << endl;
    list.display();

    return 0;
}