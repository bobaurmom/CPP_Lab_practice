#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    
public:
    CircularLinkedList() {
        head = nullptr;
    }
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }
    
    bool search(int val) {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == val) {
                cout << "Found" << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found " << endl;
        return false;
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.display();
    cll.search(20);
    cll.search(50);
    cll.deleteHead();
    cll.display();
    
    return 0;
}
