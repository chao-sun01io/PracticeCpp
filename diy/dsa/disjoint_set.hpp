#pragma once

#include <stdexcept>
#include <vector>
namespace diy {
class DisjointSet {
 public:
  DisjointSet(int n_elements);

  int find(int i);
  void union_set(int root1, int root2);

 private:
  std::vector<int> s;
};

inline DisjointSet::DisjointSet(int n_elements) : s(n_elements) {
  for (int i = 0; i < s.size(); ++i) {
    s[i] = i;
  }
}
auto DisjointSet::find(int i) -> int {
  if (i >= s.size()) throw std::out_of_range("index of out range");
  if (s[i] != i) s[i] = find(s[i]);
  return s[i];
}

// Note: there is more effient way to implement disjoint set : union by size
void DisjointSet::union_set(int x, int y) { s[find(x)] = find(s[y]); }
}  // namespace diy