// IMP-task1-number12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graph.h";
using namespace std;
int main()
{
    cout << "Hello World!\n";

    Graph g;

    Node a = *new Node("A");
    Node b = *new Node("B");
    Node c = *new Node("C");
    Node d = *new Node("D");
    Node z = *new Node("Z");

    g.addAdj(a,c);
    g.addAdj(a,d);
    g.addAdj(a,z);

    g.addAdj(c,z);
    g.addAdj(c,d);
    g.addAdj(c,b);

    g.addAdj(d,b);

    g.addAdj(z,b);

    g.addPassedAdj(a,d);
    g.addPassedAdj(b,d);
    g.addPassedAdj(c,d);

    //добавляем ноды в граф хз зачем
    g.addNode(a);
    g.addNode(b);
    g.addNode(c);
    g.addNode(d);
    g.addNode(z);
    cout <<g.depthFirstSearch(a,b);
    
    g.printNodes();
}
