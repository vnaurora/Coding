#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
public:
    Graph(int vertexNums) : mVertexNums(vertexNums)
    {
        mEdge = new list<int>[mVertexNums];
    }
    ~Graph()
    {
        delete[] mEdge;
    }
    void AddEdge(int i, int j)
    {
        mEdge[i].push_back(j);
    }
    void BFS(int s); //Breadth First Search start with node s

    void DFS(int s); //Depth First Search start with node s

private:
    int mVertexNums;
    list<int>* mEdge;
};

void Graph::BFS(int s)
{
    vector<bool> visited(mVertexNums, false);

    queue<int> q;

    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (auto i = mEdge[v].begin(); i != mEdge[v].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
    cout << std::endl;
    return;
}

void Graph::DFS(int s)
{
    vector<bool> visited(mVertexNums, false);
    stack<int> stk;
    visited[s] = true;
    stk.push(s);

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        cout << v << " ";

        for (auto i = mEdge[v].begin(); i != mEdge[v].end(); i++) {
            if (!visited[*i]) {
                stk.push(*i);
                visited[*i] = true;
            }            
        }
    }
    cout << std::endl;
    return;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
    g.AddEdge(3, 1);
    g.AddEdge(3, 0);
    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "Following is Depth First Traversal "
        << "(starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
