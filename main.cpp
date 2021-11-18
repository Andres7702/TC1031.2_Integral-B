

#include <iostream>
#include <cstring>
#include "graph.hpp"
#include "Casos_de_prueba.hpp"

using namespace std;

void menu(){
    cout<<"\n";
    cout<<"1. Ruta de viaje. \n";
    cout<<"2. Colindancias. \n";
    cout<<"3. CASOS DE PRUEBA. \n";
    cout<<"\n";
}

int main() {

    Graph Mexico;
    
    while(true){
        int opcion;
        
        menu();
        cin>>opcion;
        cout<<"\n";
        
        if(opcion == 1){
            int origen;
            int destino;
            
            Mexico.listEstados();
            cout<<"\n";
            cout<<"Escribe numero de origen. \n";
            cin>>origen;
            cout<<"Escribe numero de destino. \n";
            cin>>destino;
            cout<<"\n";
            
            if(destino < 32 && destino > -1 && origen < 32 && origen > -1){
                cout<<"Ruta sugerida: \n";
                cout<<Mexico.BFS(origen,destino);
                cout<<"\n";
            }
            else{
                cout<<"Error: Tu origen y/o destino no son validos. \n";
            }
        }
        else if(opcion == 2){
            int ed;
            
            Mexico.listEstados();
            cout<<"\n";
            cout<<"Escribe el numero de estado. \n";
            cin>>ed;
            cout<<"\n";
            
            if(ed < 32 && ed > -1){
                cout<<Mexico.printAdjList(ed);
                cout<<"\n";
                
            }
            else{
                cout<<"Error: Tu opcion no es valida. \n";
            }
            
        }
        else if(opcion == 3){
            casosPrueba();
        }
        else{
            cout<<"Error: Tu opcion no es valida. \n";
        }
    }
}
