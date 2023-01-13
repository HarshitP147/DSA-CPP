#include <iostream>
#include <map>
#include <list>
using namespace std;

struct Graph{
	map<string,list<pair<string,int>>> l;

	void addEdge(int x,int y,bool bidir,int cost){
		l[x].push_back(make_pair(y,cost));
		if(bidir){
			l[y].push_back(make_pair(x,cost));
		}
	}

	
}

int main(){
	


	return 0;
}