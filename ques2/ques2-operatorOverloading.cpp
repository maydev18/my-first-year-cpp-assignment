#include <iostream>
#include "ques2-operatorOverloading.h"
using namespace std;
int main(){
    Money m1(4.56);
    Money m2(6.23);
    m1.print();
    m2.print();
    Money m3=m1+m2;
    m3.print();
    m3=m1-m2;
    m3.print();
    m1*=4;
    m1.print();
    m2/=3;
    m2.print();
    cout<<(m1>m2)<<endl;
    cout<<(m1<m2)<<endl;
    cout<<(m1==m2)<<endl;
    cout<<(m1!=m2)<<endl;
}