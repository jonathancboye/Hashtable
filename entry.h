//File: entry.h
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#ifndef ENTRY_H
#define ENTRY_H
template <typename K, typename V>
class Entry{
public:
  //constructor
 Entry(const K& k, const V& v): key(k), value(v){}

  //Return the key
  K getKey()const {return key;}
  //Return the value
  V getValue()const {return value;}
private:
  K key;
  V value;
};

#endif //ENTRY_H
