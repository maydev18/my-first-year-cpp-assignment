#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream input;
    input.open("input.txt");
    if (!input){
        cerr<<"ERROR opening the file to read data\n";
        exit(100);
    }
    ofstream output;
    output.open("output.txt");
    if(!output){
        cerr<<"ERROR opening the file to write data\n";
        exit(100);
    }
    string s("");
    char ch;
    while(input.get(ch)){
        s+=ch;
    }
    string number("");
    int count = 0;
    string digits("0123456789");
    for(int i=0 ; i<s.length() ; i++){
        if(digits.find(s[i])!=string::npos){
            count++;
            number+=s[i];
        }
        else{
            count=0;
            number="";
        }
        if(count==10){
            output<<number;
            output<<" ";
        }
    }
    input.close();
    output.close();
    if(input.fail() || output.fail()){
        cerr<<"error closing the file\n";
        exit(102);
    }
    return 0;
}