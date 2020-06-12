//
//  main.cpp
//  Laba2final
//
//  Created by Анна Потёмкина on 29.05.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Vector.h"
#include "Complex.h"
using namespace std;

void testArray();
void testList();

const int SIZE = 10;

Compl* getCompl() {
    int a = 0,
        b = 0;
    do {
        a = rand() % 5 + 1;
        b = rand() % 5 + 1;
    } while (a <= b);
    auto h = new Compl(a,b);
    return h;
}


template <typename TypeSeq, typename ft>
void map(TypeSeq& seq, ft function) {
    for (size_t i = 0; i < seq.Length(); ++i) {
        function(seq.GetElem(i));
    }
}

//сортировка независимо от типа
template <typename TypeSeq, typename ft>
void sort(TypeSeq& inputSeq, ft f) {
    for (size_t i = 0; i < inputSeq.Length() - 1; i++) {
        for (size_t j = i + 1; j < inputSeq.Length(); j++) {
            auto& dub1 = inputSeq.GetElem(i);
            auto& dub2 = inputSeq.GetElem(j);
            if (f(dub1, dub2)) {
               /* auto dub = dub1;
                dub1=dub2;
                dub2=dub;*/
                inputSeq.Swap(i,j);
            }
        }
    }
}

template <typename TypeSeq, typename T, typename ft>
T reduce(TypeSeq inputSeq, T start, ft f) {
    T dub = f(start, inputSeq.GetElem(0));
    for (size_t i = 1; i < inputSeq.Length(); ++i) {
        dub = f(dub, inputSeq.GetElem(i));
    }
    return dub;
}

template <typename TypeSeq, typename TypeSubseq, typename ft>
TypeSubseq where(TypeSeq inputSeq, ft f) {
    TypeSubseq dub;
    for (size_t i = 0; i < inputSeq.Length(); i++) {
        if (f(inputSeq.GetElem(i))) {
            dub.Append(inputSeq.GetElem(i));
        }
    }
    return dub;
}

int main(int argc, const char * argv[]) {
    Array<int> Obj;
    for (int i=0; i<3;++i){
        Obj.append(i);
    }
    Obj.resize(5);
    cout<<Obj.length()<<endl;
    List<string> Obj3;
    string x;
    for (long i = 6; i >= 1; --i) {
        cin >> x;
        Obj3.append(x);
    }
    if (Obj3.PolCheck()==true){
        cout<<" polindrom "<<endl;
    }
    else{
        cout<<"not polindrom "<<endl;
    }
   Vector<double> Vec1("arraySequence");
    int a = 0, b = 0;
     for (unsigned int i = 0; i < SIZE; ++i) {
         a = rand() % 1000 - 500;
         b = rand() % 1000 - 500;
         double c = (double)a / b;
         if (i < 4) {
             Vec1.Prepend(c);
         }
         else {
             Vec1.Append(c);
         }
     }
    
   Vector<double> Vec2("listSequence");
    int g = 0, m = 0;
     for (unsigned int i = 0; i < SIZE; ++i) {
         g = rand() % 1000 - 500;
         m = rand() % 1000 - 500;
         double p = (double)g / m;
         if (i < 4) {
             Vec2.Prepend(p);
         }
         else {
             Vec2.Append(p);
         }
     }
   // Vector<double> Vec2(Vec1);
    cout<< Vec1<< endl;
    cout << Vec2<< endl;
    Vec1=Vec1+Vec2;
    cout<<Vec1<<endl;
    
    Vector<double> d("arraySequence");
    int z=0;
    for (long i = 10; i >= 1; --i) {
         z = rand() % 100 - 10;
        d.Append(z);
    }
    cout << d<< endl;;
    sort(d, [](double a, double b) {
    return a > b;
    });
    cout<< d<<endl;
    
    double ElReduce = reduce<Vector<double>, double>(d, 100, [](double ElChange, double ElVec) {
    return ElChange + ElVec;
    });
    cout << ElReduce <<endl;
    cout << d<< endl;;
    Vector<double> v = where<Vector<double>, Vector<double>>(d, [](double ElemChange) {
    return ElemChange > 6;
    });
    cout << v<< endl;
    testArray();
    testList();
    
    Vector<Compl*> veccomp("arraySequence");
    for (size_t i = 0; i < SIZE; i++)
    {
        Compl com;
        cin >> com;
        Compl* com1 = new Compl(com.GetMain(), com.GetComp());
        veccomp.Append(com1);
        veccomp.Prepend(getCompl());
    }
    cout << "вектор комплексных " <<endl;
    map(veccomp, [](Compl* com) {
    cout << *com;
    });
    
    cout << "Проверим работу некоторых методов "<< endl;
    veccomp.Pop(3);
    veccomp.Swap(1, 2);
    cout<<" удалили 3 элемент и поменяли первый и второй местами"<< endl;
    map(veccomp, [](Compl* com) {
       cout << *com;
       });
   sort(veccomp, [](Compl* a, Compl* b) {
       return a->GetMain()> b->GetMain();
    });
    cout <<"отсортированный вектор "<<endl;
    map(veccomp, [](Compl* com) {
    cout << *com;
    });
    *veccomp[0]=*veccomp[0]+*veccomp[1];
    cout<< "сложим 0 и 1: "<< *veccomp.GetElem(0)<<endl;
    veccomp.Remove();
    cout<< "длина после удаления: "<< veccomp.Length()<<endl;
    testList();
    }

