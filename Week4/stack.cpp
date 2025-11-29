#include <iostream>
using namespace std;

class Node{
    public:
    int num ;
    Node * next;
    Node (int value){
        num = value;
        next = nullptr;
    }
};
class stack{
    private:
        Node *top ;
        int size;
    public:
    stack(){
        top = nullptr;
        size = 0;
    }
    void push(int value){
        size++;
        Node * newNode = new Node(value);
        if(top == nullptr){
            top = newNode;
        } else {
            newNode -> next = top;
            top = newNode;
        }
    }
    void pop(){
        if (top == nullptr){
            cout<<"overflow"<<endl;
        }else {
            Node * temp = top;
            top = top-> next;
            delete temp;
        }
    }

    void print(){
        if (size==0 || top ==nullptr){
            cout<<"nothing to print"<<endl;
            return;
        }else{
            Node * current = top;
            while (current != nullptr){
                cout<<current->num<<endl;
                current = current -> next;
            }
        }
    }
    ~stack(){
        while (top!= nullptr){
            pop();
        }
        cout<<"stack has been cleared from memories";
    }


};



int main(){
    stack st;
    st.push(12);
    st.push(24);
    st.push(80);
    cout<<"before pop:"<<endl;
    st.print();
    st.pop();
    cout<<"after pop:"<<endl;
    st.print();

    return 0;
}