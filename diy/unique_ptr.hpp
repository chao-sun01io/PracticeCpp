#pragma once

namespace diy {
template <typename T>
class unique_ptr {
 public:
  explicit unique_ptr(T *ptr) : raw_ptr_(ptr) {}
  unique_ptr(unique_ptr &&other) noexcept {
    raw_ptr_ = other.raw_ptr_;
    other.raw_ptr_ = nullptr;
  };
  //   unique_ptr &operator=(unique_ptr &&other) noexcept {
  //     if (&other != this) std::swap(other.raw_ptr_, raw_ptr_);
  //     return *this;
  //   }

  // move and swap  idiom replace the move assignment operator
  unique_ptr &operator=(unique_ptr rhs) noexcept  // will call move constructor
  {
    std::swap(raw_ptr_, rhs.raw_ptr_);
    // std::swap(*this,rhs)  // is also ok
    return *this;
  }
  unique_ptr(const unique_ptr &) = delete;
  //  unique_ptr &operator=(const unique_ptr &) = delete; // shouldn't reserved
  ~unique_ptr() {
    delete raw_ptr_;
    raw_ptr_ = nullptr;
  }

  T *get() { return raw_ptr_; }

  T &operator*() const { return *raw_ptr_; }

  T *operator->() const { return raw_ptr_; }

 private:
  T *raw_ptr_;
};
}  // namespace diy