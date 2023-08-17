#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<char ,  char > mp;

void linkMap(string a , string b){

    mp.clear();

    for(int i = 0 ; i < a.size() ; i++){
        mp.insert(make_pair(a[i] , b[i]));
    }

}

string encrypt(string msg){
  
  string ciphertext;
  for(int i=0; i<msg.size(); i++)
  {
    ciphertext.push_back(mp[msg[i]]);
  }
  
  return ciphertext;
}

string decrypt(string msg){

  string plainText;
  for(int i=0; i<msg.size(); i++)
  {
    plainText.push_back(mp[msg[i]]);
  }
  
  return plainText;
}

int main(){

    string alphabet =   "abcdefghijklmnopqrstuvwxyz";
    string substitute = "bcdefghijklmnopqrstuvwxyza";

    // string substitute = "zyxwvutsrpqonmlkjihgfedcba";

    string msg = "abcd";

    linkMap(alphabet, substitute);

    string cipher = encrypt(msg);
    cout<<"Encrypted : "<<cipher<<endl;

    linkMap(substitute , alphabet);
    string text = decrypt(cipher);
    cout<<"Decrypted : "<<text<<endl;

    return 0;
}