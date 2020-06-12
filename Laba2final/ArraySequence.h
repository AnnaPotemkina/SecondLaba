//
//  ArraySequence.h
//  Laba2final
//
//  Created by Анна Потёмкина on 01.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef ArraySequence_h
#define ArraySequence_h
#include "Arrayy.h"
#include "Sequence.h"

template<typename T>
class ArraySequence : public Sequence<T>
{
private:
    Array<T> ArrayVec;
    unsigned long int size_of_array;
public:
    ArraySequence();
    ~ArraySequence() = default;
   unsigned long int length() override;
      
    void append(T) override;

    void prepend(T) override;

    void pop(unsigned long int) override;

   // void remove() override;
    
    //void resize() override;

    void swap(unsigned long int,unsigned long int) override;

    const T& getElem(unsigned long int) override;

    unsigned long int getIndex(T) override;

    void *getFirst() override;

    void *getLast() override;
    
    bool Check() override;
    
    T getEnd() override;
    
    void deleteAll() override;

    void insert(  T, unsigned long int) override;
    
    void sort() override ;

    
    T operator[](unsigned long int);
    
    Array<T>& operator+(Array<T>&);
    
    Array<T>& operator=(const Array<T>&);
    
    template <typename T1>
    friend std::ostream& operator<<(std::ostream&, const ArraySequence<T1>&);
    
};

template<typename T>
ArraySequence<T>::ArraySequence() : Sequence<T>(){
    size_of_array = 0;
}

template <typename T>
void ArraySequence<T>::deleteAll() {
    ArrayVec.deleteAll();
    size_of_array = 0;
}

template <typename T>
bool ArraySequence<T>::Check() {
    return ArrayVec.Check();
}


template <typename T>
void ArraySequence<T>::append(T ElemToAdd) {
     return ArrayVec.append(ElemToAdd);
}


template <typename T>
void ArraySequence<T>::insert( T itemToAdd, unsigned long int index) {
    ArrayVec.insert( itemToAdd, index);
}

template <typename T>
void ArraySequence<T>::prepend(T ElemToAdd) {
   return  ArrayVec.prepend(ElemToAdd);
}

template <typename T>
void ArraySequence<T>::pop(unsigned long int index) {
   ArrayVec.pop(index);
    --size_of_array;
}

template <typename T>
void ArraySequence<T>::swap(unsigned long int index1, unsigned long int index2) {
    ArrayVec.swap(index1, index2);
}

template <typename T>
unsigned long int ArraySequence<T>::length() {
    return ArrayVec.length();
}

template <typename T>
const T& ArraySequence<T>::getElem(unsigned long int index) {
    return ArrayVec.getElem(index);
}

template <typename T>
unsigned long int ArraySequence<T>::getIndex(T value) {
    return ArrayVec.getIndex(value);
}

/*template <typename T>
void ArraySequence<T>::resize(int index) {
   ArrayVec.resize(index);
}*/

template<typename T>
void *ArraySequence<T>::getFirst() {
  return ArrayVec.getFirst();
    
}

template<typename T>
void *ArraySequence<T>::getLast() {
   return ArrayVec.getLast();
}

template <typename T>
Array<T>& ArraySequence<T>::operator+(Array<T>& arrToSumm) {
    return *this + arrToSumm;
}

template<typename T>
T ArraySequence<T>::operator[](unsigned long int index)
{
    return ArrayVec[index];
}

template <typename T>
T ArraySequence<T>::getEnd() {
    return ArrayVec.getEnd();
}

template <typename T>
void ArraySequence<T>::sort() {
    ArrayVec.Sort();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ArraySequence<T>& listOutput) {
    os << listOutput.ArrayVec;
    return os;
}

#endif /* ArraySequence_h */
