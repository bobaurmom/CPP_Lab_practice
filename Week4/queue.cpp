#include <iostream>
using namespace std;

class Node {
    public:
    string name;
    Node *next;
    Node ( string value){
        name = value;
        next = nullptr;
    }
};
class Queue{
    private:
        Node *back ,*front;
        int size;
    public:
    Queue(){
        front = back = nullptr;
        size =0;
    }
    void enqueue (string value){
        Node * newNode = new Node(value);
        if (size ==0||front== nullptr){
            front = newNode;
            back = newNode;
        }else{
            back -> next = newNode;
            back = newNode;
        }
        size ++;

    }
    string dequeue(){
        if (size ==0 || front == nullptr) {
            cout << "empty" << endl;
        }
        Node* temp = front;
        string value = temp->name;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
        cout<<"delete"<< temp->name<< endl;
        size--;
        return value;

    }
    bool isEmpty(){
        if (front == nullptr || size ==0){
            cout<< "is empty"<< endl;
            return true;
        }else{
            cout << "not empty"<< endl;
            return false;
        }

    }
    bool search (string name){
        Node *temp = front;
        if (front == nullptr){
            cout<<"empty"<<endl;
            return false;
        }
        while (temp){
                if (temp->name == name){
                cout << name << " found in the queue." << endl;
                return true; 
            }
            temp = temp->next;
        }
        cout << name << "not found in the queue." << endl;
        return false; 
        }

    
    void print(){
        if ( front == nullptr || size == 0){
            return;
        }else {
            Node* current = front;
            while (current != nullptr) {
                cout << current->name<<"<-";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q;
    q.isEmpty();
    q.enqueue("hello");
    q.enqueue("hi");
    q.enqueue("how are you");
    q.dequeue();
    q.print();
    q.isEmpty();
    q.search("hi");

    return 0;
}
