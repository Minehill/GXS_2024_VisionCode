// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qrmsg/srv/detail/qr__rosidl_typesupport_introspection_c.h"
#include "qrmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qrmsg/srv/detail/qr__functions.h"
#include "qrmsg/srv/detail/qr__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qrmsg__srv__Qr_Request__init(message_memory);
}

void qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_fini_function(void * message_memory)
{
  qrmsg__srv__Qr_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_member_array[3] = {
  {
    "num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Request, num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "way",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Request, way),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_new",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Request, is_new),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_members = {
  "qrmsg__srv",  // message namespace
  "Qr_Request",  // message name
  3,  // number of fields
  sizeof(qrmsg__srv__Qr_Request),
  qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_member_array,  // message members
  qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_type_support_handle = {
  0,
  &qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qrmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Request)() {
  if (!qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_type_support_handle.typesupport_identifier) {
    qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qrmsg__srv__Qr_Request__rosidl_typesupport_introspection_c__Qr_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qrmsg/srv/detail/qr__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qrmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qrmsg/srv/detail/qr__functions.h"
// already included above
// #include "qrmsg/srv/detail/qr__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qrmsg__srv__Qr_Response__init(message_memory);
}

void qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_fini_function(void * message_memory)
{
  qrmsg__srv__Qr_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_member_array[3] = {
  {
    "finish",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Response, finish),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "way",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Response, way),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qrmsg__srv__Qr_Response, dis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_members = {
  "qrmsg__srv",  // message namespace
  "Qr_Response",  // message name
  3,  // number of fields
  sizeof(qrmsg__srv__Qr_Response),
  qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_member_array,  // message members
  qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_type_support_handle = {
  0,
  &qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qrmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Response)() {
  if (!qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_type_support_handle.typesupport_identifier) {
    qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qrmsg__srv__Qr_Response__rosidl_typesupport_introspection_c__Qr_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "qrmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "qrmsg/srv/detail/qr__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_members = {
  "qrmsg__srv",  // service namespace
  "Qr",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_Request_message_type_support_handle,
  NULL  // response message
  // qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_Response_message_type_support_handle
};

static rosidl_service_type_support_t qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_type_support_handle = {
  0,
  &qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qrmsg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr)() {
  if (!qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_type_support_handle.typesupport_identifier) {
    qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qrmsg, srv, Qr_Response)()->data;
  }

  return &qrmsg__srv__detail__qr__rosidl_typesupport_introspection_c__Qr_service_type_support_handle;
}
