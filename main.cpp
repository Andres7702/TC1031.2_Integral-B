//Andrés Acevedo Caracheo
//Este es un programa planeador de rutas de viajes dentro de la republica Mexicana.
//El programa utiliza un grafo para calcular la ruta mas rapida desde un estado a
//otro (Escogue la ruta que recorra menos estados). Ademas de esto el usuario tambien
//puede consultar las colindancias de cualquier estado.

#include <iostream>
#include <cstring>
#include "graph.hpp"
#include "Casos_de_prueba.hpp"

using namespace std;

//Menu de opciones del programa principal
void menu(){
    cout<<"\n";
    cout<<"1. Ruta de viaje. \n";
    cout<<"2. Colindancias de Estado. \n";
    cout<<"3. Colindancias de todos los Estados. \n";
    cout<<"4. CASOS DE PRUEBA. \n";
    cout<<"\n";
}

void add_historial(string historial){
    std::ofstream archivo;

    archivo.open("Historial.txt");
    if( archivo ) {
        archivo << "Rutas pasadas:";
        for (int i = 0; i < historial.size(); ++i)
        archivo << historial[i];
        archivo.close();
    }
    else{
        cout << "Error: No se pudo guardar el historial" << endl;
    }
}

int main() {
    
    string historial;

    Graph Mexico;
    
    while(true){
        int opcion;
        
        menu();
        cin>>opcion;
        cout<<"\n";
        
        //OPCION 1 Enseña ruta mas corta de un estado a otro.
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
                string ruta;
                cout<<"Ruta sugerida: \n";
                ruta = Mexico.BFS(origen,destino);
                cout<<ruta;
                cout<<"\n";
                
                historial += "\n \n";
                historial += ruta;
                
                add_historial(historial);
                
            }
            else{
                cout<<"Error: Tu origen y/o destino no son validos. \n";
            }
        }
        //OPCION 2 imprime las colindancias de un estado solicitado
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
        //Imprime las colindancias de todos los estados
        else if (opcion == 3){
            cout<<Mexico.printfullAdjList();
        }
        //Casos de prueba
        else if(opcion == 4){
            casosPrueba();
        }
        //Opcion no valida
        else{
            cout<<"Error: Tu opcion no es valida. \n";
        }
    }
}
