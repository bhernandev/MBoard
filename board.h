#ifndef MBOARD
#define MBOARD

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum userType{
 admin,
 business,
 general
};

class User{
 public:
  //Constructor
  User(string u, string p, int i, userType t, fstream &eff);
  //General User Methods
  void postMessage(string message);
  void deleteMessage(int i);
  void viewAll();
  //Business Methods
  void postAd(string message, string link);
  void deleteAd(int i);
  void viewAds();
  //Admin Methods
  void allUsers();
  void messagesBy(string username);
  void deleteUser(string username);
 private:
  int id;
  string username;
  string password;
  userType type;
  vector<int> mIndexes;
  fstream* f;
  //Loads messages or advertisements
  void load();
};

#endif
