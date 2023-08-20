#include<iostream>
using namespace std;

string encrypt(string s, int d){

    char mat[d][ (s.length()) ];

    for(int i = 0 ; i < d ; i++){
        for(int j = 0 ; j < s.length() ; j++){
            mat[i][j] = 'b';
        }
    }

    int row = 0;
    int col = 0;
    bool check = false;

    for(int i = 0 ; i < s.length() ; i++){

        if(row == 0 || row == d-1)
          check = !check;
        
        mat[row][col++]=s[i];

        check ? row++ : row--;
    }

    string result;

    for(int i = 0 ; i < d ; i++){
        for(int j = 0 ; j < s.length() ; j++){
          
          if(mat[i][j] != 'b')
            result.push_back(mat[i][j]);

        }
    }

    return result;

}

string decrypt(string s , int d){

    char mat[d][ (s.length()) ];

    for(int i = 0 ; i < d ; i++){
        for(int j = 0 ; j < s.length() ; j++ ){
            mat[i][j] = 'b';
        }
    }

    bool check ;
    int row = 0 ;
    int col = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(row == 0)
          check = true;
        if(row == d-1)
          check = false;

        mat[row][col++] = '*';

        check ? row++ : row--;

    } 
    
    int index = 0;
     for(int i = 0 ; i < d ; i++){
        for(int j = 0 ; j < s.length() ; j++ ){
            
            if(mat[i][j] == '*' && i < s.length() )
              mat[i][j] = s[index++];
        }
    }

    string result;
 
    row = 0, col = 0;
    for (int i=0; i< s.length(); i++)
    {
        if (row == 0)
            check = true;
        if (row == d-1)
            check = false;
 
        if (mat[row][col] != '*')
            result.push_back(mat[row][col++]);
 
        check?row++: row--;
    }
    return result;
}

int main(){
    cout<<"Encryption \n";
    cout<<encrypt("this is the word", 2)<<endl;
    cout<<encrypt("this is the word", 3)<<endl;

    cout<<"Decryption \n";
    cout<<decrypt("ti stewrhsi h od" , 2)<<endl;
    cout<<decrypt("t twhsi h odiser" , 3)<<endl;

    return 0;
}