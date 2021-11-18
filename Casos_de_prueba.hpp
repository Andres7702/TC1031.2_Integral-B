#include <iostream>
#include <cstring>
#include "graph.hpp"

using namespace std;

//Casos de prueba que ayudaran a saber cuando ya funciones el programa.

void casosPrueba(){
    Graph Ejemplo;

    string ans;

    
    ans ="Puebla->Oaxaca";
    cout <<"1. Ruta de Puebla a Oaxaca.";
    cout << "\n" <<"Esperada: " << ans << "\nPrograma: " << Ejemplo.BFS(24,26) << "\n";
    cout << (!ans.compare(Ejemplo.BFS(24,26)) ? "SUCCES\n" : "FAIL\n");
    cout << "\n";
    
    ans ="Yucatan->Campeche->Tabasco->Veracruz->Tamaulipas->Nuevo Leon->Coahuila->Chihuaha->Sonora->Baja California->Baja California Sur";
    cout <<"2. Ruta de Yucatan a Baja California Sur.";
    cout << "\n" <<"Esperada: " << ans << "\nPrograma: " << Ejemplo.BFS(31,0) << "\n";
    cout << (!ans.compare(Ejemplo.BFS(31,0)) ? "SUCCESS\n" : "FAIL\n");
    cout << "\n";
    
    ans ="Colima->Jalisco->Guanajuato->Queretaro";
    cout <<"3. Ruta de Colima a Queretaro.";
    cout << "\n" <<"Esperada: " << ans << "\nPrograma: " << Ejemplo.BFS(18,16) << "\n";
    cout << (!ans.compare(Ejemplo.BFS(18,16)) ? "SUCCESS\n" : "FAIL\n");
    cout << "\n";
    
    ans ="\nVeracruz colinda con :\nTamaulipas, San Luis Potosi, Hidalgo, Puebla, Oaxaca, Chiapas, Tabasco";
    cout <<"4. Colindancias de Veracruz";
    cout << "\n" <<"Esperada: " << ans << "\nPrograma: " << Ejemplo.printAdjList(11) << "\n";
    cout << (!ans.compare(Ejemplo.printAdjList(11)) ? "SUCCESS\n" : "FAIL\n");
    cout << "\n";
    
    ans ="\nSan Luis Potosi colinda con :\nNuevo Leon, Tamaulipas, Zacatecas, Veracruz, Guanajuato, Queretaro, Hidalgo";
    cout <<"4. Colindancias de San Luis Potosi";
    cout << "\n" <<"Esperada: " << ans << "\nPrograma: " << Ejemplo.printAdjList(10) << "\n";
    cout << (!ans.compare(Ejemplo.printAdjList(10)) ? "SUCCESS\n" : "FAIL\n");
    cout << "\n";

}
