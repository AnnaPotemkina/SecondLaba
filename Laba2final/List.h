//
//  List.h
//  Laba2final
//
//  Created by Анна Потёмкина on 01.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef List_h
#define List_h

#include "ListElem.h"
#include "Errors.h"
#include <iostream>
#include <string>
namespace std{
std::string to_string(std::string s){
    return s;
}
std::string to_string(char ch){
    return std::string(ch,1);
}
}

    template<typename T>
    class List {
    private:
        ListElem<T> *head;
        ListElem<T> *tail;
        int size;
    public:
        List();

        List(T *, unsigned long int);

        List(const List<T> &);

         bool PolCheck();
        
        void append(T);

        void prepend(T);

        void pop(unsigned long int);

        void deleteAll();
        
        bool Check();

        void swap(unsigned long int,unsigned long int);

        void Sort();
        
        T getEnd();
        
        const T &getElem(unsigned long int);

        unsigned long int getIndex(T);

       unsigned long  int length();

        ListElem<T> *getFirst();

        ListElem<T> *getLast();

        void insert( T, unsigned long int index);

        List<T> &operator=(const List<T> &);

        List<T>&  operator+(const List<T> &);

        List<T>& operator[]( unsigned long int);

        bool operator==(const List<T> &);

        bool operator!=(const List<T> &);

        ~List();


        template<typename T1>
        friend std::ostream &operator<<(std::ostream &, const List<T1> &);
    };

template<typename T>
  List<T>::List() {
      head = nullptr;
      tail = nullptr;
      size = 0;
  }

  template<typename T>
  void List<T>::append(T val) {
   if (!this->Check()) {
       tail->setNextPtr(new ListElem<T>);
       ListElem<T>* dub1 = tail;
       tail = tail->getNextPtr();
       tail->setElem(val);
       tail->setNextPtr(nullptr);
       tail->setPreviousPtr(dub1);
   }
   else {
       ListElem<T>* dub = new ListElem<T>;
       dub->setNextPtr(nullptr);
       dub->setPreviousPtr(nullptr);
       dub->setElem(val);
       head = dub;
       tail = dub;
   }
      ++size;
  }

template<typename T>
 List<T>::List(const List<T> &Lst) {
     head = nullptr;
     tail = nullptr;
     size = 0;
     ListElem<T> *El = Lst.head;
     while (El != nullptr) {
         append(*El);
         El = El->getNextPtr();
     }
 }

template <typename T>
bool List<T>::PolCheck(){
    ListElem<T> *El = head;
    std::string s;
    for (int i = 0; i < size; ++i) {
        if (typeid(*this)!=typeid(std::string)){
           s+= std::to_string(El->getElem());
        }
        else{
            s+=El->getElem();
        }
        El = El->getNextPtr();
    }

    for(int i = 0; i < s.length(); ++i)
   {   while(s[i]==' '){
        ++i;
    }
       while(s[s.length()-i-1]==' '){
            --i;
        }
        if(s[i] != s[s.length()-i-1])
        {
        
            return false;
            
        }
    }
    return true;
}

template<typename T>
void List<T>::prepend(T val) {
   if (!this->Check()) {
           head->setPreviousPtr(new ListElem<T>);
           ListElem<T>* dub1 = head;
           head = head->getPrevPtr();
           head->setElem(val);
           head->setPreviousPtr(nullptr);
           head->setNextPtr(dub1);
       }
       else {
           ListElem<T>* dub = new ListElem<T>;
           dub->setNextPtr(nullptr);
           dub->setPreviousPtr(nullptr);
           dub->setElem(val);
           head = dub;
           tail = dub;
       }
      
    ++size;
}

template<typename T>
List<T>::List( T* mas, unsigned long int n) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (int i = 0; i < n; ++i) {
        append(mas[i]);
    }
}

