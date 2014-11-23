#include "Array.h"
/*методы для сложения и вычитания масисвов я не писал, по скольку не очень понял смысл перегрузки поераторов + и -,
то ли они хотелс сложить два массива, тогда все ок, но как из одного вычесть лдругой я честно говоря не понимаю, поэтому
написал методы просто для увеличения и уменьшения массива на некоторое количчество элементов*/
Array::Array(int n) {
    cout<< "\tконструктор для "<< this<<endl;
    if(n>=1) {
        count=0;
        size=n;
        p=(int*)malloc(n*sizeof(int));
    } else {
        cout<<"\terror неверный размер массива\n";
    }
    //ctor
}

Array::Array(const Array& Ar) {
    size=Ar.size;
    count=0;
    p=(int*)malloc(size*sizeof(int));
    for(int i=0; i<size; ++i) {
        p[i]=Ar.p[i];
    }
}

void Array::operator+(int n) {
    if(p!=NULL) {
        p=(int*)realloc( p, (size+n)*sizeof(int));
        size+=n;
    } else {
        cout<<"\terror\n";
    }
}

void Array::operator-(int n) {
    if(p!=NULL&&n<size) {
        p=(int*)realloc(p, (size-n)*sizeof(int));
        size-=n;
    } else {
        cout<<"\terror\n";
    }

}

void Array::operator++() {
    if(p!=NULL) {
        p=(int*)realloc(p, (size+1)*sizeof(int));
        size++;
    } else {
        cout<<"\terror\n";
    }
}

void Array::operator--() {
    if(p!=NULL&&size<=2) {
        p=(int*)realloc(p, (size-1)*sizeof(int));
        size--;
    } else {
        cout<<"\terror\n";
    }
}

int Array::operator[](int i)const {
    if(p!=NULL&&(i<size&&i>=0)) {
        return p[i];
    } else {
        cout<<"\terror\n";
        return 1;
    }
}
void Array::print()const {
    if(p!=NULL) {
        for(int i=0; i<size; ++i) {
            cout<< "\t"<<p[i]<<endl;
        }
        cout<<endl;
    } else {
        cout<< "\terror\n";
    }
}
Array::~Array() {
    cout<< "\tдеструктор для "<< this<<endl;
    free(p);
    //dtor
}
