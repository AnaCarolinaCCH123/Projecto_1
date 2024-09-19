#include "sorts.h"
//Divide recursivamente el vector y luego los junta en orden. 

void Sorts::ordenaMerge(std::vector<Song> &v) {
    std::vector<Song> tmp(v.size()); // Vector temporal del tamano v 
    mergeSplit(v, tmp, 0, v.size() - 1); 
}

void Sorts::mergeSplit(std::vector<Song> &A, std::vector<Song> &B, int low, int high) {
    if (low >= high){

    return; } // Caso inicial si ya esta ordenado

    int mid = (low + high) / 2; // Calcula la mitad 
    mergeSplit(A, B, low, mid); // Ordena lado izquierdo
    mergeSplit(A, B, mid + 1, high); // Ordena lado derecho
    mergeArray(A, B, low, mid, high); 
}

void Sorts::mergeArray(std::vector<Song> &A, std::vector<Song> &B, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    
    while (i <= mid && j <= high) {
        if (A[i].getAno() < A[j].getAno() ||
            (A[i].getAno() == A[j].getAno() && A[i].getTit() < A[j].getTit())) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

   
    while (i <= mid) {
        B[k++] = A[i++];
    }

   
    while (j <= high) {
        B[k++] = A[j++];
    }


    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}
