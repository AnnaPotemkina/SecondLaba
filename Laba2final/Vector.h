//
//  Vector.h
//  Laba2final
//
//  Created by Анна Потёмкина on 05.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include "ArraySequence.h"
#include "ListSequence.h"
#include "Errors.h"
#include <string>
#include <typeinfo>

template <typename T>
class Vector {
private:
    Sequence<T>* VectorData;
     unsigned long int sizeOfVector;
   std:: string typeOfSeq;
public:
    Vector();
    
    Vector(std:: string);
    
    Vector(const Vector<T>&);
    
    ~Vector() = default;
    
   // std::string TypeSeq() {return typeOfData;}
    void Append(T);
    
    void Prepend(T);
    
    bool Check_vec();
    
    const T& GetElem(unsigned long int);
    
    void Pop(unsigned long int);
    
    void Remove();
    
    T GetEnd();
    
    void Insert(T, unsigned long int);
    
    unsigned long int Length();
    
    unsigned  long int GetIndex(T);
    
    T &GetElemByIndex(unsigned long int);
    
    void Sorting();
    
    void Swap(unsigned long int,unsigned long int);
    
    T* getSubsequence(unsigned long int, unsigned long int);
    
    Vector<T> operator+(const Vector<T>&);
    
    Vector<T>& operator=(const Vector<T>&);
    
    T operator[](unsigned long int);
    
    template <typename T1>
    friend std::istream& operator>>(std::istream& , Vector<T1>&);
    
    template <typename T1>
    friend std::ostream& operator<<(std::ostream&, Vector<T1>&);
};

template<typename T>
 Vector<T>::Vector() {
    VectorData = new ArraySequence<T>;
    sizeOfVector = VectorData->length();
    typeOfSeq = "arraySequence";
}

template <typename T>
Vector<T>::Vector(std::string tp){
    typeOfSeq  = tp;
    if (tp == "arraySequence") {
        VectorData = new ArraySequence<T>;
        sizeOfVector = VectorData->length();
    }
    else if (tp == "listSequence") {
        VectorData = new ListSequence<T>;
        sizeOfVector = VectorData->length();
    }
    else {
        throw Exception_in_vector("Wrong type");
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& VecToCopy) {
    sizeOfVector = VecToCopy.sizeOfVector;
    typeOfSeq = VecToCopy.typeOfSeq;
    if (VecToCopy.typeOfSeq == "arraySequence") {
        VectorData = new ArraySequence<T>;
        for (unsigned long int i = 0; i < sizeOfVector; ++i) {
            VectorData->prepend(VecToCopy.VectorData->getElem(i));
        }
    }
    else if (VecToCopy.typeOfSeq == "listSequence") {
        VectorData = new ListSequence<T>;
        for (unsigned long int i = 0; i < sizeOfVector; ++i) {
            VectorData->prepend(VecToCopy.VectorData->getElem(i));
        }
    }
    else {
        throw Exception_in_vector("Wrong type");
    }
    
}


template <typename T>
void Vector<T>::Append(T elemToAdd) {
    VectorData->append(elemToAdd);
    ++sizeOfVector;
}

template <typename T>
unsigned long int Vector<T>::Length() {
    return VectorData->length();
}

template <typename T>
void Vector<T>::Prepend(T elemToAdd) {
    VectorData->prepend(elemToAdd);
    ++sizeOfVector;
}



template <typename T>
T Vector<T>::GetEnd() {
    if (this->Check_vec()) {
        throw Exception_in_vector("it is empty");
    }
    else {
        return VectorData->getEnd();
    }
}

template <typename T>
bool Vector<T>::Check_vec() {
    return VectorData->Check();
}

template <typename T>
void Vector<T>::Pop(unsigned long int el){
    --sizeOfVector;
    VectorData->pop(el);
}

template <typename T>
void Vector<T>::Sorting() {
    VectorData->sort();
}

template <typename T>
const T& Vector<T>::GetElem(unsigned long int index) {
    return VectorData->getElem(index);
}

template <typename T>
unsigned long int Vector<T>::GetIndex(T val) {
    return VectorData->getIndex(val);
}

template <typename T>
void Vector<T>::Insert(T Elem, unsigned long int index) {
    VectorData->insert(Elem, index);
    ++sizeOfVector;
}

template <typename T>
void Vector<T>::Remove() {
    if (this->Check_vec()) {
        throw Exception_in_vector("Is empty");
    }
    else
    {
        VectorData->deleteAll();
    }
}

template <typename T>
void Vector<T>::Swap(unsigned long int index1,unsigned long int index2){
    VectorData ->swap(index1,index2);
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& VecToAdd) {
   /* Vector<T> dub(*this);
    for(unsigned long int i=0; i<=(VecToAdd.sizeOfVector-1); ++i){
        dub.Append(VecToAdd.VectorData->getElem(i));}
     if (dub.typeOfSeq==VecToAdd.typeOfSeq){
      //   cout<<"ddddd";
         dub= dub+VecToAdd;
     }
     else{cout<<"111111";
         for(unsigned long int i=0; i<=(VecToAdd.sizeOfVector-1); ++i){
         dub.Append(VecToAdd.VectorData->getElem(i));;
     }
     }
    for (unsigned long int i = 0; i < VecToAdd.sizeOfVector; ++i) {
        dub.Append(VecToAdd.VectorData->getElem(i));
    }
    return dub;*/

    Vector<T> dub(*this);
        for (unsigned long int i = 0; i < VecToAdd.sizeOfVector; ++i) {
            dub.Append(VecToAdd.VectorData->getElem(i));
        }
        return dub;
    }

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& Vect)
{
    delete VectorData;
    typeOfSeq = Vect.typeOfSeq;
    sizeOfVector = Vect.sizeOfVector;
    if (Vect.typeOfSeq == "arraySequence") {
        VectorData = new ArraySequence<T>;
        for (unsigned long int i = 0; i < sizeOfVector; ++i) {
            VectorData->append(Vect.VectorData->getElem(i));
        }
    }
    else {
        VectorData = new ListSequence<T>;
        for (unsigned long int i = 0; i < Vect.sizeOfVector; ++i) {
            VectorData->append(Vect.VectorData->getElem(i));
        }
    }
    return *this;
}

template<typename T>
T Vector<T>::operator[](unsigned long int index)
{
    return this->GetElem(index);
}

template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& Vect) {
    if (typeid(T) == typeid(std::string)) {
        std::cout << "ââîäèòå ñòðîêè, åñëè õîòèòå ïðåêðàòèòü ââîä, ââåäèòå q èëè Q" << std::endl;
        std::string input = "";
        while (getline(is, input)) {
            if (input == "q" || input == "Q") {
                break;
            }
            Vect.Append(input);
        }
    }
    else {
        T input;
        while (is >> input) {
            if (!is.get()) {
                break;
            }
            Vect.Append(input);
        }
    }
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T>& VectorOutput) {
    if (VectorOutput.typeOfSeq == "arraySequence") {
        os << *dynamic_cast<ArraySequence<T>*>(VectorOutput.VectorData);
    }
    else if (VectorOutput.typeOfSeq == "listSequence") {
        os << *dynamic_cast<ListSequence<T>*>(VectorOutput.VectorData);
    }
    else {
        throw Exception_in_vector("Wrong type");
    }
    return os;
}


#endif /* Vector_h */
