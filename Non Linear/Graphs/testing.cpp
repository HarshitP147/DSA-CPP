#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;


template <typename T>
class Graph{
	map<T,vector<T>> adjList;

	public:
		void addEdge(T x,T y,bool isBidir=true){
			if(adjList.find(x)==adjList.end()){
				adjList[x] = {};
			}
			else if(adjList.find(y)==adjList.end()){
				adjList[y] = {};
			}
			adjList[x].push_back(y);
			if(isBidir){
				adjList[y].push_back(x);
			}
		}

		void breadthFirstSearch(T s){
			// s is the starting vertex
			if(adjList.find(s)==adjList.end()){
				cout << s << " vertex is not present in the graph!!" << endl;
			}
			else{
				queue<T> q;
				vector<T> visited;

				q.push(s);

				while(!q.empty()){
					
				}
			}
		}
};
