// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__QR__BUILDER_HPP_
#define QRMSG__MSG__DETAIL__QR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qrmsg/msg/detail/qr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qrmsg
{

namespace msg
{

namespace builder
{

class Init_Qr_is_new
{
public:
  explicit Init_Qr_is_new(::qrmsg::msg::Qr & msg)
  : msg_(msg)
  {}
  ::qrmsg::msg::Qr is_new(::qrmsg::msg::Qr::_is_new_type arg)
  {
    msg_.is_new = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qrmsg::msg::Qr msg_;
};

class Init_Qr_way
{
public:
  explicit Init_Qr_way(::qrmsg::msg::Qr & msg)
  : msg_(msg)
  {}
  Init_Qr_is_new way(::qrmsg::msg::Qr::_way_type arg)
  {
    msg_.way = std::move(arg);
    return Init_Qr_is_new(msg_);
  }

private:
  ::qrmsg::msg::Qr msg_;
};

class Init_Qr_num
{
public:
  Init_Qr_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Qr_way num(::qrmsg::msg::Qr::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_Qr_way(msg_);
  }

private:
  ::qrmsg::msg::Qr msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qrmsg::msg::Qr>()
{
  return qrmsg::msg::builder::Init_Qr_num();
}

}  // namespace qrmsg

#endif  // QRMSG__MSG__DETAIL__QR__BUILDER_HPP_
