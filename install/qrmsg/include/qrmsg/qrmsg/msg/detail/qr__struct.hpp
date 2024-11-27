// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__QR__STRUCT_HPP_
#define QRMSG__MSG__DETAIL__QR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qrmsg__msg__Qr __attribute__((deprecated))
#else
# define DEPRECATED__qrmsg__msg__Qr __declspec(deprecated)
#endif

namespace qrmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Qr_
{
  using Type = Qr_<ContainerAllocator>;

  explicit Qr_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ll;
      this->way = 0ll;
      this->is_new = false;
    }
  }

  explicit Qr_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ll;
      this->way = 0ll;
      this->is_new = false;
    }
  }

  // field types and members
  using _num_type =
    int64_t;
  _num_type num;
  using _way_type =
    int64_t;
  _way_type way;
  using _is_new_type =
    bool;
  _is_new_type is_new;

  // setters for named parameter idiom
  Type & set__num(
    const int64_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__way(
    const int64_t & _arg)
  {
    this->way = _arg;
    return *this;
  }
  Type & set__is_new(
    const bool & _arg)
  {
    this->is_new = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qrmsg::msg::Qr_<ContainerAllocator> *;
  using ConstRawPtr =
    const qrmsg::msg::Qr_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qrmsg::msg::Qr_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qrmsg::msg::Qr_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qrmsg::msg::Qr_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qrmsg::msg::Qr_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qrmsg::msg::Qr_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qrmsg::msg::Qr_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qrmsg::msg::Qr_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qrmsg::msg::Qr_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qrmsg__msg__Qr
    std::shared_ptr<qrmsg::msg::Qr_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qrmsg__msg__Qr
    std::shared_ptr<qrmsg::msg::Qr_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Qr_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->way != other.way) {
      return false;
    }
    if (this->is_new != other.is_new) {
      return false;
    }
    return true;
  }
  bool operator!=(const Qr_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Qr_

// alias to use template instance with default allocator
using Qr =
  qrmsg::msg::Qr_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qrmsg

#endif  // QRMSG__MSG__DETAIL__QR__STRUCT_HPP_
