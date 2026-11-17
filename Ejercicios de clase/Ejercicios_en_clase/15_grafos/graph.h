/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*		Nota: Esta imlpementación es Top Down, no divide al árbol para la operacións
*		de barrado
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    vector<int> *adjList;
		int *adjMatrix;
		//vector<Type> *vect = new vector<Type>

public:
		Graph(int);
		Graph();
		void addEdgeAdjList(int, int);
		void addEdgeAdjMatrix(int, int);
		string printAdjList();
		string printAdjMat();
		string printAdjMat_clean();
		string DFS(int, int);
		string depthHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&);
		string BFS(int, int);
		string breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&);
		string print_visited(list<int>);
		string print_path(vector<vector<int>>&,int ,int);
		bool contains(list<int>, int);
		void sortAdjList();
		void loadGraphList(string, int, int);
		void loadGraphMat(string, int, int);
};


void Graph::loadGraphList(string name, int a, int b){
	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee (name);
	int u, v;
	if (lee.is_open()){
		while (getline(lee, line)){
			u = stoi(line.substr(1,1));
			v = stoi(line.substr(4,1));
			addEdgeAdjList(u,v);
		}
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file";
	}
	sortAdjList();
}

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

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

string Graph::printAdjList(){
	  stringstream aux;
		for (int i = 0; i < nodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

void Graph::sortAdjList(){
	for (int i = 0; i < nodes; i++)
		sort(adjList[i].begin(),adjList[i].end());
}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}

string Graph::DFS(int start, int goal){
	stack<int> pila;
	list<int> visitados;
	vector <vector<int>> caminos(nodes, vector<int>(1, -1));
	pila.push(start);
	string result = "visited: " + to_string(start) + " " + depthHelper(start, goal, pila, visitados, caminos);
	result = result + print_path(caminos, start, goal);
	return result;
}

string Graph::depthHelper(int current,
							int goal,
							stack<int> &st,
							list<int> &visited,
							vector<vector<int>> &paths){
	if (!st.empty()) {
		//std::cout << "current: " << current << std::endl;
		visited.push_front(current);
		//paths[current][0] = st.top();
		if (current == goal) {
			return "";
		} else {
			st.pop();
			for (int i = 0; i < nodes; i++) {
				if (adjMatrix[current*nodes + i] == 1 && !contains(visited,i)) {
					st.push(i);
					paths[i][0] = current;
					//std::cout << "push: " << i << std::endl;
				}
			}
			current = st.top();
			return to_string(current) + " " + depthHelper(current, goal, st, visited, paths);
		}
	} else {
		return " node not found";
	}
}

string Graph::BFS(int start, int goal){
		return "";
}

string Graph::breadthHelper(int current,
															int goal,
															queue<int> &qu,
															list<int> &visited,
															vector<vector<int>> &paths){

			return " node not found";
}


bool Graph::contains(list<int> ls, int node){
		list<int>::iterator it;
		it = find(ls.begin(), ls.end(), node);
		if(it != ls.end())
			return true;
		else
			return false;
}

string Graph::print_visited(list<int> q){
	stringstream aux;
	aux << "visited: ";
	while (!q.empty()){
    aux << q.front() << " ";
    q.pop_front();
  }
	return aux.str();
}

string Graph::print_path(vector<vector <int>> &path, int start, int goal){
	int node = path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	stringstream aux;
	aux  << "path:";
	while (node != start) {
		reverse.push(node);
    	node = path[node][0];
  	}
	reverse.push(start);
	while (!reverse.empty()) {
		aux << " " << reverse.top() ;
		reverse.pop();
  	}
	return aux.str();
}
#endif /* Graph_H_ */
