// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "qrmsg/msg/detail/lf__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace qrmsg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Lf_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) qrmsg::msg::Lf(_init);
}

void Lf_fini_function(void * message_memory)
{
  auto typed_message = static_cast<qrmsg::msg::Lf *>(message_memory);
  typed_message->~Lf();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Lf_message_member_array[2] = {
  {
    "lf_k",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg::msg::Lf, lf_k),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lf_b",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg::msg::Lf, lf_b),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Lf_message_members = {
  "qrmsg::msg",  // message namespace
  "Lf",  // message name
  2,  // number of fields
  sizeof(qrmsg::msg::Lf),
  Lf_message_member_array,  // message members
  Lf_init_function,  // function to initialize message memory (memory has to be allocated)
  Lf_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Lf_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Lf_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace qrmsg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qrmsg::msg::Lf>()
{
  return &::qrmsg::msg::rosidl_typesupport_introspection_cpp::Lf_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qrmsg, msg, Lf)() {
  return &::qrmsg::msg::rosidl_typesupport_introspection_cpp::Lf_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
