#include "board.h"

int main(int argc, char* argv[]){
 ifstream fin;
 ofstream fout;
 User user("Bhernandez-cs", "mangoes", 777, general, fin, fout);
 user.postMessage("abc");
 user.postMessage("def");
 user.postMessage("g");
 user.deleteMessage(3);
 user.viewAll();
 return 0;
}
