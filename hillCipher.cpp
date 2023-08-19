#include<iostream>
using namespace std;

// 2 X 2 hill cipher

string final = "";
string finald = "";

void encrypt (string s , int key[2][2]){

    int mat[2][1] = {{int(s[0] - 97) %26} , {int(s[1] - 97) %26}};

    string ans = "";

    ans += char( ((key[0][0]*mat[0][0]) + (key[0][1]*mat[0][0]))%26 + 97 );
    ans+= char( ((key[1][0]*mat[1][0]) + (key[1][1]*mat[1][0]))%26 + 97 );

    cout<<ans;
    final += ans;
    
}

void decrypt(string s , int key[2][2]){
    int mat[2][1] = {{int(s[0] - 97) %26} , {int(s[1] - 97) %26}};

    int det = key[0][0]+key[1][1] - key[0][1]+key[1][0];


    string ans = "";

    int inv[2][2] = { {key[1][1] , -key[0][1]} , {-key[1][0] , key[0][0]} } ;


    ans += char( (((inv[0][0]*mat[0][0]) + (inv[0][1]*mat[0][0])) / det) %26 + 97 );
    ans+= char( (((inv[1][0]*mat[1][0]) + (inv[1][1]*mat[1][0]))/det) %26 + 97 );

    cout<<ans;
    finald += ans;
}

int main(){

    string keyword = "helloo";
    int key[2][2] = {{3,3} , {2,5}};
    
    if(keyword.length()%2 != 0)
    keyword += "x";

    cout<<"Keyword : "<<keyword<<endl;

    string s = "";

    cout<<"Encrypted Text : ";
    for(int i = 1 ; i <= keyword.size() ; i++){
        s += keyword[i-1];

        if(i % 2 == 0 ){  
        encrypt(s, key);
        s = "";
        }
    }
    cout<<endl;

    s = "";

    cout<<"Decrypted Text : ";
    for(int i = 1 ; i <= final.size() ; i++){
        s += final[i-1];

        if(i % 2 == 0 ){  
        decrypt(s, key);
        s = "";
        }
    }
    cout<<endl;

    return 0;
}