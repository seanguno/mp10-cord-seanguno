#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <iostream>

enum class kSharedPointerType { kArray, kObject };

template <typename T>
class SharedPointer {
public:
  SharedPointer(T* address,
                kSharedPointerType type = kSharedPointerType::kObject);
  ~SharedPointer();
  SharedPointer(const SharedPointer<T>& source);
  SharedPointer<T>& operator=(const SharedPointer<T>& source);

  // Provided, do not modify!
  SharedPointer() = default;
  T& operator*() { return *holder_; }
  T* operator->() { return holder_; }
  T* Get() { return holder_; }
  const T* Get() const { return holder_; }
  unsigned int UseCount() const {
    return (ref_count_ != nullptr) ? *ref_count_ : 0;
  }

private:
  T* holder_ = nullptr;
  kSharedPointerType type_ = kSharedPointerType::kObject;
  unsigned int* ref_count_ = nullptr;
};

// non-member helper function declarations

// non-member helper function definitions

// member function definitions

template <typename T>
SharedPointer<T>::SharedPointer(T* address, kSharedPointerType type) {
  holder_ = address;
  if (type == kSharedPointerType::kArray) {
    type_ = kSharedPointerType::kArray;
  }
  ref_count_ = new unsigned int(1);
}

template <typename T>
SharedPointer<T>::~SharedPointer() {
  if (ref_count_ == nullptr || holder_ == nullptr) return;
  --*ref_count_;
  if (*ref_count_ == 0) {
    if (type_ == kSharedPointerType::kArray) {
      delete[] holder_;
    } else {
      delete holder_;
    }
    delete ref_count_;
  }
}
template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& source) {
  if (source.holder_ == nullptr) {
    if (source.ref_count_ != nullptr) {
      ref_count_ = source.ref_count_;
      ++*ref_count_;
    }
    return;
  }
  holder_ = source.holder_;
  if (source.type_ == kSharedPointerType::kArray) {
    type_ = kSharedPointerType::kArray;
  }
  ref_count_ = source.ref_count_;
  ++*ref_count_;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& source) {
  if (this == &source) return *this;
  if (source.holder_ == nullptr) {
    this->~SharedPointer();
    holder_ = nullptr;
    if (source.ref_count_ != nullptr) {
      ref_count_ = source.ref_count_;
      ++*ref_count_;
    }
    return *this;
  }
  this->~SharedPointer();
  holder_ = source.holder_;
  ref_count_ = source.ref_count_;
  ++*ref_count_;
  return *this;
}
#endif
