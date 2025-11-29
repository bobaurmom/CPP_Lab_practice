#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    char data[100];
    int top;
public:
    ArrayStack() {
        top = -1;
    }
    
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (top == 99) {
            return true;
        }
        return false;
    }

    void push(char value) {
        if (!isFull()) {
            top = top + 1;
            data[top] = value;
        }
    }
    
    char pop() {
        if (!isEmpty()) {
            char value = data[top];
            top = top - 1;
            return value;
        }
        return '\0';
    }
    
    char peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0';
    }
};

struct Node {
    string data;
    Node* next;
    
    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class LinkedStack {
private:
    Node* top;
    
public:
    LinkedStack() {
        top = nullptr;
    }
    
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    
    void push(string value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    string pop() {
        if (!isEmpty()) {
            Node* temp = top;
            string value = temp->data;
            top = top->next;
            delete temp;
            return value;
        }
        return "";
    }
    
    string peek() {
        if (!isEmpty()) {
            return top->data;
        }
        return "";
    }
    
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class BrowserHistory {
private:
    LinkedStack backward;
    LinkedStack forward;
    string currentPage;

public:
    BrowserHistory(string homepage) {
        currentPage = homepage;
    }
    
    void visit(string url) {
        if (currentPage != "") {
            backward.push(currentPage);
        }
        currentPage = url;
        while (!forward.isEmpty()) {
            forward.pop();
        }
    }
    
    string back() {
        if (!backward.isEmpty()) {
            forward.push(currentPage);
            currentPage = backward.pop();
        }
        return currentPage;
    }
    
    string goforward() {
        if (!forward.isEmpty()) {
            backward.push(currentPage);
            currentPage = forward.pop();
        }
        return currentPage;
    }
    
    string getCurrentPage() {
        return currentPage;
    }
};

struct QueueNode {
    string name;
    QueueNode* next;
    
    QueueNode(string n) {
        name = n;
        next = nullptr;
    }
};

class BankQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;

public:
    BankQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    
    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        return false;
    }
    
    void enqueue(string n) {
        QueueNode* newNode = new QueueNode(n);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size = size + 1;
        cout << n << " joined the queue" << endl;
        cout << "Queue size " << size << endl;
    }
    
    string dequeue() {
        if (isEmpty()) {
            cout << "No customers in queue." << endl;
            return "";
        }
        QueueNode* temp = front;
        string n = temp->name;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size = size - 1;
        cout << n << " done & Queue size " << size << endl;
        return n;
    }
    
    int getSize() {
        return size;
    }
    
    ~BankQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    BankQueue bankQueue;
    bankQueue.enqueue("lol");
    bankQueue.enqueue("Boba");
    bankQueue.enqueue("Cici");
    bankQueue.dequeue();
    bankQueue.enqueue("Dodo");
    bankQueue.dequeue();
    
    return 0;
}