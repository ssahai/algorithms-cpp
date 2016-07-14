#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    void init_graph();
    struct node {
        int vertex;
        int weight;
        node* next;
    };
    vector <node*> vertices;
  public:
    Graph(int n);
    void addEdge(int v1, int v2);
    void displayAdjacencyList();
};

// Initialize graph
Graph::Graph(int i) {
    n = i;
    init_graph();
}

// Initialized list of vertices.
void Graph::init_graph() {
    for(int  i=0; i<n; i++) {
        vertices.push_back(NULL);
    }
}

// Adding edge to the graph
void Graph::addEdge(int v1, int v2) {
    node *temp      = new node();
    temp->vertex    = v2;
    temp->weight    = 1;
    temp->next      = vertices[v1-1];
    vertices[v1-1]  = temp;
}

void Graph::displayAdjacencyList() {
    for(int i=0;i <n; i++) {
        cout << (i+1) << "  :-> ";
        if (vertices[i] == NULL) {
            cout << "NULL" <<endl;
        }
        else {
            node* temp = vertices[i];
            while(temp != NULL) {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            cout << "NULL" <<endl;
        }
    }
}

int menu (){
    int t;
    cout << "\nWhat would you like to do : "<<endl;
    cout << "\t1. Add edge to the graph."<<endl;
    cout << "\t2. Display the current adjacency list of the graph."<<endl;
    cout << "\t3. Exit."<<endl;
    cout << "\nEnter choice : ";
    cin >> t;
    return t;
}
int main () {
    int ch, n, x, y;
    cout << "DIRECTED GRAPHS "<<endl;
    cout << "=============== \n"<<endl;
    cout << "Number of nodes in the directed Graph : ";
    cin >> n;
    Graph g(n);
    cout << "\nINFO : Enter edges of the graph as space separated integers representing vertices.\n"<<endl;
    while(1) {
        ch = menu();
        switch (ch) {
            case 1:
                cout << "Enter edge : ";
                cin >> x >> y;
                g.addEdge(x,y);
                break;
            case 2:
                g.displayAdjacencyList();
                break;
            case 3:
                return 0;
            default:
                cout << "Wrong choice entered. "<<endl;
        }
    }
}
