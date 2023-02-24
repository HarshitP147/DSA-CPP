#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;


template <typename T>
class Graph{
	map<T,vector<T>> adjList;

	public:
		void addEdge(T x,T y,bool isBidir=true){
			if(adjList.find(x)==adjList.end()){
				adjList[x] = {};
			}
			else if(adjList.find(x)==adjList.end()){
				adjList[y] = {};
			}
			adjList[x].push_back(y);
			if(isBidir){
				adjList[y].push_back(x);
			}
		}

		void depthFirstSearch(T s){
			if(adjList.find(s)==adjList.end()){
				cout << "The vertex is not present in the graph !!" << endl;
			}
			else{
				stack<T> stk;
				vector<T> visited;

				stk.push(s);
				cout << s << " ";
				visited.push_back(s);

				while(!stk.empty()){
					T top = stk.top();

					auto pos = adjList.find(top);
					if(pos!=adjList.end()){
						vector<T> nbrs = pos->second;

						if(nbrs.size()!=0){
							for(T vtx:nbrs){
								// check if vtx is in visited
								bool isPresent = false;
								for(T ele:visited){
									if(ele==vtx){
										isPresent = true;
										break;
									}
								}

								if(isPresent){
									stk.pop();
									continue;
								}
								else{
									stk.push(vtx);
									visited.push_back(vtx);

									top = stk.top();
									stk.pop();
									cout << top << " ";
									break;
								}
							}
						}
					}
				}
			}
		}
};


int main(){
	// implementing depth first search in C++

	Graph<int> g;

	g.addEdge(5,3,false);
 	g.addEdge(5,7,false);
	g.addEdge(3,2,false);
	g.addEdge(3,4,false);
	g.addEdge(4,8,false);
	g.addEdge(7,8,false);

	g.depthFirstSearch(5);


	return 0;
}