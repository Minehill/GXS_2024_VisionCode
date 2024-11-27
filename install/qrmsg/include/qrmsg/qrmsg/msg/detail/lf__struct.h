// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__LF__STRUCT_H_
#define QRMSG__MSG__DETAIL__LF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Lf in the package qrmsg.
typedef struct qrmsg__msg__Lf
{
  double lf_k;
  double lf_b;
} qrmsg__msg__Lf;

// Struct for a sequence of qrmsg__msg__Lf.
typedef struct qrmsg__msg__Lf__Sequence
{
  qrmsg__msg__Lf * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qrmsg__msg__Lf__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QRMSG__MSG__DETAIL__LF__STRUCT_H_
