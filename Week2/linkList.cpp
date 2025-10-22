#include <iostream>
using namespace std;
//2.1
class student {
public:
    string name;
    int id;
    string major;
    student *next;
    student(const string &n, int i, const string &m)
        : name(n), id(i), major(m), next(nullptr) {}
    student(const string &n, int i)
        : name(n), id(i), major(""), next(nullptr) {}
};
class linkedList{ 
public:
    student *head;
    linkedList(){ 
        head = nullptr;
    }
    //2.2
    void insertatbeggining(const string &n, int i, const string &m){
        student *newStudent = new student(n,i,m); 
        if (head == nullptr){
            head = newStudent;
        }
        else{
            student *temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newStudent;
        }
       
    }
    //2.3
    int count(){
        int count = 0;
        student * temp = head;
        while (temp != nullptr){
            count++;
            temp = temp-> next;
        }
        return count;
    }
    //2.4
    bool search (const int i){
        student * temp = head;
        while (temp != nullptr){
            if (temp->id == i){

                return true;
            }
            temp = temp-> next;
        }
        return false;
    }
    //2.5
    void deleteAtFirst(){
        if (head == nullptr){
            return;
        }
        student *temp = head;
        head = head->next;
        delete temp;
    }
    //bonus
    void deleteAtLast(){ 
        if (head == nullptr){
            return;
        }
        if (head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        student *temp = head;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    };
    void deleteAll(){
        if (head == nullptr){
            return;
        }
        student *temp = head;
        while (temp != nullptr){
            student *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = nullptr;
    };
    void print(){
        student * temp = head;
        while (temp != nullptr){
            cout << "Name: " << temp->name << " ID: " << temp->id << " Major: " << temp->major << "\n";
            temp = temp-> next;
        }
    }
};


int main(){
    linkedList list;
    list.insertatbeggining("kikki", 1, "CS");
    list.insertatbeggining("kaka", 2, "SE");
    list.insertatbeggining("koko", 3, "TN");
    list.insertatbeggining("kuku", 4, "IT");
    list.print();
    cout << "Count: " << list.count() << "\n";
    if (list.search(3)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }
    list.deleteAtFirst();
    list.print();
    list.deleteAtLast();
    list.print();

    return 0;
}
