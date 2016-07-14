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

int main () {
    // 
}
