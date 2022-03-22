#include <iostream>
#include <string>
using namespace std;
class PigLatin{
    public:
        PigLatin(){}
        string convertPigLatin(string & str);
        string convertPigLatinUpper(string & str);
        string convertPigLatinSentence(string & str);

};
string PigLatin::convertPigLatin(string & str){
    if(str=="") return ""; //checking if string is null
    string vowel="aeiou";
    string cons="";
    string s1="";
    if(vowel.find(str[0])==string::npos){ //it is a consonant
        for(int i=0 ; i<str.length() ; i++){
            if(vowel.find(str[i])!=string::npos){
                s1 = str.substr(i);        
                break;
            }
            else{
                cons+=str[i];
            }
        }
        return s1+cons+"ay";

    }
    else{
        if(vowel.find(str[str.length()-1])!=string::npos){ //last char is a vowel
            cout<<"y"+str+"yay"<<endl;
        }
        else{
            return "y"+str+"ay";
        }
    }
}
string PigLatin::convertPigLatinUpper(string & str){
    if(str=="") return ""; //checking if string is null
    string vowel="AEIOU";
    string cons="";
    string s1="";
    if(vowel.find(str[0])==string::npos){ //it is a consonant
        for(int i=0 ; i<str.length() ; i++){
            if(vowel.find(str[i])!=string::npos){
                s1 = str.substr(i);        
                break;
            }
            else{
                cons+=str[i];
            }
        }
        return s1+cons+"AY";

    }
    else{
        if(vowel.find(str[str.length()-1])!=string::npos){ //last char is a vowel
            return "Y"+str+"YAY";
        }
        else{
            return "Y"+str+"AY";
        }
    }
}
string PigLatin::convertPigLatinSentence(string & str){
    string word("");
    string ans("");
    for(int i=0 ; i<=str.size() ; i++){
        if(i==str.size()){
            ans+=convertPigLatin(word);
        }
        else if(str[i]==' '){
            ans+=convertPigLatin(word);
            word="";
            ans+=' ';
        }
        else if(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))){
            ans+=convertPigLatin(word);
            word="";
            ans+=str[i];
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            word+=str[i];
        }
    }
    return ans;
}
int main(){
    PigLatin p;
    string s1="orange";
    cout<<p.convertPigLatin(s1)<<endl;
    s1="ball";
    cout<<p.convertPigLatin(s1)<<endl;
    s1="The quick brown fox...";
    cout<<p.convertPigLatinSentence(s1)<<endl;
    s1="This can't be er... true";
    cout<<p.convertPigLatinSentence(s1)<<endl;
    return 0;
}