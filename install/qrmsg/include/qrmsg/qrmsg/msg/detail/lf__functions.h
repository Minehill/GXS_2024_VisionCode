// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice

#ifndef QRMSG__MSG__DETAIL__LF__FUNCTIONS_H_
#define QRMSG__MSG__DETAIL__LF__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "qrmsg/msg/rosidl_generator_c__visibility_control.h"

#include "qrmsg/msg/detail/lf__struct.h"

/// Initialize msg/Lf message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qrmsg__msg__Lf
 * )) before or use
 * qrmsg__msg__Lf__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__init(qrmsg__msg__Lf * msg);

/// Finalize msg/Lf message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
void
qrmsg__msg__Lf__fini(qrmsg__msg__Lf * msg);

/// Create msg/Lf message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qrmsg__msg__Lf__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
qrmsg__msg__Lf *
qrmsg__msg__Lf__create();

/// Destroy msg/Lf message.
/**
 * It calls
 * qrmsg__msg__Lf__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
void
qrmsg__msg__Lf__destroy(qrmsg__msg__Lf * msg);

/// Check for msg/Lf message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__are_equal(const qrmsg__msg__Lf * lhs, const qrmsg__msg__Lf * rhs);

/// Copy a msg/Lf message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__copy(
  const qrmsg__msg__Lf * input,
  qrmsg__msg__Lf * output);

/// Initialize array of msg/Lf messages.
/**
 * It allocates the memory for the number of elements and calls
 * qrmsg__msg__Lf__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__Sequence__init(qrmsg__msg__Lf__Sequence * array, size_t size);

/// Finalize array of msg/Lf messages.
/**
 * It calls
 * qrmsg__msg__Lf__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
void
qrmsg__msg__Lf__Sequence__fini(qrmsg__msg__Lf__Sequence * array);

/// Create array of msg/Lf messages.
/**
 * It allocates the memory for the array and calls
 * qrmsg__msg__Lf__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
qrmsg__msg__Lf__Sequence *
qrmsg__msg__Lf__Sequence__create(size_t size);

/// Destroy array of msg/Lf messages.
/**
 * It calls
 * qrmsg__msg__Lf__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
void
qrmsg__msg__Lf__Sequence__destroy(qrmsg__msg__Lf__Sequence * array);

/// Check for msg/Lf message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__Sequence__are_equal(const qrmsg__msg__Lf__Sequence * lhs, const qrmsg__msg__Lf__Sequence * rhs);

/// Copy an array of msg/Lf messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qrmsg
bool
qrmsg__msg__Lf__Sequence__copy(
  const qrmsg__msg__Lf__Sequence * input,
  qrmsg__msg__Lf__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // QRMSG__MSG__DETAIL__LF__FUNCTIONS_H_