void testArray() {

Vector<double> Vec1("arraySequence");
cout << "возьмем за основу массив и протестируем методы" << endl;
cout << "создадим вектор, генерируя случайные числа: " << endl << endl;
cout << "проверим добавление и вывод" << endl;
int a = 0, b = 0;
for (unsigned int i = 0; i < SIZE; ++i) {
    a = rand() % 1000 - 500;
    b = rand() % 1000 - 500;
    double c = (double)a / b;
    if (i < 4 ) {
        Vec1.Prepend(c);
    }
    else {
        Vec1.Append(c);
    }
}

cout << Vec1 << endl << endl;
cout << "протестируем методы класса вектор" << endl;
cout << "длина вектора: " << Vec1.Length() << "  есть ли хоть один элемент? " << Vec1.Check_vec() << endl << endl;
    cout << "последний элемент вектора: " << Vec1.GetEnd();
unsigned long int index = rand() % 10;
cout << "элемент с индексом " << index << ": " << Vec1.GetElem(index) << endl << endl;
index = 1;
cout << "индекс элемента " << Vec1.GetElem(index) << ":  " << Vec1.GetIndex(Vec1.GetElem(index)) << endl << endl;
    
    Vec1.Pop(3);
       cout << "удаление элемента по номеру  " << Vec1 << endl;
    Vec1.Swap(1, 0);
    cout << "поменяем два элементра местами  " << Vec1 <<endl;
    Vec1.Sorting();
     cout << "отсортировали " << Vec1 <<endl;
    double c=1.45655;
       Vec1.Insert(c, 3);
       cout << "вставим новый элемент "<<Vec1 <<endl;
    cout<<"создадим еще один вектор "<<endl;
    Vector<double> Vec2(Vec1);
    cout<< "Проверим конкатенацию "<<endl;
    Vec1=Vec1+Vec2;
    cout << "Выведем новую длину: "<< Vec1.Length()<<endl;
    cout <<"ввыведем новый вектор "<< Vec1<<endl;
    Vec1.Remove();
    Vec2.Remove();
    cout<<"длины векторов после удаления: "<< Vec1.Length() << " "<< Vec2.Length() <<endl;
    
}

    void testList() {
  
    Vector<double> Vec1("listSequence");
    cout << "возьмем за основу список и протестируем методы" << endl;
    cout << "составим вектор из случайных чисел " << endl;
    cout << "проверим ввод и вывод" << endl;
    int a = 0, b = 0;
    for (unsigned int i = 0; i < SIZE; ++i) {
        a = rand() % 1000 - 500;
        b = rand() % 1000 - 500;
        double c = (double)a / b;
        if (i < 4) {
            Vec1.Prepend(c);
        }
        else {
            Vec1.Append(c);
        }
    }
    cout << Vec1 << endl << endl;
    cout << "проверим все методы класса Вектор " << endl;
    cout << "длина вектора: " << Vec1.Length() << "есть ли хотя бы 1 элемент? " << Vec1.Check_vec() << endl << endl;
    cout << "последний элемент вектора: " << Vec1.GetEnd() << endl << endl;
    unsigned long int index = 1;
    cout << "элемент с индексом  " << index << ": " << Vec1.GetElem(index) << endl << endl;
    index = 2;
    cout << "индекс элемента  " << Vec1.GetIndex(index) << ":  " << Vec1.GetIndex(Vec1.GetElem(index)) << endl << endl;
    Vec1.Pop(3);
    cout << "удаление элемента по номеру  " << Vec1 << endl;
    Vec1.Swap(1, 0);
    cout << "поменяем два элементра местами  " << Vec1 <<endl;
    double  y=1.3456;
    Vec1.Insert(y, 3);
    cout << "вставим новый элемент  ";
        cout << "вставим новый элемент  "<<Vec1 <<endl;
        cout<<"создадим еще один вектор  "<<endl;
        Vector<double> Vec2(Vec1);
        cout<< "Проверим конкатенацию  "<<endl;
       Vec1=Vec1+Vec2;
        cout << "Выведем новую длину: "<< Vec1.Length()<<endl;
        cout <<"ввыведем новый вектор "<< Vec1<<endl;
        Vec1.Remove();
        Vec2.Remove();
        cout<<"длины векторов после удаления: "<< Vec1.Length() << " "<< Vec2.Length() <<endl;
 }



  
