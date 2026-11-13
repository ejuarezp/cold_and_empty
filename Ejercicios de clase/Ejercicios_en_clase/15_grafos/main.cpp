/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  
*
*/

#include <iostream>
#include <cstring>
#include "graph.h"


/**

void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

**/

using namespace std;

int main(int argc, char* argv[]) {

    Graph g;
    Graph star;

    string g_ans, g_ans_2;
    string star_ans, star_ans_2;

    g.loadGraphList("g.txt", 7, 7);
    star.loadGraphList("star.txt", 5, 5);

    g.loadGraphMat("g.txt", 7, 7);
    star.loadGraphMat("star.txt", 5, 5);

    g.printAdjList();
    g_ans ="vertex 0 : 1 4 vertex 1 : 0 2 3 vertex 2 : 1 vertex 3 : 1 6 vertex 4 : 0 5 vertex 5 : 4 vertex 6 : 3 ";
    cout << " 1 " <<	(!g_ans.compare(g.printAdjList()) ? "success\n" : "fail\n");
    cout << " 1 " << g.printAdjList() << endl;

    //star.printAdjList()
    star_ans="vertex 0 : 1 2 3 4 vertex 1 : 0 2 3 4 vertex 2 : 0 1 3 4 vertex 3 : 0 1 2 4 vertex 4 : 0 1 2 3 ";
    cout << " 2 " <<	(!star_ans.compare(star.printAdjList()) ? "success\n" : "fail\n");
  //  cout << " 2 " << star.printAdjList() << endl;

    cout << g.printAdjMat() << endl;
    g_ans = "0 1 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 ";
    cout << " 3 " <<	(!g_ans.compare(g.printAdjMat()) ? "success\n" : "fail\n");
    //cout << " 3 " << g.printAdjMat() << endl;

    //star.printAdjMat()
    star_ans ="0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 ";
    cout << " 4 " <<	(!star_ans.compare(star.printAdjMat()) ? "success\n" : "fail\n");
    //cout << " 4 " << star.printAdjMat() << endl;


    //g.DFS(0,3);
    g_ans = "visited: 0 4 5 1 3 path: 0 1 3";
    g_ans_2 = "visited: 0 1 2 3 path: 0 1 3";
    cout << " 5 " <<	( (!g_ans.compare(g.DFS(0,3)) || !g_ans_2.compare(g.DFS(0,3))) ? "success\n" : "fail\n");

    //star.DFS(0,3);
    star_ans = "visited: 0 4 3 path: 0 4 3";
    star_ans_2 = "visited: 0 1 2 3 path: 0 1 2 3";
    cout << " 6 " <<	( (!star_ans.compare(star.DFS(0,3)) || !star_ans_2.compare(star.DFS(0,3)))? "success\n" : "fail\n");


    //g.BFS(0,3);
    g_ans = "visited: 0 1 4 2 3 path: 0 1 3";
    g_ans_2 = "visited: 0 4 1 5 3 path: 0 1 3";
    cout << " 7 " <<	(( !g_ans.compare(g.BFS(0,3)) || !g_ans_2.compare(g.BFS(0,3))) ? "success\n" : "fail\n");

    //star.BFS(0,3);
    star_ans = "visited: 0 1 2 3 path: 0 3";
    star_ans_2 = "visited: 0 4 3 path: 0 3";
    cout << " 8 " <<	((!star_ans.compare(star.BFS(0,3)) || !star_ans_2.compare(star.BFS(0,3))) ? "success\n" : "fail\n");

}
