#include<iostream>
using namespace std;

string encode(string k , string s){
    string text = "";

    for(int i = 0 ; i < s.length() ; i++){
        text += char( (( int(k[i] - 97 ) ) +( int(s[i] - 97 ) ) )%26 + 97);
    }
    
    return text;
}

string decode (string k , string s){
    string text = "";

    for(int i = 0 ; i < s.length() ; i++){
        text += char( ( ( int(s[i] - 97 ) ) - ( int(k[i] - 97 ) ) )%26 + 97);
    }

    return text;
}


int main(){
    // string keyword = "deceptivedeceptivedeceptive";
    // string plainText = "wearediscoveredsaveyourself";

    // string keyword =   "deceptivewearediscoveredsav";
    // string plainText = "wearediscoveredsaveyourself";

    string keyword =   "jaishreeram";
    string plainText = "abcdefghijk";

    string cipherText = encode(keyword, plainText);
    cout<<cipherText<<endl;

    plainText = decode(keyword , cipherText);
    cout<<plainText<<endl;


    return 0;
}