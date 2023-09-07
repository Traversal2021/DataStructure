#include <stdlib.h>
#include<list>
#include <iostream>
using namespace std;

class HashTable{
    int capacity;
    list<int>* table;
    
    public:
    HashTable(int V){
        int size = getPrime(V);
        capacity = size;
        cout << "Capacity is " << capacity << endl;
        table = new list<int>[capacity];
    }

    void insertItem(int key, int data){
        int index = hashFuction(key);
        table[index].push_back(data);
        // cout << "key is "<< key << endl;
        // cout << "index is "<< index << endl;
        // cout << "data is " << data << endl;
        // cout << endl;
    }
    
    void deleteItem(int key){
        int index = hashFuction(key);

        list<int>:: iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++){
            if (*i == key)
            break;
        }

        if(i != table[index].end()) table[index].erase(i);

    }

    int hashFuction(int key){
        return (key % capacity);
    }

    void displayHash(){
        for (int i = 0; i < capacity; i++)
        {
            cout << "table[" << i << "]";
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }

    int checkPrime(int n){
        int i;
        if(n == 1 || n ==0){
            return 0;
        }
        for (i = 2; i<n/2; i ++){
            if( n % i == 0){
                return 0;
            }
        }
        return 1;
    }

    int getPrime(int n){
        if(n % 2 == 0){
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }
};

int main()
{
  int key[] = {231, 321, 212, 321, 433, 262};
  int data[] = {123, 432, 523, 43, 423, 111};
  int size = sizeof(key) / sizeof(key[0]);
  cout << "size is " << size << endl;

  HashTable h(size);

  for (int i = 0; i < size; i++)
  h.insertItem(key[i], data[i]);

  h.deleteItem(12);
  h.displayHash();
}