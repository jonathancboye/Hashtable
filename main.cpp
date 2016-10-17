//File: main.cpp
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "hashtable.h"
using namespace std;


u_long djb2(u_char *str)
{
  u_long hash = 5381;
  int c;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}

u_long sdbm(u_char *str)
{
  u_long hash = 0;
  int c;

  while (c = *str++)
    hash = c + (hash << 6) + (hash << 16) - hash;

  return hash;
}

//Read File into hash table
void readFile(string fileName, HashTable<string,string> &htable);

//Create HashTable
HashTable<string,string> createHashTable();

//Create log file
void createLog(string fileName, HashTable<string,string> &htable);

int main(){
  char menuOption; //menu choice
  HashTable<string,string> htable(&sdbm);
  string name;
  while(true){
    cout << "####################" << endl;
    cout << "#       MENU       #" << endl;
    cout << "####################" << endl;
    cout << "(C)reate Hash Table" << endl;
    cout << "(I)nsert new Entry" << endl;
    cout << "(D)elete Entry" << endl;
    cout << "(S)earch by last name" << endl;
    cout << "(L)ogfile" << endl;
    cout << "(P)rint distribution" << endl;
    cout << "(Q)uit" <<endl;
    cout << endl;
    cout << "Enter choice: ";
    cin >> menuOption;
    cout << endl;
    switch(menuOption){
    case 'C':
      htable = createHashTable();
      break;
    case 'I':
      {
      cout << "Enter a last name to insert into hash table:";
      cin >> name;
      Entry<string,string> e(name,name);
      if(htable.insert(e))
	cout << "Successfully inserted entry";
      else
	cout << "Entry already exists";
      cout << endl;
      break;
      }
    case 'D':
      cout << "Enter a name to remove from hash table:";
      cin >> name;
      if(htable.removeEntry(name))
	cout << "Entry removed";
      else
	cout << "Entry not found";
      cout << endl;
      break;
    case 'S':
      cout << "Enter a name to search for in hash table:";
      cin >> name;
      if(htable.searchEntry(name))
	cout << "Entry found";
      else
	cout << "Entry not found";
      cout << endl;
      break;
    case 'L':
      cout << "Enter a file name to output log info: ";
      cin >> name;
      createLog(name, htable);
      break;
    case 'P':
      htable.distribution();
      break;
    case 'Q':
      return EXIT_SUCCESS;
    default:
      cout << "Please select a valid option" << endl;
    }
  }

  htable.distribution();
  return EXIT_SUCCESS;
}

HashTable<string,string> createHashTable(){
  string fileName;
  char option;
  u_long (*hashFunction)(u_char*);
  bool done = false;
  cout << "File name to load into hash table: ";
  cin >> fileName;
  cout << "Select a hashing function" <<endl;
  while(!done){
    cout << "a) sdbm" << endl;
    cout << "b) djb2" << endl;
    cin >> option;
    if(option == 'a')
      hashFunction = &sdbm;
    if(option == 'b')
      hashFunction = &djb2;
    if(option == 'a' || option == 'b'){
      done = true;
    }
    else
      cout << "Please select a hashing function" << endl;
  }
  HashTable<string,string> hashTable(hashFunction);
  readFile(fileName, hashTable);
  return hashTable;
}

void readFile(string fileName, HashTable<string,string> &htable){
  ifstream ifs;
  ifs.open(fileName.c_str());
  if(!ifs.fail()){
    string name;
    while(ifs >> name){
      Entry<string,string> e(name,name);
      htable.insert(e);
    }
    ifs.close();
  }
  else
    cout << "ERROR: Could not open file" << endl;
}

void createLog(string fileName, HashTable<string,string> &htable){
  ofstream ofs;
  ofs.open(fileName.c_str());
  htable.getFormatedTable(ofs);
}
