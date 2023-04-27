#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Graph{
    map<T,vector<T>> adjList;

    void addEdge(T x,T y){
        if(adjList.find(x)==adjList.end()){
            adjList[x]={};
        }
        else if(adjList.find(y)==adjList.end()){
            adjList[y]={};
        }

        adjList[x].push_back(y);
    }
};

template<typename T>
void DFS(Graph<T> &g, T node, map<T,bool> &visited, stack<T> &st) {
    visited[node] = true;
    for(auto neighbour : g.adjList[node]) {
        if(!visited[neighbour])
            DFS(g, neighbour, visited, st);
    }
    st.push(node);
}

template<typename T>
void topologicalSort(Graph<T> &g) {
    map<T,bool> visited;
    stack<T> st;

    for(auto p : g.adjList)
        visited[p.first] = false;

    for(auto p : g.adjList) {
        if(!visited[p.first])
            DFS(g, p.first, visited, st);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
	// Implementing Topological Sorting using Depth first search in C++
	// Although Topological Sorting is a different type of sorting than the other types of sort like merge sort etc
    Graph<int> g;
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 3);
    g.addEdge(3, 8);

    topologicalSort(g);

    return 0;
}
