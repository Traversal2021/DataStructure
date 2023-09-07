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
        if(front == 0 && rear == QUEUESIZE - 1){
            return true;
        }
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
            rear ++;
            items[rear] = element;
        }
    }

    int deQueue(){
        if(isEmpty()){
            cout << "QUEUE EMPTY" << endl;
            return -1;
        }else{
            int element = items[front];
            if(front == QUEUESIZE -1){
                front =-1;
                rear = -1;
            }else{
                front ++;
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
            for (int i = front; i <= rear; i++)
                cout << items[i] << "  ";
            cout << endl
                << "Rear index-> " << rear << endl; 
        }
    }

};

int main() {
  Queue q;

  //deQueue is not possible on empty queue
  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6th element can't be added to because the queue is full
  q.enQueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();

  //Now we have just 4 elements
  q.display();

  return 0;
}