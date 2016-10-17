//File: hashtable.cpp
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

template <typename K, typename V>
HashTable<K,V>& HashTable<K,V>::operator=(const HashTable<K,V> &lhs){
  if(this == &lhs)
    return *this;

  hashFunction = lhs.hashFunction;
  for(int i=0;i<BUCKETS;++i)
    bucketArray[i] = lhs.bucketArray[i];
  return *this;
}

template <typename K, typename V>
bool HashTable<K,V>::searchEntry(const K &key){
  for(Itor it = bucketArray[hash(key.c_str())].begin();it != bucketArray[hash(key.c_str())].end();++it){
    if(it -> getKey() == key){
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
bool HashTable<K,V>::removeEntry(const K &key){
  for(Itor it = bucketArray[hash(key.c_str())].begin(); it != bucketArray[hash(key.c_str())].end();++it)
    if(it -> getKey() == key){
      bucketArray[hash(key.c_str())].erase(it);
      return true;
    }
  return false;
}

template <typename K, typename V>
void HashTable<K,V>::distribution(){
  map<int,double> dist;
  map<int,double>::iterator it;
  double sum =0;
  int size =0;

  for(int i=0;i<BUCKETS;++i){
    size = bucketArray[i].size();
    dist[size] += 1;
    sum += size;
    for(int j=0;j < size;++j)
      cout << "x";
    cout << endl;
  }
  
  cout << "Total Entries: " << sum << endl;
  cout << "Expected number of entries in a bucket: " << sum/BUCKETS<< endl;


  char space = ' ';
  int numberWidth = 12;
  int labelWidth = 5;
  cout << left << setw(labelWidth) << setfill(space) << "X";
  for(it = dist.begin();it!=dist.end();++it){
    cout << left << "|";
    cout << left << setw(numberWidth) << setfill(space) << it -> first;
  }
  cout << endl;
  cout << left<< setw(labelWidth) << setfill(space) << "P(x)";
  for(it = dist.begin();it!=dist.end();++it){
    cout << left << "|";
    cout << left << setw(numberWidth) << setfill(space) << (double)(it -> second)/BUCKETS;
  }
  cout << endl;
  

}

template <typename K, typename V>
void HashTable<K,V>::getFormatedTable(ofstream &out){
  Itor it;
  int size = 0;
  for(int i=0;i<BUCKETS;++i){
    out << "Bucket " << i << ": ";
    for(it = bucketArray[i].begin();it != bucketArray[i].end();++it)
      out << it -> getValue() << " ";
    out << endl;
  }
}

template <typename K, typename V>
bool HashTable<K,V>::insert(Entry<K,V> entry){
  if(searchEntry(entry.getKey())) return false;
  const char* str = entry.getKey().c_str();
  bucketArray[hash(str)].push_back(entry);
}

template <typename K, typename V>
u_long HashTable<K,V>::hash(const char* str){
  u_char* u_str= reinterpret_cast<u_char*>(const_cast<char*>(str));
  u_long hashedValue =  hashFunction(u_str);
  return hashedValue % BUCKETS;
}
#endif //HASHTABLE_CPP
