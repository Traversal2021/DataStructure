#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 5

int queueSize = 0;

struct queue{
    int items[MAX];
    int first;
    int rear;
};
typedef struct queue qu;

// build an empty queue
void createEmptyQueue(qu* q){
    q->first = -1;
    q->rear = -1;
}

//IsEmpty
int isEmpty(qu* q){
    if(q->rear == -1){return 1;}
    else {return 0;}
}

//IsFull
int isFull(qu* q){
    if(q->rear - q->first == MAX-1) return 1;
    else return 0; 
}

// Enqueue
void enqueue(qu* q, int newItem){
    if(isFull(q)){
        cout << "QUEUE FULL";
    }else{
        if(isEmpty(q)){
            q->first ++;           
        }
        q->rear++;
        q->items[q->rear] = newItem;
    }

}

// Dequeue
void dequeue(qu* q){
    if(isEmpty(q)){
        cout << "QUEUE EMPTY";
    }else{
        cout << "SELECTED ITEM: " << q->items[q->first];
        q->first++;
        if(q->first > q->rear){
            q->first = -1;
            q->rear = -1;
        }
    }
}

// peek
void peek(qu* q){
    cout << q->items[q->first];
}

int main(){
    int ch;
    qu* q = (qu*)malloc(sizeof(q));

    createEmptyQueue(q);

  //deQueue is not possible on empty queue
    dequeue(q);

    //enQueue 5 elements
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);

    // 6th element can't be added to because the queue is full
    enqueue(q,6);

    peek(q);

    //deQueue removes element entered first i.e. 1
    dequeue(q);

    //Now we have just 4 elements
    peek(q);

    return 0;
}
    