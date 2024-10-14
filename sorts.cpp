#include "sorts.h"

// Divide recursivamente el vector y luego los junta en orden. 
void Sorts::ordenaMerge(std::vector<Song> &v) {
    std::vector<Song> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
}

void Sorts::mergeSplit(std::vector<Song> &A, std::vector<Song> &B, int left, int right) {
    if (left < right) {
        return; }
        int mid = (left + right) / 2;
        mergeSplit(A, B, left, mid);
        mergeSplit(A, B, mid + 1, right);
        mergeArray(A, B, left, mid, right);
    }


void Sorts::mergeArray(std::vector<Song> &A, std::vector<Song> &B, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (A[i].getAno() < A[j].getAno() || 
            (A[i].getAno() == A[j].getAno() && A[i].getTitle() < A[j].getTitle())) {
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

    for (int l = low; l <= high; l++) {
        A[l] = B[l];
    }
}
