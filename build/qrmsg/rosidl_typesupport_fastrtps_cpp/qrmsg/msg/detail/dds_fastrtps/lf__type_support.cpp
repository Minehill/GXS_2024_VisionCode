// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice
#include "qrmsg/msg/detail/lf__rosidl_typesupport_fastrtps_cpp.hpp"
#include "qrmsg/msg/detail/lf__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace qrmsg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qrmsg
cdr_serialize(
  const qrmsg::msg::Lf & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lf_k
  cdr << ros_message.lf_k;
  // Member: lf_b
  cdr << ros_message.lf_b;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qrmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  qrmsg::msg::Lf & ros_message)
{
  // Member: lf_k
  cdr >> ros_message.lf_k;

  // Member: lf_b
  cdr >> ros_message.lf_b;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qrmsg
get_serialized_size(
  const qrmsg::msg::Lf & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lf_k
  {
    size_t item_size = sizeof(ros_message.lf_k);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lf_b
  {
    size_t item_size = sizeof(ros_message.lf_b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qrmsg
max_serialized_size_Lf(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: lf_k
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: lf_b
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = qrmsg::msg::Lf;
    is_plain =
      (
      offsetof(DataType, lf_b) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Lf__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const qrmsg::msg::Lf *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Lf__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<qrmsg::msg::Lf *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Lf__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const qrmsg::msg::Lf *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Lf__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Lf(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Lf__callbacks = {
  "qrmsg::msg",
  "Lf",
  _Lf__cdr_serialize,
  _Lf__cdr_deserialize,
  _Lf__get_serialized_size,
  _Lf__max_serialized_size
};

static rosidl_message_type_support_t _Lf__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Lf__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace qrmsg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_qrmsg
const rosidl_message_type_support_t *
get_message_type_support_handle<qrmsg::msg::Lf>()
{
  return &qrmsg::msg::typesupport_fastrtps_cpp::_Lf__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qrmsg, msg, Lf)() {
  return &qrmsg::msg::typesupport_fastrtps_cpp::_Lf__handle;
}

#ifdef __cplusplus
}
#endif
