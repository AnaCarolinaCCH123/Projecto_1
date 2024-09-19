
#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>

class Song {
public:
    Song();  // Constructor por omision 
    Song(std::string tit, int ano); // Constructor por parametros

    std::string getTit() const;
    int getAno() const;

private:
    std::string _tit;
    int _ano;
};

#endif