template<typename T>
void List<T>::pop(unsigned long int index) {
    if (index >= 0 && index < size) {
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else if (index == 0) {
            head = head->getNextPtr();
            delete head->getPrevPtr();
            head->setPreviousPtr(nullptr);
        } else if (index == size - 1) {
            tail = tail->getPrevPtr();
            delete tail->getNextPtr();
            tail->setNextPtr(nullptr);
        } else {
            ListElem<T> *El = head;
            for (int i = 0; i < index - 1; ++i) {
                El = El->getNextPtr();
            }
            El->setNextPtr(El->getNextPtr()->getNextPtr());
            delete El->getNextPtr()->getPrevPtr();
            El->getNextPtr()->setPreviousPtr(El);
        }
        --size;
    } else {
        throw Exception_in_list("Index out of range!");
    }
}

template<typename T>
void List<T>::swap(unsigned long int index1, unsigned long int index2) {
    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
        ListElem<T> *El1 = head;
        for (int i = 0; i < index1; ++i) {
            El1 = El1->getNextPtr();
        }
        ListElem<T> *El2 = head;
        for (int i = 0; i < index2; ++i) {
            El2 = El2->getNextPtr();
        }
        T el = *El1;
        El1->setElem(El2->getElem());
        El2->setElem(el);
    } else {
        throw Exception_in_list("Index out of range!");
    }
}

template<typename T>
const T &List<T>::getElem(unsigned long int index) {
    if (index >= 0 && index < size) {
        ListElem<T> *El = head;
        for (int i = 0; i < index; ++i) {
            El = El->getNextPtr();
        }
        return El->getElem();
    } else {
        throw Exception_in_list("Index out of range!");
    }
}

template <typename T>
bool List<T>::Check() {
    if (size) {
        return false;
    }
    else {
        return true;
    }
}


template <typename T>
void List<T>::deleteAll() {
    if (!this->Check()) {
        ListElem<T>* dub = head;
        while (dub)
        {
            ListElem<T>* dub2 = dub;
            dub = dub->getNextPtr();
            delete dub2;
        }
        size = 0;
    }
    else {
        throw Exception_in_list("it is empty");
    }
}

template<typename T>
   List<T> &List<T>::operator=(const List<T> &Lst) {
       if (this == &Lst) {
           return *this;
       }
       deleteAll();
       ListElem<T> *El = Lst.head;
       while (El != nullptr) {
           append(*El);
           El = El->getNextPtr();
       }
       return *this;
   }

  template <typename T>
  List<T>& List<T>::operator+(const List<T>& listToConcat) {
      List<T> dub(*this);
      ListElem<T>* dub1 = listToConcat.head;
      while (dub1) {
          dub.pushBack(dub1->getElem());
          dub1 = dub1->getNextPtr();
      }
      return dub;
  }


   //template<typename T>

   template<typename T>
   bool List<T>::operator==(const List<T> &Lst) {
       if (size == Lst.size) {
           ListElem<T> *El1 = head;
           ListElem<T> *El2 = Lst.head;
           while (El1 != nullptr && El2 != nullptr) {
               if (*El1 != *El2) {
                   return false;
               }
               El1 = El1->getNextPtr();
               El2 = El2->getNextPtr();
           }
           return true;
       } else {
           throw Exception_in_list("It is not possible to compare arrays of different lengths!");
       }
   }

   template<typename T>
   bool List<T>::operator!=(const List<T> &Lst) {
       return !(*this == Lst);
   }

template<typename T>
   ListElem<T> * List<T>::getFirst() {
       return head;
   }

   template<typename T>
   ListElem<T> *List<T>::getLast() {
       return tail;
   }

template<typename T>
  unsigned long int List<T>::length() {
      return size;
  }

template<typename T>
unsigned long int List<T>::getIndex(T val) {
    ListElem<T> *El = this->head;
    for (int i = 0; i < this->size; ++i) {
        if (El->getElem() == val) {
            return i;
        }
        El = El->getNextPtr();
    }
    return -1;
}

