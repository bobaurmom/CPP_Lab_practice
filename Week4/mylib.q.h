#include <stdio.h>
#include "queue.cpp"



int main(){
    Queue q;
    q.isEmpty();
    q.enqueue("hello");
    q.enqueue("hi");
    q.enqueue("how are you");
    q.dequeue();
    q.print();
    q.isEmpty();

    return 0;
}