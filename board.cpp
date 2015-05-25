#include "board.h"

User::User(string u, string p, int i, userType t, ifstream &iff, ofstream &off){
 id = i;
 username = u;
 password = p;
 type = t;
 fin = &iff;
 fout = &off;
 load();
}

void User::postMessage(string message){
 int count = 0;
 string m;
 vector<string> v;
 fin->open("messages.txt");
 while(*fin >> m){
  v.push_back(m);
  count++;
 }
 fin->close();
 fout->open("messages.txt");
 for(int i = 0; i < v.size(); i++){
  *fout << v[i] << endl;
 } 
 *fout << username + "___says___" + message << endl;
 fout->close();
 mIndexes.push_back(count);
}

void User::deleteMessage(int i){
 int count = 0;
 string m;
 vector<string> v;
 fin->open("messages.txt");
 while(count < i){
  *fin >> m;
  v.push_back(m);
  count++;
 }
 *fin >> m;
 v.push_back("deleted");
 while(*fin >> m){
  v.push_back(m);
 }
 fin->close();
 fout->open("messages.txt");
 for(int i = 0; i < v.size(); i++){
  *fout << v[i] << endl;
 }
 fout->close();
}


void User::viewAll(){
 fin->open("messages.txt");
 string m;
 while(*fin >> m){
  cout << m << endl;
 }
 fin->close();
 fin->open("advertisements.txt");
 while(*fin >> m){
  cout << m << endl;
 }
 fin->close();
}

void User::postAd(string message, string link){
 int count = 0;
 string m;
 vector<string> v;
 fin->open("advertisements.txt");
 while(*fin >> m){
  v.push_back(m);
  count++;
 }
 fin->close();
 fout->open("advertisements.txt");
 for(int i = 0; i < v.size(); i++){
  *fout << v[i] << endl;
 }
 *fout << message + "___at___" + link << endl;
 fout->close();
 mIndexes.push_back(count);  
}

void User::deleteAd(int i){
 int count = 0;
 string m;
 vector<string> v;
 fin->open("advertisements.txt");
 while(count < i){
  *fin >> m;
  v.push_back(m);
  count++;
 }
 *fin >> m;
 v.push_back("deleted");
 while(*fin >> m){
  v.push_back(m);
 }
 fin->close();
 fout->open("advertisements.txt");
 for(int i = 0; i < v.size(); i++){
  *fout << v[i] << endl;
 }
 fout->close();
}

void User::viewAds(){
 string m;
 fin->open("advertisements.txt");
 while(*fin >> m){
  cout << m << endl;
 }
 fin->close();
}

void User::allUsers(){
 
}

void User::messagesBy(string username){
 
}

void User::deleteUser(string username){

}

void User::load(){
 fin->open("indexes.txt");
 int i;
 while(*fin >> i){
  if(i == id){
   while(*fin >> i){
    if(i == id){
     break;
    }
    mIndexes.push_back(i);
    cout << i << endl;
   }
   break;
  }
 }
 fin->close();
}
