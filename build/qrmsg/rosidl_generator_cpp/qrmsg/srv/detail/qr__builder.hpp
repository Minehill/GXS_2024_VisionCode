// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__SRV__DETAIL__QR__BUILDER_HPP_
#define QRMSG__SRV__DETAIL__QR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qrmsg/srv/detail/qr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qrmsg
{

namespace srv
{

namespace builder
{

class Init_Qr_Request_is_new
{
public:
  explicit Init_Qr_Request_is_new(::qrmsg::srv::Qr_Request & msg)
  : msg_(msg)
  {}
  ::qrmsg::srv::Qr_Request is_new(::qrmsg::srv::Qr_Request::_is_new_type arg)
  {
    msg_.is_new = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qrmsg::srv::Qr_Request msg_;
};

class Init_Qr_Request_way
{
public:
  explicit Init_Qr_Request_way(::qrmsg::srv::Qr_Request & msg)
  : msg_(msg)
  {}
  Init_Qr_Request_is_new way(::qrmsg::srv::Qr_Request::_way_type arg)
  {
    msg_.way = std::move(arg);
    return Init_Qr_Request_is_new(msg_);
  }

private:
  ::qrmsg::srv::Qr_Request msg_;
};

class Init_Qr_Request_num
{
public:
  Init_Qr_Request_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Qr_Request_way num(::qrmsg::srv::Qr_Request::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_Qr_Request_way(msg_);
  }

private:
  ::qrmsg::srv::Qr_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qrmsg::srv::Qr_Request>()
{
  return qrmsg::srv::builder::Init_Qr_Request_num();
}

}  // namespace qrmsg


namespace qrmsg
{

namespace srv
{

namespace builder
{

class Init_Qr_Response_dis
{
public:
  explicit Init_Qr_Response_dis(::qrmsg::srv::Qr_Response & msg)
  : msg_(msg)
  {}
  ::qrmsg::srv::Qr_Response dis(::qrmsg::srv::Qr_Response::_dis_type arg)
  {
    msg_.dis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qrmsg::srv::Qr_Response msg_;
};

class Init_Qr_Response_way
{
public:
  explicit Init_Qr_Response_way(::qrmsg::srv::Qr_Response & msg)
  : msg_(msg)
  {}
  Init_Qr_Response_dis way(::qrmsg::srv::Qr_Response::_way_type arg)
  {
    msg_.way = std::move(arg);
    return Init_Qr_Response_dis(msg_);
  }

private:
  ::qrmsg::srv::Qr_Response msg_;
};

class Init_Qr_Response_finish
{
public:
  Init_Qr_Response_finish()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Qr_Response_way finish(::qrmsg::srv::Qr_Response::_finish_type arg)
  {
    msg_.finish = std::move(arg);
    return Init_Qr_Response_way(msg_);
  }

private:
  ::qrmsg::srv::Qr_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qrmsg::srv::Qr_Response>()
{
  return qrmsg::srv::builder::Init_Qr_Response_finish();
}

}  // namespace qrmsg

#endif  // QRMSG__SRV__DETAIL__QR__BUILDER_HPP_
