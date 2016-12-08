/*
Read all input from webcrawl into nodes
Give a certain address, breadth first search for a pointer to a node with the same
address

./a.out < KyInput.txt | sort -r | head -n 5 | cut -b 3-
???
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <random>
#include <string>

typedef std::map<std::string, std::vector<std::string>>::iterator it;

class Graph{
	public:
		Graph();
		void BFS(std::string, int); // rethink this
//		it randomWalk(it, size_t);
		void printSuggest(std::map<std::string,int>);
		int get_random(int);

	private:
		std::map<std::string,std::vector<std::string>> graph;
};

Graph::Graph(){
	std::string tmp1, tmp2;
	while(std::cin >> tmp1 >> std::ws >> tmp2){
		graph[tmp1].push_back(tmp2);\
		if(graph.find(tmp2) ==graph.end()){
			graph[tmp2].clear();
		}
	}
}

void Graph::BFS(std::string address, int levels){
	std::queue<it> q;
	it addr = graph.find(address);
	if(addr == graph.end()){
//		std::cout << "address not found" <<std::endl;
	}
	q.push(addr);
	int prev = 1;
	int next = 0;
	std::map<std::string, int> suggest;
	while(!q.empty()){
		it curr= q.front();
		q.pop();
		next = next+curr->second.size();

//		std::cout<<curr->first<<" "<<levels<<" "<<prev<<" "<<next<<std::endl;
		if(suggest.find(curr->first) != suggest.end()){
			suggest[curr->first]++;
		}
		else{
			suggest[curr->first] = 1;
		}
		prev--;
		if(prev == 0){
			prev = next;
			next = 0;
			levels--;
		}
		if(levels < 0){
			printSuggest(suggest);
			break;
		}
		for(size_t i = 0; i < curr->second.size(); i++){
			std::string tmp = curr->second[i];
			it tmpIT = graph.find(tmp);
			if(tmpIT == graph.end()){
//				std::cout <<"address not found"<<std::endl;
			}
			q.push(tmpIT);
		}
	}

}
/*
it Graph::randomWalk(it n, size_t degrees){
	map<string,int> m;
	for(size_t i = 0; i < degrees; i++){
		Node tmp = n.neighbors[i]
		if(n.address != tmp.address){
			auto it = m.find(tmp.address);
			if(it != m.end()){
				it.second++;
			}
			else{
				m[tmp.address] = 1;
			}
		}
	}
}
*/

void Graph::printSuggest(std::map<std::string,int> s){
	for(auto i = s.begin(); i != s.end(); i++){
		std::cout<<i->second<<" "<<i->first<<std::endl;
	}
}

int Graph::get_random(int n){
	std::random_device rd;
	std:: default_random_engine g(rd());
	std::uniform_int_distribution<int> d(0, n-1);
	return d(g);
}

int main(){
	Graph myGraph;
	myGraph.BFS("swagmaster",4);
	return 0;
}
