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
				cout << s << " vertex is not present in the graph !!" << endl;
			}
			else{
				queue<T> q;
				vector<T> visited;

				q.push(s);

				while(!q.empty()){
					T vtx = q.back();
					cout << vtx << " ";
					q.pop();
					visited.push_back(vtx);

					auto pos = adjList.find(vtx);
					if(pos!=adjList.end()){
						vector<T> nbrs = pos->second;
						bool isPresent = false;
						for(T ele:visited){
							if(vtx==ele){
								isPresent = true;
								break;
							}
						}
						if(!isPresent){
							visited.push_back(vtx);
							q.push(vtx);
						}

					}
				}
			}
		}
};

int main(){
	// implementing breadth first search algorithm in C++

	Graph<int> g;

	g.addEdge(5,3,false);
 	g.addEdge(5,7,false);
	g.addEdge(3,2,false);
	g.addEdge(3,4,false);
	g.addEdge(4,8,false);
	g.addEdge(7,8,false);


	g.breadthFirstSearch(5);


	return 0;
}