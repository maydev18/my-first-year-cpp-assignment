#include <iostream>
using namespace std;
class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        Time();
        Time(int h,int m, int s);
        void Hour(int h);
        void Min(int m);
        void Sec(int s);
        void print();
        void advance(int h, int m , int s);
        void reset(int h, int m , int s);
};

Time::Time(){
    hour=0;
    min=0;
    sec=0;
}
Time::Time(int h,int m ,int s){
    
    hour=h;
    min=m;
    sec=s;
}
void Time::Hour(int h) {hour=h;}
void Time::Min(int m){min=m;}
void Time::Sec(int s){sec=s;}
void Time::print(){
    cout<<"Current time is "<<hour<<" : "<<min<<" : "<<sec<<endl;
}
void Time::advance(int h, int m , int s){
    if(hour+h>23 || min+m>59 || sec+s>59){
        cout<<"Cannot update time, invalid time after updating"<<endl;
    }
    else{
        hour+=h;
        min+=m;
        sec+=s;
    }
    return;
}
void Time::reset(int h, int m , int s){
    if(hour<0 || hour>23 || m<0 || m>59 || s<0 || s>59){
        cout<<"Error resetting the time, invalid time after resetting!"<<endl;
    }
    else{
        hour=h;
        min=m;
        sec=s;
    }
    return;
}

int main(){
    Time t(1,2,3);
    t.print();
    t.advance(11,2,3);
    cout<<"time after advancing\n";
    t.print();
    t.reset(12,12,12);
    cout<<"time after resetting\n";
    t.print();
    return 0;
}