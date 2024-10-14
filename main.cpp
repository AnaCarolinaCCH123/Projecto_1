#include <iostream>
#include <string>
#include <vector>
#include "song.h"
#include "sorts.h"
#include "dlink.h"

int main() {

   
    DList<Song> songList; // Template DList 
    Sorts sorter; // Sorts para ordenar 
    int option = 0;

    do {
        std::cout << "El presente porgrama pretende simular una playlist de musica\n";
        std::cout << "Este es el menu de opciones\n";
        std::cout << "1. Agregar una nueva cancion al inicio\n";
        std::cout << "2. Eliminar cancion por ano\n";
        std::cout << "3. Eliminar cancion por titulo\n";
        std::cout << "4. Ver lista de canciones ordenadas por ano\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> option;

        switch (option) {

        case 1: {

            std::string title;
            int year;

            std::cout << "TItulo de la canciOn: ";
            std::cin.ignore(); 
            std::getline(std::cin, title);
            std::cout << "Ingrese su ano de publicacion: ";
            std::cin >> year;

            // Objeto Song 
            Song nuevaCancion(year, title);
            songList.addFirst(nuevaCancion);
            std::cout << "Cancion agregada correctamente.\n";
            break;
        }

        case 2: {
            int year;
            std::cout << "Ingrese el ano de la cancion a eliminar: ";
            std::cin >> year;
            songList.removeYear(year);
            break;
        }

        case 3: {
            std::string title;
            std::cout << "Ingrese el titulo de la cancion a eliminar: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            songList.removeTitle(title);
            break;
        }

        case 4: {
             std::vector<Song> songVector = songList.toVector(); 
             std::vector<Song> tempList(songVector.size()); //  vector temporal
             
             //Merge Sort
             sorter.ordenaMerge(songVector);
           
            std::cout << "Lista de canciones ordenadas:\n";
            for (const auto &cancion : songVector) {
                std::cout << cancion.getTitle() << ", " << cancion.getAno() << std::endl;
            }
    
    break;
}        
        case 5:
            std::cout << "Saliendo del programa\n";
            break;
        default:
            std::cout << "Erro 404\n";
        }

    } while (option != 5);

    return 0;
}
