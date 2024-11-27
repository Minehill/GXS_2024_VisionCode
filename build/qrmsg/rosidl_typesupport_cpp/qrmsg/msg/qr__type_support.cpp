// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "qrmsg/msg/detail/qr__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace qrmsg
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _Qr_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Qr_type_support_ids_t;

static const _Qr_type_support_ids_t _Qr_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Qr_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Qr_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Qr_type_support_symbol_names_t _Qr_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qrmsg, msg, Qr)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qrmsg, msg, Qr)),
  }
};

typedef struct _Qr_type_support_data_t
{
  void * data[2];
} _Qr_type_support_data_t;

static _Qr_type_support_data_t _Qr_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Qr_message_typesupport_map = {
  2,
  "qrmsg",
  &_Qr_message_typesupport_ids.typesupport_identifier[0],
  &_Qr_message_typesupport_symbol_names.symbol_name[0],
  &_Qr_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Qr_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Qr_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace qrmsg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qrmsg::msg::Qr>()
{
  return &::qrmsg::msg::rosidl_typesupport_cpp::Qr_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, qrmsg, msg, Qr)() {
  return get_message_type_support_handle<qrmsg::msg::Qr>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
