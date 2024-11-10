// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__QR__TRAITS_HPP_
#define QRMSG__MSG__DETAIL__QR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qrmsg/msg/detail/qr__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qrmsg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Qr & msg,
  std::ostream & out)
{
  out << "{";
  // member: num
  {
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
    out << ", ";
  }

  // member: way
  {
    out << "way: ";
    rosidl_generator_traits::value_to_yaml(msg.way, out);
    out << ", ";
  }

  // member: is_new
  {
    out << "is_new: ";
    rosidl_generator_traits::value_to_yaml(msg.is_new, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Qr & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
    out << "\n";
  }

  // member: way
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "way: ";
    rosidl_generator_traits::value_to_yaml(msg.way, out);
    out << "\n";
  }

  // member: is_new
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_new: ";
    rosidl_generator_traits::value_to_yaml(msg.is_new, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Qr & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace qrmsg

namespace rosidl_generator_traits
{

[[deprecated("use qrmsg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qrmsg::msg::Qr & msg,
  std::ostream & out, size_t indentation = 0)
{
  qrmsg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qrmsg::msg::to_yaml() instead")]]
inline std::string to_yaml(const qrmsg::msg::Qr & msg)
{
  return qrmsg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<qrmsg::msg::Qr>()
{
  return "qrmsg::msg::Qr";
}

template<>
inline const char * name<qrmsg::msg::Qr>()
{
  return "qrmsg/msg/Qr";
}

template<>
struct has_fixed_size<qrmsg::msg::Qr>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qrmsg::msg::Qr>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qrmsg::msg::Qr>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QRMSG__MSG__DETAIL__QR__TRAITS_HPP_
