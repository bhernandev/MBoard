#include "board.h"

User::User(string u, string p, int i, int t, ifstream &iff, ofstream &off){
 id = i;
 username = u;
 password = p;
 type = t;
 fin = &iff;
 fout = &off;
 vector<int>* mPoint = &mIndexes;
 User::load();
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
 for(int j = 0; j < mIndexes.size(); j++){
  if(mIndexes[j] == i){
   mIndexes.erase(mIndexes.begin() + j);
  }
 }
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
 for(int j = 0; j < mIndexes.size(); j++){
  if(mIndexes[j] == i){
   mIndexes.erase(mIndexes.begin() + j);
  }
 }
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
 int i = 0;
 string s;
 vector<string> names;
 fin->open("userInfo.txt");
 *fin >> s;
 while(*fin >> s){
  if(i%4 == 0){
   names.push_back(s);
  }
  i++;
 }
 fin->close();
 for(int j; j < names.size(); j++){
  cout << names[j] << endl;
 }
}

void User::viewMessage(int i){
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
 fin->close();
 cout << m << endl;
}

void User::messagesBy(string user){
 int i;
 int uID;
 string uComp;
 bool uExists = false;
 vector<int> inds;
 fin->open("userInfo.txt");
 *fin >> uComp;
 while(*fin >> uComp){
  if(uComp == user){
   uExists = true;
   *fin >> uComp;
   *fin >> uID; //gives us the id as an int
  }
 }
 fin->close();
 if(!uExists){
  cout << "Error: Could not find username specified" << endl;
 }
 else{
  fin->open("indexes.txt");
  while(*fin >> i){
   if(i == uID){
    while(*fin >> i){
     if(i == uID){
      break;
     }
     inds.push_back(i);
    }
   }
  }
  fin->close();
  for(int j = 0; j < inds.size(); j++){
   viewMessage(inds[j]);
  }
 }
}

void User::deleteUser(string user){
 string s;
 vector<string> info;
 fin->open("userInfo.txt");
 while(*fin >> s){
  if(s == user){
   info.push_back("deleted");
   for(int j = 0; j < 3; j++){
    *fin >> s;
    info.push_back("deleted");
   }
  }
  else{
  info.push_back(s);
  }
 }
 fin->close();
 fout->open("userInfo.txt");
 for(int j = 0; j < info.size(); j++){
  *fout << info[j] << endl;
 }
 fout->close();
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
   }
  }
 }
 fin->close();
}

string User::getUName(){
 return username;
}

string User::getPWord(){
 return password;
}

int User::getID(){
 return id;
}

int User::getType(){
 return type;
}

vector<int> User::getIndexes(){
 return mIndexes;
}
