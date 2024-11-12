//Ana Carolina Corone 
//A00838713
// Proyecto TC1031

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "song.h"
#include "sorts.h"
#include "dlink.h"


void cargaDatosCanciones(DList<Song>& songList) {
    std::ifstream archivo("datosCanciones.csv");
    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            size_t pos = linea.find(',');
            if (pos != std::string::npos) {
                int year = std::stoi(linea.substr(0, pos));
                std::string title = linea.substr(pos + 1);

                Song cancion(year, title);
                songList.addFirst(cancion);
            }
        }
        archivo.close();
    } else {
        std::cout << "No se pudo leer el archivo, no existe o está dañado" << std::endl;
    }
}

void escribeDatosCanciones(const DList<Song>& songList) {
    std::ofstream archivo("datosCanciones.csv");
    if (archivo.is_open()) {
        std::vector<Song> listaCanciones = songList.toVector();
        for (const auto& cancion : listaCanciones) {
            archivo << cancion.getAno() << "," << cancion.getTitle() << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "No se pudo escribir en el archivo" << std::endl;
    }
}

int main() {
    DList<Song> songList;   // Double Linked List
    Sorts sorter;           //Sorts 
    int option = 0;

    std::cout << "El presente programa pretende simular una playlist de música\n";

    // Cargar el archivo .csv al programa
    cargaDatosCanciones(songList);

    do {
        std::cout << "\nEste es el menu de opciones\n";
        std::cout << "1. Agregar una nueva cancion al inicio\n";
        std::cout << "2. Eliminar cancion por ano\n";
        std::cout << "3. Eliminar cancion por titulo\n";
        std::cout << "4. Ver y guardar lista de canciones ordenadas por ano\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese una opción: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::string title;
                int year;

                std::cout << "Titulo de la cancion: ";
                std::cin.ignore(); 
                std::getline(std::cin, title);
                std::cout << "Ingrese su ano de publicacion: ";
                std::cin >> year;

                Song nuevaCancion(year, title);
                songList.addFirst(nuevaCancion);
                std::cout << "Cancion agregada correctamente.\n";

                escribeDatosCanciones(songList);
                break;
            }

            case 2: {
                int year;
                std::cout << "Ingrese el ano de la cancion a eliminar: ";
                std::cin >> year;
                try {
                    songList.removeYear(year);
                    std::cout << "Cancion eliminada correctamente.\n";

                    escribeDatosCanciones(songList);
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }

            case 3: {
                std::string title;
                std::cout << "Ingrese el titulo de la cancion a eliminar: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                try {
                    songList.removeTitle(title);
                    std::cout << "Cancion eliminada.\n";

                    escribeDatosCanciones(songList);
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }

          case 4: {
           
                std::vector<Song> songVector = songList.toVector(); 
                sorter.ordenaMerge(songVector);
            
                std::cout << "Lista de canciones ordenadas:\n";
                for (const auto &cancion : songVector) {
                    std::cout << cancion.getTitle() << ", " << cancion.getAno() << std::endl;
                }

                DList<Song> sortedList;
                for (const auto& cancion : songVector) {
                    sortedList.addFirst(cancion); 
                }

                escribeDatosCanciones(sortedList); 
                break;
            }
            case 5:
                std::cout << "Saliendo del programa.\n";
                escribeDatosCanciones(songList);
                break;

            default:
                std::cout << "Error\n";
                break;
        }

    } while (option != 5);

    return 0;
}
