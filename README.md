# Listas de música 
El presente código muestra como ordenar listas de múisca amplias considerando su año de publicación. Es así que es posible reconocer que canción es más reciente e incluir las canciones que se desean ordenar. 

## SICT0302B: Toma decisiones 
### Selecciona y usa una estructura lineal adecuada al problema
El uso de estructura lineal empleado es con un vector que permite almacenar elementos y acceder a ellos de manera rápida. El vector acepta objetos de tipo song cuyos atributos son año de publicación y título. 

### Selecciona un algoritmo de ordenamiento adecuado al problema
El método de ordenamiento que fue empleado para este programa fue merge sort, que ordena las canciones según su año de publicación. Utilice merge sort porque me permite ordenar una lista más larga de canciones que estén desordenadas. 

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
La implementación del ordenamiento se encuentra el main.cpp que con ayuda del ciclo do-while permite entrar a un menú de opciones para ver o ingresar caniones. De igual manera, indica si no hay canciones y en caso de que los años de publicación sean los mismos, se ordena según su título. 

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes. 
La complejidad del programa al emplear mergesort es O(n log(n)). 
 

