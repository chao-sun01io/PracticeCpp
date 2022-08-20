#pragma once
#include <algorithm>
#include <vector>
// merge sort elements between [left, right)

// Note: This isn't an efficient way because create log(N) vector at the same time
// Prefer the implementation bellow.
// template <typename Comparable>
// std::vector<Comparable> mergeSort(std::vector<Comparable> &arr, int left, int right) {
//   if (left == right - 1) return {arr[left]};
//   int center = left + (right - left) / 2;
//   auto left_sorted = mergeSort(arr, left, center);
//   auto right_sorted = mergeSort(arr, center, right);
//   std::vector<Comparable> res(left_sorted.size() + right_sorted.size());
//   std::merge(left_sorted.begin(), left_sorted.end(), right_sorted.begin(), right_sorted.end(), res.begin());
//   return res;
// }

// merge elements of arr in [left,right) and [right,end) into [left,end) of buf
template <typename Comparable>
void merge(std::vector<Comparable> &arr, std::vector<Comparable> &buf, int left, int right, int rightend) {
  int left_end = right;
  int i = left;
  int j = right;
  int pos = left;

  for (; i < right && j < rightend;) {
    if (arr[i] <= arr[j]) {
      buf[pos++] = std::move(arr[i++]);
    } else {
      buf[pos++] = std::move(arr[j++]);
    }
  }

  if (i != right) {
    std::copy(arr.begin() + i, arr.begin() + right, buf.begin() + pos);
  }

  if (j != rightend) {
    std::copy(arr.begin() + j, arr.begin() + rightend, buf.begin() + pos);
  }

  std::copy(buf.begin() + left, buf.begin() + rightend, arr.begin() + left);
}

// mergeSoft subroution in [left,right]
template <typename Comparable>
void mergeSort(std::vector<Comparable> &arr, std::vector<Comparable> &buf, int left, int right) {
  //   if (left == right - 1) return;
  if (left < right) {
    int center = left + (right - left) / 2;
    mergeSort(arr, buf, left, center);
    mergeSort(arr, buf, center + 1, right);
    // std::merge(arr.begin() + left, arr.begin() + center + 1, arr.begin() + center + 1, arr.begin() + right + 1, buf.begin() + left);
    // std::copy(buf.begin() + left, buf.begin() + right + 1, arr.begin() + left);
    merge(arr, buf, left, center + 1, right + 1);
  }
}

template <typename Comparable>
void mergeSort(std::vector<Comparable> &arr) {
  std::vector<Comparable> buf(arr.size());
  mergeSort(arr, buf, 0, arr.size() - 1);
}
