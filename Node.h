#pragma once
#include <string>;
#include <iostream>;
#include <vector>;
#include <iterator>;
using namespace std;

class Node
{
private: string name;
private: vector <Node> adj;//смежные вершины
private: vector <Node> passedAdj;//пройденные смежные вершины


public:Node(string name) {
	this->name = name;
}
public: void addPassedAdj(Node& node)
{
	passedAdj.push_back(node);
}
public: bool equals(Node n) {
	//if (adj.size()==n.getAdj().size()) {
	//	//auto iteradj = adj.begin();
	//	int c;
	//	for (Node an : adj) {
	//		c = 0;
	//		for (Node ad : n.getAdj()) {
	//			if (an.getName() == ad.getName() || n.getName()== an.getName()) {
	//				c++;
	//			}
	//		}
	//		if (c == 0)
	//			return false;	
	//	}
	//}
	//else {
	//	return false;
	//}
	if (n.getName() == name)return true;
		//				c++;
		//			}
	return false;
}
public: string getName() {
	return name;
}
public: void addAdj(Node& node)
{
	adj.push_back(node);
}

public: vector<Node> getPassedAdj() {
	return passedAdj;
}
public: vector<Node> getAdj() {
	return adj;
}
};

