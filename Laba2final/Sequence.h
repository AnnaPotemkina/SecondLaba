//
//  Sequence.h
//  Laba2final
//
//  Created by Анна Потёмкина on 01.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
template<typename T>
class Sequence {
public:
    
    Sequence()=default;
    
    ~Sequence() = default;
    
    virtual unsigned long int length() = 0;
    
    virtual void append(T) = 0;

    virtual void prepend(T) = 0;

    virtual void pop( unsigned long int) = 0;

 //   virtual void remove() = 0;
    
    // virtual void resize() = 0;

    virtual void swap( unsigned long int, unsigned long int) = 0;

    virtual const T& getElem( unsigned long int) = 0;

    virtual unsigned long int getIndex(T) = 0;

    virtual void *getFirst() = 0;

    virtual void *getLast() = 0;
    
    virtual  T getEnd()=0;
    
    virtual bool Check() = 0;
    
    virtual void deleteAll() = 0;

    virtual void insert(  T, unsigned long int) = 0;

    virtual void sort()=0;

};


#endif /* Sequence_h */
