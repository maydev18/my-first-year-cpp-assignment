
#include <iostream>
#include <string>
using namespace std;
class Fish{
    public:
        string specie;
        char gender;
        double weight;
        Fish();
        Fish(string s, char g , double w);
        void showSpecie();
        void showGender();
        void showWeight();
        //*****************************************************************************************************************
        //contributed by shashwat sahil mayank manav navjot ishita saumya bableen swasti karam and coding team. if you want to be a part of our team please dm all the boys here.
        //*****************************************************************************************************************
        void changeSpecie(string s);
        void changeGender(char g);
        void changeWeight(double w);
        void feed();
        void toString();
};

Fish::Fish(){
    specie = "guppy";
    gender = 'm';
    weight = 1.0;
}
Fish::Fish(string s, char g , double w){
    specie = s;
    gender = g;
    weight = w;
}
void Fish::showSpecie(){
    cout << "the specie of fish is " << specie << endl;
    return;
}
void Fish::showGender(){
    if(gender=='m') cout<<"gender of fish is male"<<endl;
    else cout<<"gender of fish is female"<<endl;
    return;
}
void Fish::showWeight(){
    cout<<"the weight of fish is "<<weight<<" grams"<<endl;
    return;
}
void Fish::changeSpecie(string s) {specie=s;}
void Fish::changeGender(char g) {gender=g;}
void Fish::changeWeight(double w) {weight=w;}

void Fish::feed(){
    weight=weight+(0.1*weight);
    return;
}
void Fish::toString(){
    cout<<"The description of fish is as follows"<<endl;
    cout<<"The specie of fish is "<<specie<<endl;
    if(gender=='m') cout<<"The gender of fish is male"<<endl;
    else cout<<"The gender of fish is female"<<endl;
    cout<<"the weight of fish is "<<weight<<" grams"<<endl;
    return;
}
class FishTank:public Fish{
    protected:
        Fish fishArray[500];
        string specieArray[500];
        int species=0;
        int totalFish=0;
    public:
        void addFish(const Fish & f);
        void feedFish();
        void feedFish(string sp);
        int getTotalFish();
        Fish getFishHighestWeight(string sp);
        void reproduceFish();
        int getMaleCount(string sp);
        int getFemaleCount(string sp);
        void loadFishTank();

};
void FishTank::addFish(const Fish & f){
    try{
        if (totalFish>500){
            throw totalFish;
        }
        bool present=false;
        for(int i=0 ; i<totalFish ; i++){
            if(fishArray[i].specie==f.specie){
                present=true;
                break;
            }
        }
        if(present==false){
            specieArray[species++]=f.specie;
        }
        fishArray[totalFish++]=f;
        cout<<"Fish has been added\n";
    }
    catch(int x){
        cout<<"cannot add more fishes limit of fish tank exceeded!!\n";
    }
}
void FishTank::feedFish(){
    for(int i=0 ; i<totalFish ; i++){
        fishArray[i].weight = fishArray[i].weight+(fishArray[i].weight*0.1);
    }
    cout<<"all fishes are successfully feeden\n";
}
void FishTank::feedFish(string sp){
    for(int i=0 ; i<totalFish ; i++){
        if(fishArray[i].specie==sp){
            fishArray[i].weight = fishArray[i].weight+(fishArray[i].weight*0.1);
        }
    }
    cout<<sp<<" species has been feeden up\n";
}
int FishTank::getTotalFish(){
    return totalFish;
}
Fish FishTank::getFishHighestWeight(string sp){
    Fish f;
    for(int i=0 ; i<totalFish ; i++){
        if(fishArray[i].weight>f.weight && fishArray[i].specie==sp){
            f=fishArray[i];
        }
    }
    return f;
}
int FishTank::getFemaleCount(string sp){
    int count=0;
    for(int i=0 ; i<totalFish ; i++){
        if(fishArray[i].specie==sp && fishArray[i].gender=='f') count++;
    }
    return count;
}
int FishTank::getMaleCount(string sp){
    int count=0;
    for(int i=0 ; i<totalFish ; i++){
        if(fishArray[i].specie==sp && fishArray[i].gender=='m') count++;
    }
    return count;
}
void FishTank::reproduceFish(){
    for(int i=0 ; i<species ; i++){
        int males=getMaleCount(specieArray[i]);
        int females=getFemaleCount(specieArray[i]);
        if(males==0) continue;
        else{
            int totalOffSpring=females*6;
            for(int j=0 ; j<totalOffSpring/2 ; j++){
                Fish f(specieArray[i],'m',1.0);
                addFish(f);
            }
            for(int j=0 ; j<totalOffSpring/2 ; j++){
                Fish f(specieArray[i],'f',1.0);
                addFish(f);
            }
        }
    }
    cout<<"fishes have reproduced\n";
}
void FishTank::loadFishTank(){
    if (totalFish==0){
        cout<<"your fish tank is empty, add some fishes to see them\n";
        return;
    }
    for(int i=0 ; i<totalFish ; i++){
        cout<<"specie= "<<fishArray[i].specie<<" | "<<"gender= "<<fishArray[i].gender<<" | "<<"weight= "<<fishArray[i].weight<<endl;
    }
}

