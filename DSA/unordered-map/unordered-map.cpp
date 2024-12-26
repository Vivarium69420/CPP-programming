#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

template <typename KeyType, typename ValueType>
class UnorderedMap {
 private:
  size_t bucketCount;
  std::vector<std::list<std::pair<KeyType, ValueType>>> buckets;

 public:
  UnorderedMap(size_t bucketCount = 8);
  ~UnorderedMap();

  size_t hash(const KeyType &key) const;
  void insert(const KeyType &key, const ValueType &val);
  void remove(const KeyType &key);
  ValueType get(const KeyType &key) const;
  void print() const;
};

template <typename KeyType, typename ValueType>
UnorderedMap<KeyType, ValueType>::UnorderedMap(size_t bucketCount)
    : bucketCount(bucketCount) {
  buckets.resize(bucketCount);
}

template <typename KeyType, typename ValueType>
UnorderedMap<KeyType, ValueType>::~UnorderedMap() {
  // Destructor implementation (empty in this case)
}

template <typename KeyType, typename ValueType>
size_t UnorderedMap<KeyType, ValueType>::hash(const KeyType &key) const {
  return std::hash<KeyType>()(key) % bucketCount;
}

template <typename KeyType, typename ValueType>
void UnorderedMap<KeyType, ValueType>::insert(const KeyType &key,
                                              const ValueType &val) {
  size_t index = hash(key);
  for (auto &node : buckets[index]) {
    if (node.first == key) {
      node.second = val;
      return;
    }
  }
  buckets[index].emplace_back(key, val);
}

template <typename KeyType, typename ValueType>
void UnorderedMap<KeyType, ValueType>::remove(const KeyType &key) {
  size_t index = hash(key);
  auto &bucket = buckets[index];
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (it->first == key) {
      bucket.erase(it);
      return;
    }
  }
  std::cout << "Key not found\n";
}

template <typename KeyType, typename ValueType>
void UnorderedMap<KeyType, ValueType>::print() const {
  for (size_t i = 0; i < buckets.size(); i++) {
    std::cout << "Bucket " << i << ": ";
    for (const auto &node : buckets[i]) {
      std::cout << "(" << node.first << ", " << node.second << ") ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {
  UnorderedMap<std::string, int> umap(8);
  umap.insert("Hello", 1);
  umap.insert("Hi", 1);
  umap.insert("Die", 3);
  umap.print();

  std::cout << std::endl;

  umap.remove("Die");
  umap.print();
  return 0;
}
