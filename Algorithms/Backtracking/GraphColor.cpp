#include <bits/stdc++.h>
using namespace std;

#define graphType map<T,vector<T>>

template <typename T>
struct Graph{
    graphType adjList;

    void addEdge(T x,T y){
        if(adjList.find(x)==adjList.end()){
            adjList[x]={};
        }
        else if(adjList.find(y)==adjList.end()){
            adjList[y]={};
        }

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    graphType getAdjList() const{
        return this->adjList;
    }
};

template <typename T>
bool isSafe(graphType adjList,map<T,char> colMap,T vtx,char c){
    for(auto v:adjList[vtx]){
        if(colMap[v]==c){
            return false;
        }
    }
    return true;
}

template <typename T>
void graphColUtil(graphType adjList,map<T,char> colMap,T vtx,vector<char> colors){
    if(vtx==colMap.end()->first){
        // Base case: All the vertices have been assigned a color
        for(auto col:colMap){
            cout << col.first << ":" << col.second << endl;
        }
        cout << endl;
        return;
    }

    for(auto col:colors){
        if(isSafe(adjList,colMap,vtx->first,col)){
            colMap[vtx->first]=col;
            graphColUtil(adjList,colMap,next(vtx),colors);
            colMap[vtx->first]='0';
        }
    }
}

template <typename T>
void graphColoring(graphType adjList,vector<char> colors){
    map<T,char> colMap;
    // assigning 0 for no colors 
    for(auto node:adjList){
        colMap[node.first]='0';
    }
    graphColUtil(adjList,colMap,adjList.begin(),colors);
}

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    auto adjList = g.getAdjList();

    vector<char> colors;
    int n;
    cout << "Enter number of colors:";
    cin >> n;
    while(n--){
        char c;
        cout << "Enter color:";
        cin >> c;
        colors.push_back(c);
    }

    graphColoring(adjList,colors);

    return 0;
}
