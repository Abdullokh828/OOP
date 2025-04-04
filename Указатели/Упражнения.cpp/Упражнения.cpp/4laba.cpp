#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Singly linked list class
class LinkList {
private:
    Node* head; // Pointer to the head of the list
public:
    LinkList() : head(nullptr) {}

    // Add an element to the list
    void add(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Display the list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to delete all elements of the list
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
    list.add(10);
    list.add(20);
    list.add(30);

    cout << "Linked List: ";
    list.display();

    return 0;
}
