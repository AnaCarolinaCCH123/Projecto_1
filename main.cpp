#include "song.h"
#include "sorts.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Song> canciones; //Vector que almacena las canciones 
    Sorts sorts;
    int num;

    do {
    
        std::cout << "Opciones del programa:\n";
        std::cout << "1. Ingresar canciones\n";
        std::cout << "2. Ver lista de canciones ordenadas\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige la opcion: ";
        std::cin >> num;

        switch (num) {
            case 1: {
                int numCanciones;
                std::cout << "Numero de canciones a ingresar: ";
                std::cin >> numCanciones;

                for (int i = 0; i < numCanciones; ++i) {
                    std::string titulo;
                    int ano;

                    std::cout << "Ingresa el titulo de la cancion:\n";
                    std::cin.ignore(); 
                    std::getline(std::cin, titulo);

                    std::cout << "Ingresa su ano de publicacion de:\n";
                    std::cin >> ano;

                    canciones.emplace_back(titulo, ano);
                    std::cout << "Canciones agregadas\n";
                }
                break;  
            }
            case 2: {
                if (canciones.empty()) {
                    std::cout << "No hay canciones \n";
                } else {
                    // Ordenar las canciones
                    sorts.ordenaMerge(canciones);

                    // Mostrar canciones ordenadas
                    std::cout << "Lista de canciones ordenada segun su ano de publicacion:\n";
                    for (const auto &cancion : canciones) {
                        std::cout << cancion.getTit() << ", " << cancion.getAno() << std::endl;
                    }
                }
                break;
            }
            case 3: {
                std::cout << "Saliendo del programa...\n";
                break;
            }
           
        }
    } while (num != 3); 

    return 0;
}
