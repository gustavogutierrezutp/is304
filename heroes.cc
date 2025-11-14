#include <iostream>
#include <string>
#include "hashtable.hh"

using namespace std;

int main() {
  Hashtable heroes(7);
  heroes.insert("Spider-Man", "Green Goblin");
  heroes.insert("Batman", "Joker");
  heroes.insert("Superman", "Lex Luthor");
  heroes.insert("Captain America", "Red Skull");
  heroes.insert("Wonder Woman", "Ares");
  heroes.insert("Iron Man", "Thanos"); 
  heroes.insert("Hulk", "Abomination");
  heroes.insert("Thor", "Loki");
  heroes.insert("Black Panther", "T'Challa");
  cout << "Heroes and their arch-nemeses:" << endl;
  cout << heroes.size() << " entries in total." << endl;
  heroes.debug();
  return 0;
}