#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//usertype 0 = admin, usertype 1 = business, usertype 2 = general user

class User{
 public:
  //Constructor
  User(string u, string p, int i, int t, ifstream &iff, ofstream &off);
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
  void viewMessage(int i);
  void messagesBy(string user);
  void deleteUser(string user);
  string getUName();
  string getPWord();
  int getID();
  int getType();
  vector<int> getIndexes();
  void load();
 private:
  int id;
  string username;
  string password;
  int type;
  vector<int> mIndexes;
  ifstream* fin;
  ofstream* fout;
  //Loads messages or advertisements
};

#endif