template<typename T>
   void List<T>::insert( T val, unsigned long int index) {
       if (index >= 0 && index <= this->size) {
           if (index == 0) {
               prepend(val);
           } else if (index == this->size) {
               append(val);
           } else {
               ListElem<T> *ElPrev = this->head;
               for (int i = 0; i < index - 1; ++i) {
                   ElPrev = ElPrev->getNextPtr();
               }
               ListElem<T> *ElNext = ElPrev->getNextPtr();
               ListElem<T> *El = new ListElem<T>;
               El->setElem(val);
               El->setPreviousPtr(ElPrev);
               El->setNextPtr(ElNext);
               ElPrev->setNextPtr(El);
               ElNext->setPreviousPtr(El);
               ++this->size;
           }
       } else {
           throw Exception_in_list("Index out of range!");
       }
   }

template<typename T>
 List<T>& List<T>::operator[](unsigned long int i) {
    if (i >= 0 && i < size) {
        ListElem<T>* dub = head;
        unsigned long int j = 0;
        while (dub != nullptr && j < i) {
            dub = dub->getNextPtr();
            ++j;
        }
        return *dub;
    }
    else {
        throw Exception_in_list("it is empty");
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& listOutput) {
    if (listOutput.size) {
        ListElem<T>* dub = listOutput.head;
        while (dub) {
            if (dub != listOutput.tail) {
                os << dub->getElem() << ";  ";
            }
            else {
                os << dub->getElem() << std::endl;
            }
            dub = dub->getNextPtr();
        }
        return os;
    }
    else {
        throw Exception_in_list("no element");
    }
}

template<typename T>
    List<T>::~List() = default;

template <typename T>
void List<T>::Sort() {
    if (size == 1) {
        return;
    }
    else if (size == 2) {
        //ListOptions<T>* temp1 = tail;
        tail->setNextPtr(head);
        head->setPreviousPtr(tail);
        head->setNextPtr(nullptr);
        tail->setPreviousPtr(nullptr);
        ListElem<T>* dub = head;
        head = tail;
        tail = dub;
    }
    else {
        ListElem<T>* dub1 = head;
        while (dub1) {
            ListElem<T>* dub2 = head;
            while (dub2->getNextPtr()) {
                if (dub2->getElem() > dub2->getNextPtr()->getElem()) {
                    ListElem<T>* dub3 = dub2->getNextPtr();
                    if (!dub2->getPrevPtr()) {
                        dub3->getNextPtr()->setPreviousPtr(dub2);
                        dub3->setPreviousPtr(nullptr);
                        dub2->setNextPtr(dub3->getNextPtr());
                        dub3->setNextPtr(dub2);
                        dub2->setPreviousPtr(dub3);
                        head = dub3;
                    }
                    else if (!dub3->getNextPtr()) {
                        dub2->getPrevPtr()->setNextPtr(dub3);
                        dub2->setNextPtr(nullptr);
                        dub3->setPreviousPtr(dub2->getPrevPtr());
                        dub3->setNextPtr(dub2);
                        dub2->setPreviousPtr(dub3);
                        break;
                    }
                    else {
                        dub2->getPrevPtr()->setNextPtr(dub3);
                        dub3->getNextPtr()->setPreviousPtr(dub2);
                        dub2->setNextPtr(dub3->getNextPtr());
                        dub3->setPreviousPtr(dub2->getPrevPtr());
                        dub2->setPreviousPtr(dub3);
                        dub3->setNextPtr(dub2);
                    }
                }
                dub2 = dub2->getNextPtr();
            }
            if (!dub1->getNextPtr()) {
                tail = dub1;
                break;
            }
            dub1 = dub1->getNextPtr();

        }
    }
}

template <typename T>
T List<T>::getEnd() {
    if (this->Check()) {
        throw Exception_in_list("no elements");
    }
    else {
        return tail->getElem();
    }
}

#endif /* List_h */
