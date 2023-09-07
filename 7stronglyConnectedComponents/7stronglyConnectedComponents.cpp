#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int V;
    list<int>* edge;
    list<int>* adjList;
    stack<int> Stack;

    // constructor
    public:
    Graph (int V){
        this->V = V;
        adjList = new list<int>[V];
    }

    // add edge into graph
    void addEdge(int vertex1, int vertex2){
        adjList[vertex1].push_back(vertex2);
    }

    // traverse the tree in DFS: push to stack
    void findOrder(int vertex, bool visited[]){
        visited[vertex] = true;

        list<int>:: iterator i;
        for (i=adjList[vertex].begin(); i!= adjList[vertex].end(); ++i){
            if( visited[*i] !=true) {
                findOrder(*i, visited);
            }
        }

        Stack.push(vertex);
    }

    // transpose the edge
    list<int>* transposeEdge(list<int>* orginalEdge){
        list<int>* transposedEdge = new list<int>[V];

        for (int i = 0; i < V; i++){
            list<int>:: iterator j;
            for (j=orginalEdge[i].begin(); j!= orginalEdge[i].end(); ++j){
                transposedEdge[*j].push_back(i);
            }
        }

        return transposedEdge;
    }

    //DFS
    void DFS(int vertex, bool* visited){        

        visited[vertex] = true;

        list<int>:: iterator i;
        for (i = adjList[vertex].begin(); i != adjList[vertex].end(); ++i){
            if( visited[*i] != true){
                DFS(*i, visited);
            }
        }

        cout << vertex <<endl;
    }

    // printSCC
    void printSCC(){
        
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++){
            visited[i] = false;
        }

        findOrder(0, visited);

        adjList = transposeEdge(adjList);

        

        for (int i = 0; i < V; i++){
            visited[i] = false;
        }

        while(Stack.empty() != true){
            int topVertex = Stack.top();

            if(visited[topVertex] == true) Stack.pop();
            else{
                cout << "SCC is " << endl;
                DFS(topVertex, visited);
                cout <<endl;
            }
        }       
    }
};

int main() {
  Graph g(8);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 0);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  g.addEdge(6, 4);
  g.addEdge(6, 7);

  cout << "Strongly Connected Components:\n";
  g.printSCC();
}