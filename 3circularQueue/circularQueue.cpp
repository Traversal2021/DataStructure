#include <stdlib.h>
#include <iostream>

using namespace std;

#define QUEUESIZE 5

class Queue{
    private:
        int front, rear, items[QUEUESIZE];

    public:
        Queue(){
            front = -1;
            rear = -1;
        }

    bool isFull(){
        if((rear - front) == QUEUESIZE -1){
            return true;
        }
        if(front == rear +1) return true;
        return false;
    }

    bool isEmpty(){
        if(front == -1 & rear == -1){
            return true;
        }
        return false;
    }

    void enQueue(int element){
        if(isFull()){
            cout << "QUEUE FULL" << endl;
        }else{
            if(front==-1) front = 0;
            rear = (rear+1) % QUEUESIZE;
            items[rear] = element;
        }
    }

    int deQueue(){
        if(isEmpty()){
            cout << "QUEUE EMPTY" << endl;
            return -1;
        }else{
            int element = items[front];
            if(front == rear){
                front =-1;
                rear = -1;
            }else{
                front = (front +1) % QUEUESIZE;
            }
            return element;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "QUEUE EMPTY" << endl;
        }else{
           cout << endl
                << "Front index-> " << front;
            cout << endl
                << "Items -> ";
            for (int i = front; i != rear; i = (i+1)% QUEUESIZE)
                cout << items[i] << "  ";
            cout << items[rear] << "  "; 
            cout << endl
                << "Rear index-> " << rear << endl; 
        }
    }

};

int main() {
    Queue q;

    // Fails because front = -1
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enQueue(6);

    q.display();

    int elem = q.deQueue();

    if (elem != -1)
        cout << endl
        << "Deleted Element is " << elem;

    q.display();

    q.enQueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enQueue(8);

    return 0;
}