// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__LF__STRUCT_HPP_
#define QRMSG__MSG__DETAIL__LF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qrmsg__msg__Lf __attribute__((deprecated))
#else
# define DEPRECATED__qrmsg__msg__Lf __declspec(deprecated)
#endif

namespace qrmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Lf_
{
  using Type = Lf_<ContainerAllocator>;

  explicit Lf_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf_k = 0.0;
      this->lf_b = 0.0;
    }
  }

  explicit Lf_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf_k = 0.0;
      this->lf_b = 0.0;
    }
  }

  // field types and members
  using _lf_k_type =
    double;
  _lf_k_type lf_k;
  using _lf_b_type =
    double;
  _lf_b_type lf_b;

  // setters for named parameter idiom
  Type & set__lf_k(
    const double & _arg)
  {
    this->lf_k = _arg;
    return *this;
  }
  Type & set__lf_b(
    const double & _arg)
  {
    this->lf_b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qrmsg::msg::Lf_<ContainerAllocator> *;
  using ConstRawPtr =
    const qrmsg::msg::Lf_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qrmsg::msg::Lf_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qrmsg::msg::Lf_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qrmsg::msg::Lf_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qrmsg::msg::Lf_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qrmsg::msg::Lf_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qrmsg::msg::Lf_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qrmsg::msg::Lf_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qrmsg::msg::Lf_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qrmsg__msg__Lf
    std::shared_ptr<qrmsg::msg::Lf_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qrmsg__msg__Lf
    std::shared_ptr<qrmsg::msg::Lf_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Lf_ & other) const
  {
    if (this->lf_k != other.lf_k) {
      return false;
    }
    if (this->lf_b != other.lf_b) {
      return false;
    }
    return true;
  }
  bool operator!=(const Lf_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Lf_

// alias to use template instance with default allocator
using Lf =
  qrmsg::msg::Lf_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qrmsg

#endif  // QRMSG__MSG__DETAIL__LF__STRUCT_HPP_
