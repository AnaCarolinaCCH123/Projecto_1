#ifndef SORTS_H_
#define SORTS_H_

#include "song.h"
#include <vector>

class Sorts {
public:
    void ordenaMerge(std::vector<Song> &v); // ordenar vector de objetos Song

private:
    void mergeSplit(std::vector<Song> &v, std::vector<Song> &tmp, int left, int right);
    void mergeArray(std::vector<Song> &A, std::vector<Song> &B, int low, int mid, int high);
};

#endif