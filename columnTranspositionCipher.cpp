#include<iostream>
#include<map>
using namespace std;

string key = "HACK";
map<int,int>mp;

void setpermutation(){

    for(int i = 0 ; i < key.length() ; i++){
        mp[key[i]] = i;
    }

    for(auto itr = mp.begin() ; itr!= mp.end() ; itr++){
        cout<< itr->first<<" "<< itr->second <<endl;
    }
  
}

string encrypt(string msg){

    int row,col,j;
    string cipher = "";

    col = key.length();
    row = msg.length()/col;

    if(msg.length() % col )
      row += 1;

    // cout<<"Rows"<<row<<"  Len"<<msg.length()<<" col "<<col<<endl;

    char mat[row][col];

    for(int i = 0 , k = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ;){

            if(msg[k] == '\0'){
                mat[i][j] = '_';
                j++;
            }

            if(isalpha(msg[k]) || msg[k] == ' '){
                mat[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }

    for(auto itr = mp.begin() ; itr != mp.end() ; itr++){
        j = itr->second;

        for(int i = 0 ; i < row ; i++){
            if( isalpha(mat[i][j]) || mat[i][j] == ' ' || mat[i][j] == '_' )
            cipher += mat[i][j];
        }
    }


    return cipher;

}

string decrypt(string cipher)
{

    int col = key.length();  
    int row = cipher.length()/col;
    char mat[row][col];
  
    for (int j=0,k=0; j<col; j++)
        for (int i=0; i<row; i++)
          mat[i][j] = cipher[k++];
  

    int index = 0;
    for( auto itr=mp.begin(); itr!=mp.end(); itr++)
        itr->second = index++;
  

    char decCipher[row][col];
    auto itr=mp.begin();
    int k = 0;
    for (int l=0,j; key[l]!='\0'; k++)
    {
        j = mp[key[l++]];
        for (int i=0; i<row; i++)
        {
            decCipher[i][k]=mat[i][j];
        }
    }
  
    string msg = "";
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                msg += decCipher[i][j];
        }
    }
    return msg;
}

int main(){
    string msg = "kill everyone";
    setpermutation();
    string cipherText = encrypt(msg);
    cout<<"Cipher text : "<<cipherText<<endl;
    string plainText = decrypt(cipherText);
    cout<<"Plain text : "<<plainText<<endl;
    return 0;
}