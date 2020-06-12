//
//  ListElem.h
//  Laba2final
//
//  Created by Анна Потёмкина on 31.05.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef ListElem_h
#define ListElem_h
#include "Errors.h"

template<typename T>
class ListElem {
private:
    T Elem;
    
    ListElem<T> *NextPtr;
    
    ListElem<T> *PreviousPtr;
     
    bool Flag;
    
public:
    ListElem();
    
    ListElem(T);
    
    ListElem(const ListElem<T> &);
    
    void setElem(T);
    
    void setNextPtr(ListElem<T> *);
    
    void setPreviousPtr(ListElem<T> *);
    
    const T &getElem();
    
    ListElem<T> *getNextPtr();
    
    ListElem<T> *getPrevPtr();
    
    bool check() { return Flag; }
    
    ListElem<T> &operator = (const ListElem<T> &);

    ListElem<T> &operator = (T);

    operator T();

    template<typename T1> friend std::ostream& operator<< (std::ostream &, const ListElem<T> &);
    bool operator==(ListElem<T>& listToCompare) { return (Flag && listToCompare.hasValue && Elem == listToCompare.value) || (listToCompare.hasValue == Flag); }

    ~ListElem();
};

template <typename T>
ListElem<T>::ListElem(){
    Flag=false;
    NextPtr= nullptr;
    PreviousPtr = nullptr;
}

template <typename T>
ListElem<T>::ListElem(T el){
    Elem = el;
    Flag = true;
    NextPtr = nullptr;
    PreviousPtr = nullptr;
}

template <typename T>
ListElem<T>::ListElem(const ListElem<T> &ListEl){
    Flag = ListEl.Flag;
    Elem = ListEl.Elem;
    NextPtr= ListEl.NextPtr;
    PreviousPtr= ListEl.PreviousPtr;
}

template <typename T>
void ListElem<T>::setElem(T el){
    Elem=el;
    Flag=true;
}
    
template <typename T>
const T &ListElem<T>::getElem(){
    if(Flag){
        return Elem;
    }
    else{
        throw Element_exception_array("There is no Element");
    }
}
    
template <typename T>
ListElem<T> &ListElem<T>::operator=(const ListElem<T> &ListEl){
    if (this== &ListEl){
        return *this;
    }
    Flag= ListEl.Flag;
    Elem = ListEl.Elem;
    NextPtr = ListEl.NextPtr;
    PreviousPtr = ListEl.PreviousPtr;
    return *this;
}
    
template<typename T>
ListElem<T>::operator T() {
    if (Flag){
        return Elem;
    }
    else {
        throw Element_exception_array("Element has not value!");
    }
}

template<typename T>
ListElem<T> &ListElem<T>::operator=(T el) {
    Elem = el;
    Flag = true;
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const ListElem<T> &ListEl) {
    out << ListEl.Elem;
    return out;
}

template<typename T>
void ListElem<T>::setNextPtr(ListElem<T> *Next) {
    NextPtr = Next;
}

template<typename T>
void ListElem<T>::setPreviousPtr(ListElem<T> *Previous) {
    PreviousPtr = Previous;
        }

template<typename T>
ListElem<T> *ListElem<T>::getNextPtr() {
    return NextPtr;
}

template<typename T>
ListElem<T> *ListElem<T>::getPrevPtr() {
    return PreviousPtr;
}

template<typename T>
ListElem<T>::~ListElem() = default;


#endif /* ListElem_h */
