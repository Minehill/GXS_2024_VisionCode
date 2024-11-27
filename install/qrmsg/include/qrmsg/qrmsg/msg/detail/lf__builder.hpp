// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__LF__BUILDER_HPP_
#define QRMSG__MSG__DETAIL__LF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qrmsg/msg/detail/lf__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qrmsg
{

namespace msg
{

namespace builder
{

class Init_Lf_lf_b
{
public:
  explicit Init_Lf_lf_b(::qrmsg::msg::Lf & msg)
  : msg_(msg)
  {}
  ::qrmsg::msg::Lf lf_b(::qrmsg::msg::Lf::_lf_b_type arg)
  {
    msg_.lf_b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qrmsg::msg::Lf msg_;
};

class Init_Lf_lf_k
{
public:
  Init_Lf_lf_k()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Lf_lf_b lf_k(::qrmsg::msg::Lf::_lf_k_type arg)
  {
    msg_.lf_k = std::move(arg);
    return Init_Lf_lf_b(msg_);
  }

private:
  ::qrmsg::msg::Lf msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qrmsg::msg::Lf>()
{
  return qrmsg::msg::builder::Init_Lf_lf_k();
}

}  // namespace qrmsg

#endif  // QRMSG__MSG__DETAIL__LF__BUILDER_HPP_
