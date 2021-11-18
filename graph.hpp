
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
    int nodes;
    
    vector<int> *adjList;
    vector<string> estados;
    
    void fillEstados();
    void addEdgeAdjList(int, int);
    void loadGraphList();

public:
    Graph();
    
    string BFS(int,int);
    void breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&);
    
    string printAdjList(int);
    string printfullAdjList();
    void print_path(vector <vector<int>>&,int,int,stringstream&);
    void listEstados();
    
    bool contains(list<int>, int);
    void sortAdjList();
};

Graph::Graph() {
    edgesList = 0;
    fillEstados();
    loadGraphList();
}

void Graph :: fillEstados(){
    estados.push_back("Baja California Sur");
    estados.push_back("Baja California");
    estados.push_back("Sonora");
    estados.push_back("Chihuaha");
    estados.push_back("Coahuila");
    estados.push_back("Nuevo Leon");
    estados.push_back("Tamaulipas");
    estados.push_back("Sinaloa");
    estados.push_back("Durango");
    estados.push_back("Zacatecas");
    estados.push_back("San Luis Potosi");
    estados.push_back("Veracruz");
    estados.push_back("Nayarit");
    estados.push_back("Jalisco");
    estados.push_back("Aguascalientes");
    estados.push_back("Guanajuato");
    estados.push_back("Queretaro");
    estados.push_back("Hidalgo");
    estados.push_back("Colima");
    estados.push_back("Michoacan");
    estados.push_back("Estado de Mexico");
    estados.push_back("Ciudad de Mexico");
    estados.push_back("Morelos");
    estados.push_back("Tlaxcala");
    estados.push_back("Puebla");
    estados.push_back("Guerrero");
    estados.push_back("Oaxaca");
    estados.push_back("Chiapas");
    estados.push_back("Tabasco");
    estados.push_back("Campeche");
    estados.push_back("Quintana Roo");
    estados.push_back("Yucatan");
}

void Graph:: loadGraphList(){
    adjList = new vector<int>[32];
    nodes = 32;
        string line;
        ifstream myfile("colinda.txt");
        int u, v;
        if (myfile.is_open()){
        while (getline(myfile, line)){
            u = stoi(line.substr(1,2));
            v = stoi(line.substr(5,2));
            addEdgeAdjList(u,v);
        }
        myfile.close();
        } else {
            cout << "Unable to open file";
        }
}

void Graph :: addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

string Graph::printAdjList(int i){
    stringstream aux;
    string l;
    aux << "\n";
    
    aux << estados[i]<<" colinda con"<< " :"<<"\n";
    for (int j = 0; j < adjList[i].size(); j ++){
        aux << estados[adjList[i][j]]<<", ";
    }
    l = aux.str();
    l.pop_back();
    l.pop_back();
    
    return l;

}

string Graph::printfullAdjList(){
    stringstream aux;
    string l;
    aux << "\n";
    for(int i = 0; i < 32; i++){
        aux << estados[i]<<" colinda con"<< " :"<<"\n";
        for (int j = 0; j < adjList[i].size(); j ++){
            aux << estados[adjList[i][j]]<<", ";
        }
        aux<<"\n";
        aux<<"\n";
    }
    
    return aux.str();
}


string Graph::BFS(int start, int goal){
        queue <int> q;
        list <int> visited;
        stringstream aux;
        vector <vector<int>> paths(nodes, vector<int>(0));
        q.push(start);
        breadthHelper(start, goal, q, visited, paths,aux);
        print_path(paths, start, goal, aux);
        string result = aux.str();
        result.pop_back();
        result.pop_back();
        return result;
}

void Graph::breadthHelper(int c, int g, queue<int> &q, list<int> &visited, vector<vector<int>> &paths, stringstream &a){
    if(c == g){
    }
    else if (q.empty()){
        a<<" node not found";
    }
    else{
        c = q.front();
        q.pop();
        visited.push_back(c);
        for(int i = 0; i < adjList[c].size(); i++){
            if(!contains(visited, adjList[c][i])){
                q.push(adjList[c][i]);
                paths[adjList[c][i]].push_back(c);
            }

        }
        breadthHelper(c, g, q, visited, paths, a);
    }
}

bool Graph::contains(list<int> ls, int node){
        list<int>::iterator it;
        it = find(ls.begin(), ls.end(), node);
        if(it != ls.end())
            return true;
        else
            return false;
}

void Graph::print_path(vector<vector<int>> &p, int s, int g, stringstream &a){
    int node = p[g][0];
    stack<int> reverse;
    reverse.push(g);
    while(node != s){
        reverse.push(node);
        node = p[node][0];
    }
    reverse.push(s);
    while (!reverse.empty()) {
        a << estados[reverse.top()] <<"->";
        reverse.pop();
    }
}

void Graph :: listEstados(){
    for(int i = 0; i<32; i++){
        cout << i;
        cout <<". ";
        cout << estados[i];
        cout <<"\n";
    }
}

#endif /* Graph_H_ */
