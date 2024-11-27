// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qrmsg:msg/Qr.idl
// generated code does not contain a copyright notice
#include "qrmsg/msg/detail/qr__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
qrmsg__msg__Qr__init(qrmsg__msg__Qr * msg)
{
  if (!msg) {
    return false;
  }
  // num
  // way
  // is_new
  return true;
}

void
qrmsg__msg__Qr__fini(qrmsg__msg__Qr * msg)
{
  if (!msg) {
    return;
  }
  // num
  // way
  // is_new
}

bool
qrmsg__msg__Qr__are_equal(const qrmsg__msg__Qr * lhs, const qrmsg__msg__Qr * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num
  if (lhs->num != rhs->num) {
    return false;
  }
  // way
  if (lhs->way != rhs->way) {
    return false;
  }
  // is_new
  if (lhs->is_new != rhs->is_new) {
    return false;
  }
  return true;
}

bool
qrmsg__msg__Qr__copy(
  const qrmsg__msg__Qr * input,
  qrmsg__msg__Qr * output)
{
  if (!input || !output) {
    return false;
  }
  // num
  output->num = input->num;
  // way
  output->way = input->way;
  // is_new
  output->is_new = input->is_new;
  return true;
}

qrmsg__msg__Qr *
qrmsg__msg__Qr__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Qr * msg = (qrmsg__msg__Qr *)allocator.allocate(sizeof(qrmsg__msg__Qr), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qrmsg__msg__Qr));
  bool success = qrmsg__msg__Qr__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qrmsg__msg__Qr__destroy(qrmsg__msg__Qr * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qrmsg__msg__Qr__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qrmsg__msg__Qr__Sequence__init(qrmsg__msg__Qr__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Qr * data = NULL;

  if (size) {
    data = (qrmsg__msg__Qr *)allocator.zero_allocate(size, sizeof(qrmsg__msg__Qr), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qrmsg__msg__Qr__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qrmsg__msg__Qr__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
qrmsg__msg__Qr__Sequence__fini(qrmsg__msg__Qr__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qrmsg__msg__Qr__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

qrmsg__msg__Qr__Sequence *
qrmsg__msg__Qr__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Qr__Sequence * array = (qrmsg__msg__Qr__Sequence *)allocator.allocate(sizeof(qrmsg__msg__Qr__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qrmsg__msg__Qr__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qrmsg__msg__Qr__Sequence__destroy(qrmsg__msg__Qr__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qrmsg__msg__Qr__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qrmsg__msg__Qr__Sequence__are_equal(const qrmsg__msg__Qr__Sequence * lhs, const qrmsg__msg__Qr__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qrmsg__msg__Qr__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qrmsg__msg__Qr__Sequence__copy(
  const qrmsg__msg__Qr__Sequence * input,
  qrmsg__msg__Qr__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qrmsg__msg__Qr);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qrmsg__msg__Qr * data =
      (qrmsg__msg__Qr *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qrmsg__msg__Qr__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qrmsg__msg__Qr__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qrmsg__msg__Qr__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
