// Binary heap implemention

#include <algorithm>
#include <bits/c++config.h>
#include <cstddef>
#include <vector>

// take min heap for example.
template <typename Comparable> class BinaryHeap {
public:
  explicit BinaryHeap(int capacity = 100) {
    cur_size_ = 0;
    data_.resize(capacity);
  }
  // explicit BinaryHeap(const std::vector<Comparable> &items);

  // insertion
  void push(Comparable v) {
    // data_[0] is not used
    if (cur_size_ == data_.size() - 1) {
      data_.resize(2 * cur_size_ + 1);
    }

    // percolate up
    int hole = ++cur_size_;
    auto copy = v;

    data_[0] = std::move(v);
    for (; copy < parent(hole); hole /= 2) {
      data_[hole] = std::move(data_[parent(hole)]);
    }
    data_[hole] = std::move(data_[0]);
  }

  void pop() {
    // pick the lastelement ,then percolate down
    data_[1] = data_[--cur_size_];

    Comparable tmp = std::move(data_[1]);
    int hole = 1;
    for (int child; lchild(hole) <= cur_size_; hole = child) {
      child = lchild(hole);
      if (rchild(hole) <= cur_size_ &&
          data_[rchild(hole)] < data_[lchild(hole)])
        child = rchild(hole);
      if (data_[child] < tmp) {
        data_[hole] = std::move(data_[child]);
      } else
        break;
    }
    data_[hole] = std::move(tmp);
  }

  Comparable top() {
    // if(empty())
    //    throw xxxx;

    return data_[1];
  }

  bool empty() { return cur_size_ == 0; }

private:
  std::size_t cur_size_;
  std::vector<int> data_;
  size_t lchild(size_t i) { return 2 * i; }
  size_t rchild(size_t i) { return 2 * i + 1; }
  size_t parent(size_t i) { return i / 2; }
};
