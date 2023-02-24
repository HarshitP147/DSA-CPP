#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;


template <typename T>
class Graph{
	map<T,vector<T>> adjList;// creating an adjacency list for the graph

	public:
		void addEdge(T x,T y,bool isBidir=true){
			if(adjList.find(x)==adjList.end()){
				adjList[x] = {};
			}
			if(adjList.find(y)==adjList.end()){
				adjList[y] = {};
			}
			adjList[x].push_back(y);
			if(isBidir){
				adjList[y].push_back(x);
			}
		}


		void displayAdjList() const{
			for(auto const &itr : adjList){
				T key = itr.first;
				cout << key  << ": { ";
				for(auto values:itr.second){
					cout << values << " " ;
				}
				cout <<  "}" << endl;
			}
		}
};



int main(){
	// implementing graphs in C++
	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);

	g.addEdge(2,3);
	g.addEdge(2,4);

	g.addEdge(3,4);

	g.displayAdjList();


	return 0;
}