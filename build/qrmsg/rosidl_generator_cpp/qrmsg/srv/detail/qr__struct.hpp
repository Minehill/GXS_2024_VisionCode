// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__SRV__DETAIL__QR__STRUCT_HPP_
#define QRMSG__SRV__DETAIL__QR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qrmsg__srv__Qr_Request __attribute__((deprecated))
#else
# define DEPRECATED__qrmsg__srv__Qr_Request __declspec(deprecated)
#endif

namespace qrmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Qr_Request_
{
  using Type = Qr_Request_<ContainerAllocator>;

  explicit Qr_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ll;
      this->way = 0ll;
      this->is_new = false;
    }
  }

  explicit Qr_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    qrmsg::srv::Qr_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qrmsg::srv::Qr_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qrmsg::srv::Qr_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qrmsg::srv::Qr_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qrmsg__srv__Qr_Request
    std::shared_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qrmsg__srv__Qr_Request
    std::shared_ptr<qrmsg::srv::Qr_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Qr_Request_ & other) const
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
  bool operator!=(const Qr_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Qr_Request_

// alias to use template instance with default allocator
using Qr_Request =
  qrmsg::srv::Qr_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qrmsg


#ifndef _WIN32
# define DEPRECATED__qrmsg__srv__Qr_Response __attribute__((deprecated))
#else
# define DEPRECATED__qrmsg__srv__Qr_Response __declspec(deprecated)
#endif

namespace qrmsg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Qr_Response_
{
  using Type = Qr_Response_<ContainerAllocator>;

  explicit Qr_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finish = false;
      this->way = 0ll;
      this->dis = 0.0;
    }
  }

  explicit Qr_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finish = false;
      this->way = 0ll;
      this->dis = 0.0;
    }
  }

  // field types and members
  using _finish_type =
    bool;
  _finish_type finish;
  using _way_type =
    int64_t;
  _way_type way;
  using _dis_type =
    double;
  _dis_type dis;

  // setters for named parameter idiom
  Type & set__finish(
    const bool & _arg)
  {
    this->finish = _arg;
    return *this;
  }
  Type & set__way(
    const int64_t & _arg)
  {
    this->way = _arg;
    return *this;
  }
  Type & set__dis(
    const double & _arg)
  {
    this->dis = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qrmsg::srv::Qr_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qrmsg::srv::Qr_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qrmsg::srv::Qr_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qrmsg::srv::Qr_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qrmsg__srv__Qr_Response
    std::shared_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qrmsg__srv__Qr_Response
    std::shared_ptr<qrmsg::srv::Qr_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Qr_Response_ & other) const
  {
    if (this->finish != other.finish) {
      return false;
    }
    if (this->way != other.way) {
      return false;
    }
    if (this->dis != other.dis) {
      return false;
    }
    return true;
  }
  bool operator!=(const Qr_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Qr_Response_

// alias to use template instance with default allocator
using Qr_Response =
  qrmsg::srv::Qr_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qrmsg

namespace qrmsg
{

namespace srv
{

struct Qr
{
  using Request = qrmsg::srv::Qr_Request;
  using Response = qrmsg::srv::Qr_Response;
};

}  // namespace srv

}  // namespace qrmsg

#endif  // QRMSG__SRV__DETAIL__QR__STRUCT_HPP_
