#include <iostream>
#include <string>
#include "ques3-fishes.h"
FishTank ft;
using namespace std;
void add(){
    string sp;
    char gen;
    double wt;
    cout<<"enter the specie of fish: ";
    cin>>sp;
    cout<<"enter its gender, for male enter m and for female enter f: ";
    cin>>gen;
    cout<<"enter its weight: ";
    cin>>wt;
    Fish f(sp,gen,wt);
    ft.addFish(f); 
}
void feedAll(){
    ft.feedFish();
}
void feedOne(){
    string sp;
    cout<<"enter the species of fish you wanna feed: ";
    cin>>sp;
    ft.feedFish(sp);
}
void numberFishes(){
    cout<<"total fishes in tank are "<<ft.getTotalFish()<<endl;
}
void maxWeight(){
    Fish f;
    string sp;
    cout<<"enter the specie of which you want to find the maximum weight: \n";
    cin>>sp;
    f=ft.getFishHighestWeight(sp);
    cout<<"the maximum weight of fish of specie "<<sp<<" is "<<f.weight<<endl;
    cout<<"the gender of fish of specie "<<sp<< " is "<<f.gender<<endl;
}
void reproduce(){
    ft.reproduceFish();
}
void loadtank(){
    ft.loadFishTank();
}
int main(){
    while (true){
        int choice=1;
        cout<<"***************************WELCOME TO MY FISH WORLD***************************\n";
        cout<<"Choose an operation to perform\n";
        cout<<"1. Add a fish to tank\n";
        cout<<"2. Feed All Fishes\n";
        cout<<"3. Feed a particular specie of fish\n";
        cout<<"4. Get total number of fishes\n";
        cout<<"5. Get the fish of a particular specie having maximum weight\n";
        cout<<"6. Reproduce offsprings\n";
        cout<<"7. Load fish tank\n";
        cout<<"8. Exit\n";
        int user;
        cin>>user;
        switch (user){
            case 1:
                add();
                break;
            case 2:
                feedAll();
                break;
            case 3:
                feedOne();
                break;
            case 4:
                numberFishes();
                break;
            case 5:
                maxWeight();
                break;
            case 6:
                reproduce();
                break;
            case 7:
                loadtank();
                break;
            case 8:
                choice=0;
                break;
            default:
                cout<<"Wrong input added!!\n";
        }
        if(choice==0){
            cout<<"thanks for visiting my fish tank , see you again. bye!\n";
            break;
        }
    }
    return 0;
}