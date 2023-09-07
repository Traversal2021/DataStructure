#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10

struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

int stacksize = 0;

void createEmptyStack (st* s){
    s->top = -1;
    stacksize=0;
}

int isfull(st* s){
    if (s->top == MAX -1) return 1; 
    else return 0;
}

// Check if the stack is empty
int isEmpty(st* s){
    if (s->top == -1) return 1;
    else return 0;
}

// Add elements into stack
void push(st* s, int newItem){
    if(isfull(s)){
        cout << "STACK FULL";
    }else{
        s->top ++;
        s->items[s->top] = newItem;
    }
    stacksize++;
}

// Remove element from stack
void pop(st* s){
    if(isEmpty(s)){
        cout << "STACK EMPTY";
    }else{
        cout << "Item poped = " << s->items[s->top];
        s->top--;
    }
    stacksize--;
}

// Print elements of stack
void printStack(st* s){
    printf("The stack is:");
    for (int i = stacksize-1; i>=0; i--){
        cout << s->items[i];
    }
}

// Driver code
int main(){
    int ch;
    st* s = (st *)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);
}