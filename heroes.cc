#include <iostream>
#include <string>
#include "hashtable.hh"

using namespace std;

#include <string>
#include <random>

string generateRandomString(unsigned int length) {
    // Character set to choose from
    const string characters = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";
    
    // Random number generator
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characters.size() - 1);
    
    // Build the random string
    string randomString;
    randomString.reserve(length);
    
    for (unsigned int i = 0; i < length; ++i) {
        randomString += characters[distribution(generator)];
    }
    
    return randomString;
}

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
  //heroes.debug();
  //heroes.distribution();
  cout << "Load factor: " << heroes.load_factor() << endl;
  cout << "Finding some villains:" << endl;
  cout << "Spider-Man: " << heroes.find("Spider-Man") << endl;
  cout << "Superman: " << heroes.find("Superman") << endl;
  cout << "Chavo: " << heroes.find("Chavo") << endl;


  heroes.remove("Batman");
  cout << "After removing Batman, size: " << heroes.size() << endl;
  return 0;
}

int main2() {
    const unsigned int numEntries = 1000;
    const unsigned int stringLength = 10;
    Hashtable table(501); // A prime number size for better distribution

    for (unsigned int i = 0; i < numEntries; ++i) {
        string randomKey = generateRandomString(stringLength);
        //string randomValue = generateRandomString(stringLength);
        table.insert(randomKey, "SomeValue");
    }

    //cout << "Inserted " << numEntries << " random entries into the hashtable." << endl;
    //cout << "Hashtable size: " << table.size() << endl;
    // Uncomment the next line to see the contents of the hashtable
    //table.debug();

    table.distribution();
    cout << "Load factor: " << table.load_factor() << endl;
    return 0;
} 