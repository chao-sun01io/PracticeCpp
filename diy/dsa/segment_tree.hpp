#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>
namespace diy {

/**
 * @brief Demostrate SegmentTree by compute the range sum in interval [L,R)
 * Implemented by Binary Heap which is more efficient
 */
template <typename T>
class SegmentTree {
 public:
  explicit SegmentTree(const std::vector<T> &arr) { build(arr); }
  void build(const std::vector<T> &arr) {
    n_ = arr.size();
    tree_ = std::vector<int>(2 * n_, 0);
    std::copy(arr.begin(), arr.end(), tree_.begin() + n_);
    for (int i = n_ - 1; i > 0; --i) {
      tree_[i] = tree_[i << 1] + tree_[i << 1 | 1];
    }
  }

  void update(int idx, T val) {
    if (idx < 0 || idx >= n_) throw std::out_of_range("idx of range");
    tree_[idx + n_] = val;

    for (int i = idx + n_; i > 0; i >>= 1) {
      tree_[i >> 1] = tree_[i] + tree_[i ^ 1];  // if m = 2*i,then m^1 = 2*i+1 and vice versa
    }
  }

  // return the range_sum value of [l,r);
  auto query(int l, int r) -> T {
    if (l < 0 || r > n_) throw std::out_of_range("idx of range");

    T res = 0;
    for (l = l + n_, r = r + n_; l > 0 && l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        res += tree_[l++];
      }
      if (r & 1) {
        res += tree_[--r];
      }
    }

    return res;
  }

 private:
  std::vector<T> tree_;
  int n_{};
};

}  // namespace diy