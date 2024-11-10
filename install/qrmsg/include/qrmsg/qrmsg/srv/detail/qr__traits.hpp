// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__SRV__DETAIL__QR__TRAITS_HPP_
#define QRMSG__SRV__DETAIL__QR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qrmsg/srv/detail/qr__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qrmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Qr_Request & msg,
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
  const Qr_Request & msg,
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

inline std::string to_yaml(const Qr_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qrmsg

namespace rosidl_generator_traits
{

[[deprecated("use qrmsg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qrmsg::srv::Qr_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  qrmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qrmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const qrmsg::srv::Qr_Request & msg)
{
  return qrmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qrmsg::srv::Qr_Request>()
{
  return "qrmsg::srv::Qr_Request";
}

template<>
inline const char * name<qrmsg::srv::Qr_Request>()
{
  return "qrmsg/srv/Qr_Request";
}

template<>
struct has_fixed_size<qrmsg::srv::Qr_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qrmsg::srv::Qr_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qrmsg::srv::Qr_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace qrmsg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Qr_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: finish
  {
    out << "finish: ";
    rosidl_generator_traits::value_to_yaml(msg.finish, out);
    out << ", ";
  }

  // member: way
  {
    out << "way: ";
    rosidl_generator_traits::value_to_yaml(msg.way, out);
    out << ", ";
  }

  // member: dis
  {
    out << "dis: ";
    rosidl_generator_traits::value_to_yaml(msg.dis, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Qr_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: finish
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finish: ";
    rosidl_generator_traits::value_to_yaml(msg.finish, out);
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

  // member: dis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dis: ";
    rosidl_generator_traits::value_to_yaml(msg.dis, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Qr_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qrmsg

namespace rosidl_generator_traits
{

[[deprecated("use qrmsg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qrmsg::srv::Qr_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  qrmsg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qrmsg::srv::to_yaml() instead")]]
inline std::string to_yaml(const qrmsg::srv::Qr_Response & msg)
{
  return qrmsg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qrmsg::srv::Qr_Response>()
{
  return "qrmsg::srv::Qr_Response";
}

template<>
inline const char * name<qrmsg::srv::Qr_Response>()
{
  return "qrmsg/srv/Qr_Response";
}

template<>
struct has_fixed_size<qrmsg::srv::Qr_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qrmsg::srv::Qr_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qrmsg::srv::Qr_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qrmsg::srv::Qr>()
{
  return "qrmsg::srv::Qr";
}

template<>
inline const char * name<qrmsg::srv::Qr>()
{
  return "qrmsg/srv/Qr";
}

template<>
struct has_fixed_size<qrmsg::srv::Qr>
  : std::integral_constant<
    bool,
    has_fixed_size<qrmsg::srv::Qr_Request>::value &&
    has_fixed_size<qrmsg::srv::Qr_Response>::value
  >
{
};

template<>
struct has_bounded_size<qrmsg::srv::Qr>
  : std::integral_constant<
    bool,
    has_bounded_size<qrmsg::srv::Qr_Request>::value &&
    has_bounded_size<qrmsg::srv::Qr_Response>::value
  >
{
};

template<>
struct is_service<qrmsg::srv::Qr>
  : std::true_type
{
};

template<>
struct is_service_request<qrmsg::srv::Qr_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qrmsg::srv::Qr_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QRMSG__SRV__DETAIL__QR__TRAITS_HPP_
