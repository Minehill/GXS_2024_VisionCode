// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__QR__STRUCT_H_
#define QRMSG__MSG__DETAIL__QR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Qr in the package qrmsg.
/**
  * num:当前处理物料的编号；way:处理方式，0为捡取，1为放下; new: 是否开始寻找新物体
 */
typedef struct qrmsg__msg__Qr
{
  int64_t num;
  int64_t way;
  bool is_new;
} qrmsg__msg__Qr;

// Struct for a sequence of qrmsg__msg__Qr.
typedef struct qrmsg__msg__Qr__Sequence
{
  qrmsg__msg__Qr * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qrmsg__msg__Qr__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QRMSG__MSG__DETAIL__QR__STRUCT_H_
