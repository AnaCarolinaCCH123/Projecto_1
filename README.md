# Listas de música 
El presente código muestra como ordenar listas de múisca amplias considerando su año de publicación, simulando una playlist de música. Es así que es posible reconocer que canción es más reciente e incluir las canciones que se desean ordenar. 

#### Para complilar correctamente el programa se separaron los archivos en .cpp y .h para mejor organización, separados por clase y que no se hagan archivos tan largos. Además para mejor compilación, es decir si se compila un solo cpp hay que compilar todo ante cualquier cambio (Zinjal,2020).

### g++ *.cpp -o main.exe
### main.exe

## SICT0302B: Toma decisiones 
### Selecciona y usa una estructura lineal adecuada al problema
El uso de estructura lineal empleado es una lista doblemente ligada para almacenar datos. De esta manera es posible insertar y eliminar las canciones de cualquier parte de la lista ya que tiene apuntadores hacia adelante y atrás de la lista. 

### Selecciona un algoritmo de ordenamiento adecuado al problema
El método de ordenamiento que fue empleado para este programa fue merge sort, que ordena las canciones según su año de publicación. Utilice merge sort porque me permite ordenar una lista más larga de canciones que estén desordenadas. 

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
La implementación del ordenamiento se encuentra el main.cpp que con ayuda del ciclo do-while permite entrar a un menú de opciones para ver o ingresar caniones. De igual manera, indica si no hay canciones y en caso de que los años de publicación sean los mismos, se ordena según su título. 

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes. 
La complejidad del programa al emplear mergesort para tiempo es O(n log(n)), para espacio es O(n).
La complejidad del programa al emplear listas doblemente ligadas para espacio es O(n), para tiempo para agregar es O(1), para eliminar O(n). 

La complejidad conjunta del código:
En tiempo es O(n log(n)) -> (O(n log(n))+O2(n).
En espacio es O(n). 
 
## SICT0303B: Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de insertar canciones (opcion 1), eliminar canciones por año de publicación  (opción 2), eliminar canciones por título (opción 3) y acceder a las canciones ordenas (opcion 4).

## Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
Las canciones están en el archivo datosCanciones.csv, se leen al iniciar el programa.

## Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
Las canciones insertadas se guardan al inicio de datosCanciones.csv, emplea un vector temporal para ordenar los datos y posteriormente guardarlos en el archivo. 

