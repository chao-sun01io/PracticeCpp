#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>
namespace diy {
/**
 * @brief Demostrate SegmentTree by compute the range sum in interval [L,R). Implemented by recursion
 *
 */
template <typename T>
class SegmentTree2 {
 public:
  explicit SegmentTree2(const std::vector<T> &arr) { build(arr); }
  void build(const std::vector<T> &arr) {
    n_ = arr.size();
    tree_ = std::vector<T>(n_ * 4);
    build(arr, 0, 0, n_ - 1);
  }

  void update(int idx, T val) {
    if (idx < 0 || idx >= n_) throw std::out_of_range("idx of range");
    update(0, 0, n_ - 1, idx, val);
  }

  // return the range_sum value of [l,r);
  auto query(int l, int r) -> T { return query(0, 0, n_ - 1, l, r - 1); }

 private:
  // tree_[idx] stores the sum of arr[l : r]
  void build(const std::vector<T> &arr, int node, int l, int r) {
    if (l == r) {
      tree_[node] = arr[l];
      return;
    }
    // mid = (l + r) / 2
    int mid = l + (r - l) / 2;
    build(arr, lchild(node), l, mid);
    build(arr, rchild(node), mid + 1, r);
    tree_[node] = tree_[lchild(node)] + tree_[rchild(node)];
  }

  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      tree_[node] = val;
    } else {
      int mid = start + (end - start) / 2;
      if (start <= idx && idx <= mid) {
        update(lchild(node), start, mid, idx, val);
      } else {
        update(rchild(node), mid + 1, end, idx, val);
      }
      tree_[node] = tree_[lchild(node)] + tree_[rchild(node)];
    }
  }

  /**
   * @brief Get range sum of [L,R]
   *
   * @param node  the node of segment tree
   * @param start start point of range represented by node
   * @param end end of range represented by node
   * @param l l - end of interval
   * @param r r - endo of interval
   * @return T
   */
  auto query(int node, int start, int end, int l, int r) -> T {
    if (r < start || l > end) {
      return 0;
    }

    if (l <= start && r >= end) {  // all represented by node is included in [l,r]
      return tree_[node];
    }

    // range repsented by a node is partially included in thve given range
    int mid = start + (end - start) / 2;
    int v1 = query(lchild(node), start, mid, l, r);
    int v2 = query(rchild(node), mid + 1, end, l, r);
    return v1 + v2;
  }

  int lchild(int i) { return 2 * i + 1; }
  int rchild(int i) { return 2 * i + 2; }
  std::vector<T> tree_;
  int n_{};
};

}  // namespace diy