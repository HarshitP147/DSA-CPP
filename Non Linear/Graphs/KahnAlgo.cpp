#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Graph{
    map<T,vector<T>> adjList;

    void addEdge(T x,T y){
        if(adjList.find(x)==adjList.end()){
            adjList[x]={};
        }
        if(adjList.find(y)==adjList.end()){
            adjList[y]={};
        }

        adjList[x].push_back(y);
    }
};

template <typename T>
vector<T> kahnAlgorithm(Graph<T> g){
    vector<T> result;
    queue<T> q;
    map<T,int> inDegree;

    // Calculate in-degree of each vertex
    for(auto node:g.adjList){
        inDegree[node.first] = 0;
    }
    for(auto node:g.adjList){
        for(auto child:node.second){
            inDegree[child]++;
        }
    }

    // Enqueue all vertices with in-degree 0
    for(auto node:g.adjList){
        if(inDegree[node.first] == 0){
            q.push(node.first);
        }
    }

    // Process vertices in queue
    while(!q.empty()){
        T u = q.front();
        q.pop();
        result.push_back(u);

        // Reduce in-degree of all neighbours of u by 1
        for(auto child:g.adjList[u]){
            inDegree[child]--;
            // Enqueue child if its in-degree becomes 0
            if(inDegree[child] == 0){
                q.push(child);
            }
        }
    }

    // Check for cycle
    if(result.size() != g.adjList.size()){
        cout<<"The graph contains a cycle"<<endl;
        result.clear();
    }

    return result;
}

int main(){
    // Implementing Kahn's Algorithm for topological sorting in C++
    // Topological sort using Depth first search is in the Sorting subfolder in Algorithm folder 
    // This algorithm only applies to Undirected edges
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);

    vector<int> sortedVtx = kahnAlgorithm(g);

    // Print the sorted vertices
    for(auto vtx:sortedVtx){
        cout<< vtx <<" ";
    }
    cout<<endl;

    return 0;
}
