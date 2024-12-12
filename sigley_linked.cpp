#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define the class for the linked list
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free the memory allocated for the linked list
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
 
    // Function to add a new node at the end of the linked list
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to add a new node at the beginning of the linked list
    void prepend(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node with a specific data value
    void deleteNode(int data) {
        if (head == nullptr) return;

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == data) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Append nodes to the linked list
    list.append(10);
    list.append(20);
    list.append(30);

    // Print the linked list
    cout << "Linked List: ";
    list.printList();

    // Prepend a node to the linked list
    list.prepend(5);

    // Print the updated linked list
    cout << "Updated Linked List: ";
    list.printList();

    // Delete a node from the linked list
    list.deleteNode(20);

    // Print the updated linked list
    cout << "Updated Linked List after deletion: ";
    list.printList();

    return 0;
}