//
//  Arrayy.h
//  Laba2final
//
//  Created by Анна Потёмкина on 31.05.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef Arrayy_h
#define Arrayy_h
#include "ArrayElem.h"
#include "Errors.h"
#include <iostream>

template <typename T>
class Array{
private:
    ArrayElem<T>* data;
    unsigned long int size;
public:
    Array();

    Array(unsigned long int);
    
  //  Array(int);
    
    Array(const Array<T> &);
    
    ~Array();
    
    void resize(int);
    
    void append(T);

    void prepend(T);

    void pop(unsigned long int);

   // void remove();

    void swap(unsigned long int, unsigned long int);

    const T &getElem(unsigned long int);

    T getEnd();
    
    unsigned long int getIndex(T);

    void resize(unsigned long int);

    unsigned long int length();

    ArrayElem<T> *getFirst();

    ArrayElem<T> *getLast();

    void insert( T, unsigned long int);
    
    bool Check();
    
    void Sort();
    
    Array<T>& operator+(Array<T>&);

    bool operator==(const Array<T> &);

    bool operator!=(const Array<T> &);
    
    Array<T>& operator=(const Array<T>&);
    
    ArrayElem<T>& operator[](unsigned long int);
    
    void deleteAll();

    template<typename T1>
    friend std::ostream& operator<<(std::ostream&, const Array<T1>&);
};

template<typename T>
   Array<T>::~Array() = default;

template<typename T>
Array<T>::Array() {
           data = nullptr;
           size = 0;
}

template <typename T>
Array<T>::Array(unsigned long int n)
{
    data = new ArrayElem<T>[n];
    size= n;
}

template <typename T>
Array<T>::Array(const Array<T>& arrayToCopy) {
    data = new ArrayElem<T>[arrayToCopy.size];
    for (unsigned long int i = 0; i < arrayToCopy.size; ++i) {
        data[i] = arrayToCopy.data[i];
    }
    size = arrayToCopy.size;
}

template <typename T>
bool Array<T>::Check() {
    if (size) {
        return false;
    }
    else {
        return true;
    }
}

template<typename T>
       void Array<T>::resize(int n) {
           if (n >= this->size) {
               Array<T> dub(*this);
               delete[] data;
               data = new ArrayElem<T>[n];
               for (int i = 0; i < size; ++i) {
                   data[i] = dub[i];
               }
               size = n;
           } else {
               throw Exception_in_array("Array can't resize!");
           }
       }

template <typename T>
void Array<T>::deleteAll() {
    if (!this->Check()) {
        delete[] data;
        size = 0;
    }
    else {
        throw Exception_in_array("no such element");
    }
}

template<typename T>
void Array<T>::append(T val) {
           if (size == 0) {
               data = new ArrayElem<T>[1];
               data[0] = val;
               ++size;
           }
           else {
               Array<T> Arr(*this);
               delete[] data;
               data = new ArrayElem<T>[this->size + 1];
               for (int i = 0; i < this->size; ++i) {
                   data[i] = Arr[i];
               }
               data[size] = val;
               ++size;
           }
       }

template<typename T>
   void Array<T>::prepend(T val) {
       if (size == 0) {
           data = new ArrayElem<T>[1];
           data[0] = val;
           ++size;
       } else {
           Array<T> Arr(*this);
           delete[] data;
           data = new ArrayElem<T>[size + 1];
           for (int i = 1; i < size + 1; ++i) {
               data[i] = Arr[i - 1];
           }
           data[0] = val;
           ++size;
       }
   }

template<typename T>
void Array<T>::pop(unsigned long int index) {
    if (index >= 0 && index < size) {
        Array<T> Arr(*this);
        delete[] data;
        data = new ArrayElem<T>[size - 1];
        for (int i = 0; i < size; ++i) {
            if (i < index) {
                data[i] = Arr[i];
            } else if (i > index) {
                data[i - 1] = Arr[i];
            }
        }
        --size;
    } else {
        throw Exception_in_array("Index out of range!");
    }
}

