# TC1031.2_Integral-B

Este es un programa planeador de rutas de viajes dentro de la republica Mexicana. El programa utiliza un grafo 
para calcular la ruta mas rapida desde un estado a otro (Escogue la ruta que recorra menos estados). Ademas de 
esto el usuario tambien puede consultar las colindancias de cualquier estado.


# SICT0302B: Toma decisiones

### Usa grafos para hacer analisis de información: 

Decidi guardar la informacion en un grafo no direccionado ya que cada estado del pais tiene multiples relaciones con 
otros estados, siendo su colindancia. El grafo no direccionada me permite guardar dichas relaciones sin tener ninguna
restriccion en la manera en que el usuario se mueve entre ellos.

### Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema :

El algoritmo de busqueda que utilizo es un breadth first search. Escogui este algoritmo ya que es el algoritmo que me 
permite encontrar la ruta mas sencilla entre origen y destino.


# SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa:

Los casos de pruebas para todas las funciones se encuentran en "casos_de_prueba.hpp" donde se crea un objeto tipo "Graph"
nuevo y se prueban las funciones de "BFS" y "printAdjList". Dentro de dichas funciones y dentro del constructor del 
objeto, se prueban la gran mayoria de las funciones del programa. 
Se hace una comparación entre lo imprimeso y el resultado que deberia de ser. Si los casos de prueba funcionan se 
mandara un mensaje de success y si fallan de fail.
    
    
### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes:

Main
    
    add_historial: Esta función escirbe la variable "historial", dentro del archivo "Historial.txt". La funcion
    tiene que recorrer todos los caracteres del string historial por lo que es de complejidad o(n).

Clase Graph
    
    loadGraphList: Esta funcion se encarga de leer un archivo de texto para hacer las relaciones de cada nodo del grafo.
    Como la funcion tiene que realizar todas las relaciones de los nodos su complejidad es de o(n).
    
    addEdgeAdjList: Esta funcion se encarga de marcar la relacion entre dos nodos. Es de complejidad o(1).
    
    printAdjList: Esta funcion se encarga de imprimir los estados con los que colinda el estado solicitado. Es de
    complejidad o(1) por que recorre un vertice y todos sus edges. 
    
    printfullAdjList: Esta funcion se encarga de imprimir las colindancias de todos los estados. Como recorre todos los 
    vertices y edges del grafo su complejidad es de o(n).
    
    BFS: Esta funcion como tal solo se encarga de inicializar las variables que necesitaremos para el BFS ademas de mandar
    a llamar a la funcion breadthHelper y print_paths.
    
    breadthHelper: Esta es la funcion que hace que el BFS funcione. recorre el grafo con ayuda de un queue para encontrar
    el nodo solicitado. En su peor de los casos la funcion debe de recorrer todos sus vertices y edges por lo que 
    es de complejidad o(n). En la mayoria de los casos la funcion es de o(logn) ya que el peor caso solo sucede con 
    en algunos casos especificos.
    
    contains: contains se encarga de checar que un nodo no exista ya dentro de la lista visited. en su peor caso
    tiene que recorrer la lista completa por lo que es de complejidad o(n). 
    
    print_path: print path se encarga de imprimir el camino que tomo el nodo para llegar al destino. La funcion
    recorre un parte de una lista que guarda esta informacion y en ningun caso tiene que recorrer la lista
    completa, por lo qe su complejidad es de o(logn)
    
Map
    
    fillEstados: fill estados es una funcion que se encarga de asociar valores numericos con un estado de mexico
    dentri de un map. Esto para relacionar los numeros del grafo con los estados de Mexico. Como tiene que llenar 
    el map con todos los estados esta funcion es de complejidad o(n).
    
    listEstados: Esta funcion se encarga de imprimir un listado con todos los estados que contiene el map. Su
    complejidad es de o(n).
    
    
# SICT0303B: Implementa Acciones Cientificas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa:

Dentro del programa se implementan mecanismo para ver las colindancias de cada estado (relacion entre nodos). Ademas si se quisieran
consultar las colindancias de un estado en especifico tambien se puede.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa:

El programa lee el archivo colinda.txt y este archivo de texto se encarga de hacer todas las conexiones de los nodos del grafo.

### Implementa mecanismos de escritura de archivos correctos:

En el programa cuando buscas una ruta para hacer un viaje, se hace registro dentro de una variable que se llama "historial". Esta 
variable despues es escrita en un archivo de texto llamado "Historial.txt" en donde se tendra un registro de todos los viajes
consultados.

# SEG0702A Tecnologias de Vanguardia

### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.

La estructura de datos que investigue e implemente es la de "map". Este es un contenedor asociativo que guarda datos
utilizando una combinacion de llave y valor mappeado. Puedes guardar datos utilizando una llave unica. Para consultar un dato
guardado se tiene que proporcionar la llave de dicho dato.

Yo lo implemente para que dentro de este map se guardaran todos los estados de la republica y sus llaves son valores del 0 al 31.
Cada nodo del grafo tiene un valor numerico y sus conexiones a otros nodos. Al mandar a llamar una funcion que imprima los nodos 
o sus conexiones, se pasan los valores al map para que en lugar de imprimir numeros imprima los estados.

### Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos

Al declarar esta estructura se tienen que especificar 2 tipos de datos, el de la llave y el del valor que se guardara.

Insert: 

    Para insertar un valor al mapa se tiene que usar la funcion insert. A esta funcion se le mandan dos parametros,
    el primero es el de la llave y el segundo es el del valor. Los tipos de valor tiene que coincidir con los declarados 
    originalmente. 
    
    Ejemplo:
    Estados.insert(1,"Baja California");
    
Consulta: 
    
    La consulta de datos se puede hacer de varias formas. 
    
    Una de ellas es utilizando corchectes. Para esto se escribe el nombre del mapa y dentro de los corchetes se escribe 
    la llave. El resultado es el valor guardado dentro de dicha llave. 
    
    Ejemplo:
    cout<<Estados[1]; 
    Resultado: Baja California
    
    Otra manera de consulta es utilizando un iterador. Dentro de map existen las funciones begin y end que sirven 
    para crear un iterador que sabe donde empieza el map y en donde termina. Ademas de esto tambien existen las funciones 
    first y second. First devuelve el valor de llave y second devuelve el valor guardado. Utilizando todas estas funciones 
    se puede crear un iterador que recorre el map completo, imprimiendo los valores de llave y los valores guardados.
    
    Ejemplo:
    for (std::map<char,int>::iterator it=Estados.begin(); it!=Estados.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    Resultado: 
    1 => Baja California
    2 => Guanajuato
    3 => Colima
    ...
    
Borrado:

    Para eliminar elementos del map, existe la funcion erase. Esta funcion recive como parametro la llave que se quiere 
    borrar y lo elimina del map.
    
    Ejemplo:
    Estados.erase(1)
    Resultado: 
    2 => Guanajuato
    3 => Colima
    ...

# CORRECCIONES

Con esta entrega espero demostrar las evidencias:

    Usa grafos para hacer analisis de información
    Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema
    Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
    Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes
    Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa
    Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa
    Implementa mecanismos de escritura de archivos correctos
    Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.
    Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos
    
