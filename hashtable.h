//File: hashtable.h
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <iterator>
#include <fstream>
#include "entry.h"

typedef unsigned long u_long;
typedef unsigned char u_char;

template <typename K, typename V>
class HashTable{
 public:
  typedef typename std::list<Entry<K,V> >::iterator Itor;
  
  //default constructor
  HashTable(){}
  
 HashTable(u_long(*hash)(u_char*)): hashFunction(hash){}
  
  HashTable<K,V>& operator=(const HashTable<K,V> &lhs);
  
  //insert entry into bucketArray
  bool insert(Entry<K,V> entry);
  
  //Search for key in Buckets
  bool searchEntry(const K &key);
  
  //Remove a entry in Buckets
  bool removeEntry(const K &key);

  //print the distribution of the data
  void distribution();

  //send formated hashtable to bufferstream
  void getFormatedTable(std::ofstream &out);

  //compute the hash of a key
  u_long hash(const char* str);

 private:

  static const int BUCKETS = 88799;
  std::list<Entry<K,V> > bucketArray[BUCKETS];
  u_long (*hashFunction)(u_char*);
};

#include "hashtable.cpp"
#endif //HASHTABLE_H
