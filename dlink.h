#ifndef DLINK_H_
#define DLINK_H_

#include "song.h"
#include "sorts.h"
#include <iostream>
#include <sstream>
#include <vector> 

template <class T> class DList;

template <class T>
class DLink {
private:

    DLink(T);
    DLink(T, DLink<T>*, DLink<T>*);
    DLink(const DLink<T>&);

    T value;
    DLink<T> *previous;
    DLink<T> *next;

    friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
    DList();
    DList(const DList<T>&);
    ~DList();

    void addFirst(T);
    bool empty() const;
    void clear();
    std::string toString() const;
    std::vector<T> toVector() const;    
    void fromVector(const std::vector<T>&);  
    T removeTitle(const std::string&);
    T removeYear(int);

private:
    DLink<T> *head;
    DLink<T> *tail;
    int size;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
    clear();
}

template <class T>
bool DList<T>::empty() const {
    return (head == 0 && tail == 0);
}

template <class T>
void DList<T>::addFirst(T val) {
    DLink<T> *newLink = new DLink<T>(val);
    if (newLink == 0) {
        return;
    }

    if (empty()) {
        head = newLink;
        tail = newLink;
    } else {
        newLink->next = head;
        head->previous = newLink;
        head = newLink;
    }
    size++;
}

template <class T>
void DList<T>::clear() {
    DLink<T> *p, *q;

    p = head;
    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
std::string DList<T>::toString() const {
    std::stringstream aux;
    DLink<T> *p = head;

    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::vector<T> DList<T>::toVector() const {
    std::vector<T> vec;
    DLink<T> *p = head;

    while (p != 0) {
        vec.push_back(p->value);
        p = p->next;
    }

    return vec;
}

template <class T>
void DList<T>::fromVector(const std::vector<T>& vec) {
    clear();
    for (const T& item : vec) {
        addFirst(item);
    }
}

template <class T>
T DList<T>::removeYear(int year) {
    DLink<T> *p = head;
    while (p != 0) {
        if (p->value.getAno() == year) {
            if (p->previous != 0) {
                p->previous->next = p->next;
            } else {
                head = p->next;
            }
            if (p->next != 0) {
                p->next->previous = p->previous;
            } else {
                tail = p->previous;
            }
            T val = p->value;
            delete p;
            size--;
            return val;
        }
        p = p->next;
    }throw std::out_of_range("Error");
}

template <class T>
T DList<T>::removeTitle(const std::string &titlele) {
    DLink<T> *p = head;
    while (p != 0) {
        if (p->value.getTitle() == titlele) {
            if (p->previous != 0) {
                p->previous->next = p->next;
            } else {
                head = p->next;
            }
            if (p->next != 0) {
                p->next->previous = p->previous;
            } else {
                tail = p->previous;
            }
            T val = p->value;
            delete p;
            size--;
            return val;
        }
        p = p->next;
    }throw std::out_of_range("Error");
}

#endif


