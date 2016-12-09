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
#include <unistd.h>

//Global Variables


typedef std::map<std::string, std::vector<std::string>>::iterator it;
int n = 5;
int s = 100;
std::string baddr = "cnn.com";
std::string raddr = "cnn.com";
bool b = false;
bool r = false;

class Graph{
	public:
		Graph();
		void BFS();
		void randomWalk();
		void printSuggest(std::map<std::string, int>);
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

void Graph::BFS(){
	std::queue<it> q;
	it addr = graph.find(baddr);
	q.push(addr);
	int prev = 1;
	int next = 0;
	std::map<std::string, int> suggest;
	while(!q.empty()){
		it curr= q.front();
		q.pop();
		next = next+curr->second.size();

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
			n--;
		}
		if(n < 0){
			printSuggest(suggest);
			break;
		}
		for(size_t i = 0; i < curr->second.size(); i++){
			std::string tmp = curr->second[i];
			it tmpIT = graph.find(tmp);
			q.push(tmpIT);
		}
	}
}

void Graph::randomWalk(){
	std::map<std::string, int> rand;
	it addr = graph.find(raddr);
	if (addr == graph.end()){
		return;
	}
	std::string previous = raddr;
	for(int i = 0; i < s; i++){
		size_t num = addr->second.size();
		std::string temp;
		if(num == 0){
			temp = previous;
		}
		else{
			temp = addr->second[get_random(num)];
		}
		it next = graph.find(temp);
		std::cout <<temp<<std::endl;
		if(next != addr){
			auto search = rand.find(temp);
			if(search != rand.end()){
				rand[temp]++;
			}
			else{
				rand[temp] = 1;
			}
		}
		previous = addr->first;
		addr = next;
	}
	std::cout<<"------------"<<std::endl;
	printSuggest(rand);
}

void Graph::printSuggest(std::map<std::string,int> s){
	for(auto i = s.begin(); i != s.end(); i++){
		std::cout<<i->second<<" "<<i->first<<std::endl;
	}
}

int Graph::get_random(int size){
	std::random_device rd;
	std:: default_random_engine g(rd());
	std::uniform_int_distribution<int> d(0, size-1);
	return d(g);
}

//Non-class functions
void usage(int status){
	std::cout<<"usage: honeybee.cpp"<<std::endl;
	std::cout<<"	-b BADDR	BST for the address BADDR"<<std::endl;
	std::cout<<"	-r RADDR	Run random walk for the address RADDR"<<std::endl;
	std::cout<<"	-n N		number of levels to traverse for BST"<<std::endl;
	std::cout<<"	-s S		number of steps to take when random walking"<<std::endl;
}

void parse(int argc, char *argv[]){
	int c;
	while ((c = getopt(argc, argv, "hb:r:n:s:")) != -1){
		switch (c){
			case 'b':
				b = true;
				baddr = optarg;
				break;
			case 'r':
				r = true;
				raddr = optarg;
				break;
			case 'n':
				n = std::atoi(optarg);
				break;
			case 's':
				s = std::atoi(optarg);
				break;
			case 'h':
				usage(0);
				break;
			default:
				usage(1);
				break;
		}
	}
}

int main(int argc, char *argv[]){
	parse(argc, argv);
	Graph myGraph;
	if(b){
		myGraph.BFS();
	}
	if(r){
		myGraph.randomWalk();
	}
	return 0;
}
