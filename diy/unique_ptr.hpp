#pragma once

namespace diy {
template <typename T>
class unique_ptr {
 private:
  T *ptr_;

 public:
  explicit unique_ptr(T *ptr) : ptr_(ptr) {}
  unique_ptr(unique_ptr &&other) noexcept : ptr_(nullptr) { this->swap(other); };
  unique_ptr &operator=(unique_ptr &&other) noexcept {
    this->swap(other);
    return *this;
  }

  // move and swap  idiom replace the move assignment operator
  // unique_ptr &operator=(unique_ptr rhs) noexcept  // will call move constructor
  // {
  //   // std::swap(ptr_, rhs.ptr_);// is also ok
  //   this->swap(rhs);
  //   return *this;
  // }
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) =
      delete;  // note: shouldn't be reserved when use move-swap

  ~unique_ptr() {
    delete ptr_;
    ptr_ = nullptr;
  }

  void swap(unique_ptr &other) noexcept {
    using std::swap;
    swap(ptr_, other.ptr_);
  }

  T *get() const { return ptr_; }

  T &operator*() const { return *ptr_; }

  T *operator->() const { return ptr_; }

  // So it can be used in conditional expression
  explicit operator bool() { return ptr_; }
};
}  // namespace diy