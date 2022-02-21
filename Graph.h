#pragma once
#include <list>
#include "Node.h";
#include <iostream>;

class Graph
{
private:vector<Node> nodes;

public: bool depthFirstSearch(Node n,Node findN) {
	
	int c;
	for (Node adj : n.getAdj())
	{
		//проверка что не помеченное ребро
		c = 0;
		for (Node pn : n.getPassedAdj())
		{
			if (adj.equals(pn)) {
				c++;
			}
		}
		if (c==0) {
			//конец проверки
			
			// надо сначала проверить есть ли элемент соседний равен искомому
			// потом заходить в элемент и искать в нем

			if (!adj.equals(findN)) {// здесь сразу ищется, надо переделать
				addPassedAdj(adj, n);
				depthFirstSearch(adj, findN);
			}
			else {
				return true;
			}
		}
	}
	return false;
}

private: bool checkOnPass(Node n, Node adj) {
		for (Node pn : n.getPassedAdj())
		{
			if (!adj.equals(pn)) {
				return true;
			}
		}
		
	return false;
}

public: void addAdj(Node& n1, Node& n2) {
	n1.addAdj(n2);
	n2.addAdj(n1);
}
public: void addPassedAdj(Node& n1, Node& n2)
{
	n1.addPassedAdj(n2);
	n2.addPassedAdj(n1);
}
public: void addNode(Node node)
{
	nodes.push_back(node);
}

public: vector<Node> getAllNodes() {
	return nodes;
}

public: void printNodes() {
	for (Node node : nodes) {
		cout << "Point " << node.getName() << " Roads to:[(";
		for (Node adj : node.getAdj())
		{
			cout << adj.getName() << ", ";
		}
		cout << ") passed (";
		for (Node adj : node.getPassedAdj())
		{
			cout << adj.getName() << ", ";
		}
		cout << ")] ";
	}
}
};

