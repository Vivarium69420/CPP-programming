#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, std::string> u = {
      {"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};

  auto printKeyValue = [](const auto &key, const auto &value) {
    std::cout << "Key:[" << key << "] - Value:[" << value << "]\n";
  };
  for (const std::pair<const std::string, std::string> &n : u)
    printKeyValue(n.first, n.second);
}
