#include "song.h"

Song::Song() : _tit("?"), _ano(0) {}  // Constructor por omision

Song::Song(std::string tit, int ano) : _tit(tit), _ano(ano) { }// Constructor por parametros

std::string Song::getTit() const {
    return _tit;
}

int Song::getAno() const {
    return _ano;
}
