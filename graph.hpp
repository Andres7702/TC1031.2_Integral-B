
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
#include <map>

using namespace std;

//Clase grafo es la estrucutra que guarda la informacion de colindancias de todos los estados

class Graph {
private:
    //Variables
    int edgesList;
    int nodes;
    
    vector<int> *adjList;
    
    //guardaremos los estados en una estructura llamada map.
    //la llave es de tipo int y el contenido es string.
    map<int, string> estados;
    
    //Metodos de llenado
    void fillEstados();
    void addEdgeAdjList(int, int);
    void loadGraphList();

public:
    //Constructor
    Graph();
    
    //Variables
    string BFS(int,int);
    void breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&);
    
    //Metodos de impresion
    string printAdjList(int);
    string printfullAdjList();
    void print_path(vector <vector<int>>&,int,int,stringstream&);
    void listEstados();
    
    //Metodos auxiliares
    bool contains(list<int>, int);
};

//Constructor
Graph::Graph() {
    edgesList = 0;
    fillEstados();
    loadGraphList();
}

//fillEstados: llena el map asociando un estado a cada llave del 0 al 31.
void Graph :: fillEstados(){
    estados[0] = ("Baja California Sur");
    estados[1] = ("Baja California");
    estados[2] = ("Sonora");
    estados[3] = ("Chihuaha");
    estados[4] = ("Coahuila");
    estados[5] = ("Nuevo Leon");
    estados[6] = ("Tamaulipas");
    estados[7] = ("Sinaloa");
    estados[8] = ("Durango");
    estados[9] = ("Zacatecas");
    estados[10] = ("San Luis Potosi");
    estados[11] = ("Veracruz");
    estados[12] = ("Nayarit");
    estados[13] = ("Jalisco");
    estados[14] = ("Aguascalientes");
    estados[15] = ("Guanajuato");
    estados[16] = ("Queretaro");
    estados[17] = ("Hidalgo");
    estados[18] = ("Colima");
    estados[19] = ("Michoacan");
    estados[20] = ("Estado de Mexico");
    estados[21] = ("Ciudad de Mexico");
    estados[22] = ("Morelos");
    estados[23] = ("Tlaxcala");
    estados[24] = ("Puebla");
    estados[25] = ("Guerrero");
    estados[26] = ("Oaxaca");
    estados[27] = ("Chiapas");
    estados[28] = ("Tabasco");
    estados[29] = ("Campeche");
    estados[30] = ("Quintana Roo");
    estados[31] = ("Yucatan");
}

//loadGraphList: Lea archivo de texto que contiene todas las relaciones de los nodos.
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

//addEdgeAdjList: es un metodo que se encarga de registrar las relaciones de nodos
void Graph :: addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

//Imprime las relaciones (colindancias) que tiene un estado solicitado
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

//Imprime las relaciones (colindancias) de todos los estados
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

//BFS: Metodo que se encarga de la busqueda de un nodo dentro del grafo con ayuda de un queue.
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

//breadthHelper: Metodo auxiliar de BFS que se encarga de la busqueda.
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

//contains: metodo auxiliar que se encarga de checar la existencia de un nodo
//dentro de la lista contains
bool Graph::contains(list<int> ls, int node){
        list<int>::iterator it;
        it = find(ls.begin(), ls.end(), node);
        if(it != ls.end())
            return true;
        else
            return false;
}

//print_path: Metodo que se encarga de imprimir el camino que tomo el nodo de
//origen hacia su destino.
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

//ListEstados: Imprime la lista de estados que contiene el grafo. (Sirve como menu)
void Graph :: listEstados(){
    for(int i = 0; i<32; i++){
        cout << i;
        cout <<". ";
        cout << estados[i];
        cout <<"\n";
    }
}

#endif /* Graph_H_ */
