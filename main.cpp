#include "board.h"

bool usernameExists(string username, ifstream &fin){
 bool exists = false;
 fin.open("userInfo.txt");
 string u;
 while(fin >> u){
  if(u == username){
   exists = true;
  }
 }
 fin.close();
 return exists;
}

void getUsername(string &username, ifstream &fin){
 cout << "Please enter desired username" << endl;
 cin >> username;
 while(usernameExists(username, fin)){
  cout << "Please enter an unused username please" << endl;
  cin >> username;
 }
} 

void save(User user){

}

void mainMenu(User &user){

}

int main(int argc, char* argv[]){
 string a1, a2;
 a1 = argv[1];
 a2 = argv[2];
 ifstream fin;
 ofstream fout;
 string username;
 string password;
 int id;
 userType type;
 if(argc != 3){
  cout << "Error: Must enter username and password after program call" << endl;
  cout << "Example: ./main username password" << endl << endl;
  cout << "For a new user, type in ./main new user, no capitals." << endl;
  return 1;
 }
 else if(a1 == "new"){
  if(a2 == "user"){
   //Username and password creation
   getUsername(username, fin);
   cout << "Please enter desired password" << endl;
   cin >> password;
   //Unique user ID creation
   string s;
   vector<string> info;
   fin.open("userInfo");
   int n;
   fin >> n;
   id = n + 1000;
   n+=1;
   while(fin >> s){
    info.push_back(s);
   }
   fin.close();
   //Writing everything back
   fout.open("userInfo");
   fout << n;
   for(int i = 0; i < info.size(); i++){
    fout << info[i];
   }
   fout.close();
   char c;
   cout << "Please enter 'y' if you would like this to be a business account" << endl;
   cin >> c;
   if(c == 'y'){
    type = business;
   }
   else{
    type = general;
   }
  }
  else{
   // ./main new user not typed in correctly
   return 1;
  }
 }
 else{
 }
 User user(username, password, id, type, fin, fout);
 user.postMessage("abc");
 user.postMessage("def");
 user.postMessage("g");
 //user.deleteMessage(3);
 //user.viewAll();
 return 0;
}