template<typename T>
   void Array<T>::swap(unsigned long int index1, unsigned long int index2) {
       if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
           ArrayElem<T> dub = data[index1];
           data[index1] = data[index2];
           data[index2] = dub;
       } else {
           throw Exception_in_array("Index out of range!");
       }
   }

   template<typename T>
   const T& Array<T>::getElem(unsigned long int index) {
       if (index >= 0 && index < size) {
           return data[index].getElem();
       } else {
           throw Exception_in_array("Index out of range!");
       }
   }

   template<typename T>
   unsigned long int Array<T>::getIndex(T val) {
       for (int i = 0; i < size; ++i) {
           if (data[i].getElem() == val) {
               return i;
           }
       }
       return -1;
   }

   template<typename T>
   void Array<T>::resize(unsigned long int n) {
       if (n >= size) {
           Array<T> Arr(*this);
           delete[] data;
           data = new ArrayElem<T>[n];
           for (int i = 0; i < size; ++i) {
               data[i] = Arr[i];
           }
           size = n;
       } else {
           throw Exception_in_array("can't resize");
       }
   }

   template<typename T>
  unsigned long int Array<T>::length() {
       return size;
   }

template<typename T>
   ArrayElem<T> *Array<T>::getFirst() {
       return &data[0];
   }

   template<typename T>
   ArrayElem<T> *Array<T>::getLast() {
       return &data[size - 1];
   }

   template<typename T>
   void Array<T>::insert( T val, unsigned long int index) {
       if (index >= 0 && index <= size) {
           Array<T> Arr(*this);
           delete[] data;
           data = new ArrayElem<T>[size + 1];
           for (int i = 0; i < size + 1; ++i) {
               if (i < index) {
                   data[i] = Arr[i];
               } else if (i == index) {
                   data[i] = val;
               } else if (i > index) {
                   data[i] = Arr[i - 1];
               }
           }
           ++size;
       } else {
           throw Exception_in_array("Index out of range!");
       }
   }

template <typename T>
T Array<T>::getEnd() {
    if (this->Check()) {
        throw Exception_in_array("no element");
    }
    else {
        return data[size - 1].getElem();
    }
}

template <typename T>
void Array<T>::Sort() {
    bool flag = true;
    while (flag) {
        flag = false;
        for (unsigned long int i = 0; i < size - 1; ++i) {
            if (data[i].getElem() > data[i + 1].getElem()) {
                T dub = data[i].getElem();
                T d = data[i+1].getElem();
                data[i].setElem(d);
                data[i + 1].setElem(dub);
                flag = true;
            }
        }
    }
}

template<typename T>
bool Array<T>::operator!=(const Array<T> &Arr) {
    return !(*this == Arr);
}

template<typename T>
bool Array<T>::operator==(const Array<T> &Arr) {
    if (size == Arr.size) {
        for (int i = 0; i < size; ++i) {
            if (data[i] != Arr.data[i]) {
                return false;
            }
        }
        return true;
    } else {
        throw Exception_in_array("It is not possible to compare arrays of different lengths!");
    }
}

template <typename T>
   ArrayElem<T>& Array<T>::operator[](unsigned long int i) {
       if (i >= 0 && i < size) {
           return data[i];
       }
       else {
           throw Exception_in_array ("no such elem");
       }
   }

template <typename T>
Array<T>& Array<T>::operator+(Array<T>& arrToSumm) {
    Array<T> dub(*this);
    for (unsigned long int i = 0; i < arrToSumm.size; ++i) {
        dub.prepend(arrToSumm.data[i].getElem());
        
    }
}



template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arrayToCopy) {
    if (this == &arrayToCopy) {
        return *this;
    }
    else {
        size = arrayToCopy.size;
        delete[] data;
        data = new ArrayElem<T>[size];
        for (unsigned long int i = 0; i < size; ++i) {
            data[i] = arrayToCopy.data[i];
        }
        return *this;
    }
}

template <typename T1>
std::ostream& operator<<(std::ostream& os, const Array<T1>& arrOutput) {
    if (arrOutput.size) {
        for (unsigned long int i = 0; i < arrOutput.size; ++i) {
            if (i != arrOutput.size - 1) {
                os << arrOutput.data[i] << "; ";
            }
            else {
                os << arrOutput.data[i] << std::endl;
            }
        }
        return os;
    }
    else {
        throw Exception_in_array("no such elem");
    }
}


#endif /* Arrayy_h */
