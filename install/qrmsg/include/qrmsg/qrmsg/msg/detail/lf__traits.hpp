// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__LF__TRAITS_HPP_
#define QRMSG__MSG__DETAIL__LF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qrmsg/msg/detail/lf__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qrmsg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Lf & msg,
  std::ostream & out)
{
  out << "{";
  // member: lf_k
  {
    out << "lf_k: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_k, out);
    out << ", ";
  }

  // member: lf_b
  {
    out << "lf_b: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Lf & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lf_k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf_k: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_k, out);
    out << "\n";
  }

  // member: lf_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf_b: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Lf & msg, bool use_flow_style = false)
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
  const qrmsg::msg::Lf & msg,
  std::ostream & out, size_t indentation = 0)
{
  qrmsg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qrmsg::msg::to_yaml() instead")]]
inline std::string to_yaml(const qrmsg::msg::Lf & msg)
{
  return qrmsg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<qrmsg::msg::Lf>()
{
  return "qrmsg::msg::Lf";
}

template<>
inline const char * name<qrmsg::msg::Lf>()
{
  return "qrmsg/msg/Lf";
}

template<>
struct has_fixed_size<qrmsg::msg::Lf>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qrmsg::msg::Lf>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qrmsg::msg::Lf>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QRMSG__MSG__DETAIL__LF__TRAITS_HPP_
