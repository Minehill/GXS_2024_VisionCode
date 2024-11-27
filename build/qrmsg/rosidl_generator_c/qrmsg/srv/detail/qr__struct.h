// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__SRV__DETAIL__QR__STRUCT_H_
#define QRMSG__SRV__DETAIL__QR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Qr in the package qrmsg.
typedef struct qrmsg__srv__Qr_Request
{
  int64_t num;
  int64_t way;
  bool is_new;
} qrmsg__srv__Qr_Request;

// Struct for a sequence of qrmsg__srv__Qr_Request.
typedef struct qrmsg__srv__Qr_Request__Sequence
{
  qrmsg__srv__Qr_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qrmsg__srv__Qr_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Qr in the package qrmsg.
typedef struct qrmsg__srv__Qr_Response
{
  bool finish;
  int64_t way;
  double dis;
} qrmsg__srv__Qr_Response;

// Struct for a sequence of qrmsg__srv__Qr_Response.
typedef struct qrmsg__srv__Qr_Response__Sequence
{
  qrmsg__srv__Qr_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qrmsg__srv__Qr_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QRMSG__SRV__DETAIL__QR__STRUCT_H_
