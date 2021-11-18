# TC1031.2_Integral-B

Este es un programa planeador de rutas de viajes dentro de la republica Mexicana. El programa utiliza un grafo 
para calcular la ruta mas rapida desde un estado a otro (Escogue la ruta que recorra menos estados). Ademas de 
esto el usuario tambien pude consultar que otros estados colindancon cualquier otro.


# SICT0302B: Toma decisiones

Usa grafos para hacer analisis de información: 
Decidi guardar la informacion en un grafo no direccionado ya que cada estado del pais tiene multiples relaciones con 
otros estados, siendo su colindancia. El grafo no direccionada me permite guardar dichas relaciones sin tener ninguna
restriccion en la manera en que el usuario se mueve entre ellos.

Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema :
El algoritmo de busqueda que utilizo es un breadth first search. Escogui este algoritmo ya que es el algoritmo que me 
permite encontrar la ruta mas sencilla entre origen y destino.


# SICT0301B: Evalúa los componentes

Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa:

Los casos de pruebas para todas las funciones se encuentran en "casos_de_prueba.hpp" donde se prueban las funciones:
BFS y printAdjList. Dentro de dichas funciones se encuentran la mayoria de las funciones. Ademas, tambien se crea un
objeto de tipo Graph y dentro de su constructor se prueban las funciones faltantes. 
    
    
Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes:

Clase Graph

    fillEstados: fill estados es una funcion que se encarga de llenar un vector de string con los estados de la republica. 
    Esto para relacionar los numeros del grafo con los estados de Mexico. Como tiene que llenar todo el vector de relacion 
    completo esta funcion es de complejidad o(n).
    
    loadGraphList: Esta funcion se encarga de leer un archivo de texto para hacer las relaciones de cada nodo del grafo.
    Como la funcion tiene que realizar todas las relaciones de los nodos su complejidad es de o(n).
    
    addEdgeAdjList: Esta funcion se encarga de marcar la relacion entre dos nodos. Es de complejidad o(1).
    
    printAdjList: 
    
    BFS:
    
    breadthHelper:
    
    contains:
    
    print_path:
    
    listEstados:
    
    
# SICT0303B: Implementa Acciones Cientificas

Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa:
Dentro del programa se implementan mecanismo para ver las colindancias de cada estado (relacion entre nodos). Ademas si se quisieran
consultar las colindancias de un estado en especifico tambien se puede.

Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
El programa lee el archivo colinda.txt y este archivo de texto se encarga de hacer todas las conexiones de los nodos del grafo.

