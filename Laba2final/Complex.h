//
//  Complex.h
//  Laba2final
//
//  Created by Анна Потёмкина on 10.06.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef Complex_h
#define Complex_h
#include <iostream>

class Compl{
private:
   long int main_part;
    long int comp;
public:
    Compl(): main_part {0}, comp {0}{};
    Compl(long int base, long int dop): main_part{base}, comp{dop}{};
    ~Compl() = default;
    long int GetMain() const { return main_part; };
    long int GetComp() const { return comp; };
    
    Compl& operator=(const Compl& numb) {
        if (this == &numb) {
            return *this;
        }
        else {
            main_part = numb.main_part;
            comp= numb.comp;
        }
        return *this;
    }
    
    Compl  operator +(const Compl& numb){
        Compl dub(*this);
        dub.main_part=numb.main_part+dub.main_part;
        dub.comp = numb.comp+dub.comp;
        return dub;
    }
    
    Compl operator*(const Compl& numb){
        Compl dub (*this);
        dub.main_part=(numb.main_part*dub.main_part) -(numb.comp*dub.comp) ;
       dub.comp=(numb.main_part*dub.comp)+(dub.main_part*numb.comp);
        return dub;
    }

    Compl  operator -(const Compl& numb){
          Compl dub(*this);
          dub.main_part=dub.main_part-numb.main_part;
          dub.comp = dub.comp-numb.comp;
          return dub;
      }
    
    
    friend std::istream& operator>>(std::istream& is, Compl& numbToInput) {
        std::cout << "введем действительную часть: ";
        (is >> numbToInput.main_part).get();
        std::cout << "введем мнимую часть: ";
       (is >> numbToInput.comp).get();
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Compl& numbToOutput) {
        os << numbToOutput.main_part << " + i*" << numbToOutput.comp<< "; ";
        return os;
    }
};

#endif /* Complex_h */
