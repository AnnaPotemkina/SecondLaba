//
//  ArrayElem.h
//  Laba2final
//
//  Created by Анна Потёмкина on 31.05.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef ArrayElem_h
#define ArrayElem_h

#include "Errors.h"
#include <iostream>

template <typename T>
class ArrayElem
{
public:
    ArrayElem();
    ArrayElem(T);
    ArrayElem(const ArrayElem<T> &);
    ~ArrayElem() = default;
    void setElem(T);
    const T &getElem();
    bool check() { return Flag; }
    template <typename T1>
    friend std::ostream& operator<<(std::ostream&, const ArrayElem<T1>&);
    ArrayElem<T>& operator=(const ArrayElem<T>&);
    ArrayElem<T>& operator=(T);
    bool operator==(ArrayElem<T>& arrToCompare) { return (Flag && arrToCompare.Flag && Elem == arrToCompare.value) || (arrToCompare.Flag == Flag); }
    bool operator!=(ArrayElem<T>& arrToCompare) { return !(*this == arrToCompare); }
    
private:
    T Elem;
    bool Flag;
};

template<typename T>
ArrayElem<T>::ArrayElem(){
    Flag=false;
}

template<typename T>
ArrayElem<T>::ArrayElem(T el){
    Elem=el;
    Flag=true;
}

template<typename T>
ArrayElem<T>::ArrayElem(const ArrayElem<T> &ArrEl) {
    Flag = ArrEl.Flag;
    Elem = ArrEl.Elem;
}

template<typename T>
void ArrayElem<T>::setElem(T el){
    Elem=el;
    Flag=true;
}

template <typename T>
const T &ArrayElem<T>::getElem() {
    if (Flag) {
        return Elem;
    }
    else {
        throw Element_exception_array("there is no such element");
    }
}

template<typename T>
ArrayElem<T> &ArrayElem<T>::operator=(const ArrayElem<T> &ArrEl){
    if (this==&ArrEl){
        return *this;
    }
    Flag=ArrEl.Flag;
    Elem=ArrEl.Elem;
    return *this;
}

template<typename T>
ArrayElem<T> &ArrayElem<T>::operator=(T el){
    if (Elem == el){
        return *this;
    }
    else{
        Flag = true;
        Elem = el;
         return *this;
    }
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const ArrayElem<T> &ArrEl){
    os << ArrEl.Elem;
    return os;
}


#endif /* ArrayElem_h */
