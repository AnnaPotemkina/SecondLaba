//
//  ListSequence.h
//  Laba2final
//
//  Created by Анна Потёмкина on 01.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef ListSequence_h
#define ListSequence_h

#include "List.h"
#include "Sequence.h"

template<typename T>
class ListSequence : public Sequence<T>
{
private:
    List<T> ListVec;
    unsigned long int size_of_list;
public:
    ListSequence();
    ~ListSequence() = default;
    
    unsigned long int length() override;
       
     void append(T) override;

     void prepend(T) override;

     void pop(unsigned long int) override;

     void swap(unsigned long int,unsigned long int) override;

     const T& getElem(unsigned long int) override;

     unsigned long int getIndex(T) override;

     void *getFirst() override;

     void *getLast() override;
     
     bool Check() override;
     
     T getEnd() override;
     
     void deleteAll() override;

     void insert( T, unsigned long int) override;
     
     void sort() override;
    
    T operator[](unsigned long int);
    
    List<T>& operator+(List<T>&);
    
    List<T>& operator=(const List<T>&);
    template <typename T1>
    friend std::ostream& operator<<(std::ostream&, const ListSequence<T1>&);
};

template <typename T>
ListSequence<T>::ListSequence() : Sequence<T>()
{
    size_of_list = 0;
}

template <typename T>
void ListSequence<T>::append(T itemToAdd) {
    ListVec.append(itemToAdd);
    ++size_of_list;
}

template <typename T>
void ListSequence<T>::prepend(T itemToAdd) {
    ListVec.prepend(itemToAdd);
    ++size_of_list;
}

template <typename T>
void ListSequence<T>::deleteAll() {
    ListVec.deleteAll();
    size_of_list = 0;
}

template <typename T>
bool ListSequence<T>::Check() {
    return ListVec.Check();
}

template <typename T>
T ListSequence<T>::getEnd() {
    return ListVec.getEnd();
}

template <typename T>
unsigned long int ListSequence<T>::length() {
    return ListVec.length();
}

template <typename T>
const T& ListSequence<T>::getElem(unsigned long int index) {
    return ListVec.getElem(index);
}

template <typename T>
unsigned long int ListSequence<T>::getIndex(T val) {
    return ListVec.getIndex(val);
}

template <typename T>
void ListSequence<T>::insert(  T itemToAdd, unsigned long int index) {
    ListVec.insert( itemToAdd, index);
}

template <typename T>
void ListSequence<T>::sort() {
    ListVec.Sort();
}



template <typename T>
List<T>& ListSequence<T>::operator+( List<T>& listToConcat) {
    return *this + listToConcat;
}

template<typename T>
T ListSequence<T>::operator[](unsigned long int index)
{
    return ListVec.getElem(index);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ListSequence<T>& listOutput) {
    os << listOutput.ListVec;
    return os;
}

template<typename T>
void *ListSequence<T>::getFirst() {
  return  ListVec.getFirst();
}

template<typename T>
void *ListSequence<T>::getLast() {
   return ListVec.getLast();
}

template <typename T>
void ListSequence<T>::pop(unsigned long int index) {
   ListVec.pop(index);
    --size_of_list;
}

template <typename T>
void ListSequence<T>::swap(unsigned long int index1, unsigned long int index2) {
    ListVec.swap(index1, index2);
}

#endif /* ListSequence_h */
