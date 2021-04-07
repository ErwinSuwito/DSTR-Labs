
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertatBeginnning(int new_data) {
    auto* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int new_data) {
    auto* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;


    if (head == NULL)
        head = new_node;
    else {
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}


void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

bool search(int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value)
            return true;
        else
            current = current->next;
    }
    return false;;
}

int size() {
    struct Node* ptr;
    ptr = head;
    int temp = 0;

    while (ptr != nullptr) {
        temp++;
        ptr = ptr->next;
    }
    return temp;
}

int getItemAt(int index) {
    if (index < 0 || index >= size()) {
        throw "Index out of bound. \n";
    }
    Node* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}


int main() {
    insertAtEnd(3);
    insertAtEnd(1);
    insertAtEnd(7);
    insertAtEnd(2);
    insertAtEnd(9);

    cout << "The linked list is: ";
    display();


    cout << endl << "Search value 7: " << search(7);// New
    cout << endl << "Size: " << size();// New

    cout << endl << "Item at 0: " << getItemAt(0);

    return 0;
}