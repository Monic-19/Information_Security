#include <iostream>
using namespace std;

string encrypt(string normalText , int key){
    string encryptedText;

     for(int i = 0 ; i < normalText.length() ; i++){
      if( isupper(normalText[i]) )
        encryptedText += char( int(normalText[i] + key -65) % 26 + 65);
      else 
        encryptedText += char( int(normalText[i] + key -97) % 26 + 97);
    }

    return encryptedText;

}

string decrypt(string encryptedText , int key){
      string normalText;

     for(int i = 0 ; i < encryptedText.length() ; i++){
      if( isupper(encryptedText[i]) )
        normalText += char( int(encryptedText[i] - key -65) % 26 + 65);
      else 
        normalText += char( int(encryptedText[i] - key -97) % 26 + 97);
    }

    return normalText;
}



int main(){


    string normalText = "abcedf";

    int key;
    cout<<"Enter Key  :  ";
    cin>>key;

    string encryptedText = encrypt(normalText , key);

    cout<<"Normal Text : "<<normalText<<endl;
    cout<<"Key : "<<key<<endl;
    cout<<"Encrypted Text : "<<encryptedText<<endl;

   string decryptedText = decrypt(encryptedText , key);
    cout<<"Decrypted Text : "<<decryptedText<<endl;


    return 0;
}