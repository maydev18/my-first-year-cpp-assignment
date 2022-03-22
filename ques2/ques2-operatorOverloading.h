#include <iostream>
#include <math.h>
using namespace std;

class Money{
    private:
        double money;
    public:
        Money();
        Money(double money);
        void print()const;
        Money operator+(const Money & m) const;
        Money operator-(const Money & m) const;
        void operator *=(int n);
        void operator /= (int n);
        bool operator <(const Money & m) const ;
        bool operator >(const Money & m) const ;
        bool operator ==(const Money & m) const ;
        bool operator !=(const Money & m) const ;
};
Money::Money(){
    this->money=0;
}
Money::Money(double money){
    this->money = money;
}
void Money::print()const{
    int rupee=floor(money);
    float paise=money-floor(money);
    cout<<rupee<<" rupees and "<<paise*100<<" paise "<<endl;
}
Money Money::operator+(const Money & m) const {
    return Money(this->money+m.money);
}
Money Money::operator-(const Money & m) const {
    if(this->money>m.money){
        return Money(this->money-m.money);
    }
    else{
        return Money(m.money-this->money);
    }
}
void Money::operator*=(int n){
    this->money=this->money*n;
}
void Money::operator/=(int n){
    this->money=this->money/n;
}
bool Money::operator > (const Money & m)const{
    if(this->money>m.money){
        return true;
    }
    else{
        return false;
    }
}
bool Money::operator < (const Money & m)const{
    if(this->money>m.money){
        return false;
    }
    else{
        return true;
    }
}
bool Money::operator == (const Money & m)const{
    if(this->money==m.money){
        return true;
    }
    else{
        return false;
    }
}
bool Money::operator != (const Money & m)const{
    if(this->money==m.money){
        return false;
    }
    else{
        return true;
    }
}