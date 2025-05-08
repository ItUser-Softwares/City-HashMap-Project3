#pragma once

#include "city.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class HashMapVector {
public:
  std::vector<std::vector<City>> table;
  int bucketCount;

  HashMapVector(int size) : bucketCount(size) { table.resize(bucketCount); }

  int badHash(const std::string &key) {
    return (int)key[0] % bucketCount; // Just first character
  }

  int betterHash(const std::string &key) {
    int sum = 0;
    for (char c : key)
      sum += c;
    return sum % bucketCount;
  }

  int bestHash(const std::string &key) {
    unsigned long hash = 5381;
    for (char c : key)
      hash = ((hash << 5) + hash) + c;
    return hash % bucketCount;
  }

  void insert(const City &city, int (*hashFunc)(const std::string &)) {
    int index = hashFunc(city.cityName);
    table[index].push_back(city);
  }

  void displayTable() {
    for (int i = 0; i < bucketCount; ++i) {
      std::cout << "Bucket " << i << ":\n";
      for (const auto &city : table[i]) {
        city.display();
      }
    }
  }

  int countCollisions() {
    int collisions = 0;
    for (const auto &bucket : table) {
      if (bucket.size() > 1)
        collisions += (bucket.size() - 1);
    }
    return collisions;
  }
};