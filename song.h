#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <iostream>

class Song {
public:
    int ano;
    std::string title;

    Song() : ano(0), title("") {}
    Song(int a, const std::string& t) : ano(a), title(t) {}


    int getAno() const { 
        return ano; }

    std::string getTitle() const {
        return title; }

    friend std::ostream& operator<<(std::ostream& overload, const Song& song) {
        overload << "Title: " << song.title;
        overload  << ", Year: " << song.ano;
        return overload;
    }
};

#endif 

