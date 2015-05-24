#include "board.h"

User::User(string u, string p, int i, userType t, fstream &eff){
 id = i;
 username = u;
 password = p;
 type = t;
 f = &eff;
 load();
}

void User::postMessage(string message){
 int count = 0;
 string messages;
 f->open("messages.txt");
 while(*f >> messages){
  *f << messages << endl;
  count+=1;
 }
 *f << message << endl;
 mIndexes.push_back(count);
}

void User::deleteMessage(int i){
 int count = 0;
 string messages;
 f->open("messages.txt");
 while(count < i){
  *f >> messages;
  *f << messages << endl;;
  count+=1;
 }
 *f >> messages;
 while(*f >> messages){
  *f << messages << endl;
 }
}


void User::viewAll(){
 string messages;
 while(*f >> messages){
  cout << messages << endl;
  *f << messages << endl;
 }
}

void User::postAd(string message, string link){

}

void User::deleteAd(int i){

}

void User::viewAds(){

}

void User::allUsers(){

}

void User::messagesBy(string username){

}

void User::deleteUser(string username){

}

void User::load(){

}
