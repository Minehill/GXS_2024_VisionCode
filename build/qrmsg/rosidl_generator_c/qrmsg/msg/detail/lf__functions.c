// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qrmsg:msg/Lf.idl
// generated code does not contain a copyright notice
#include "qrmsg/msg/detail/lf__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
qrmsg__msg__Lf__init(qrmsg__msg__Lf * msg)
{
  if (!msg) {
    return false;
  }
  // lf_k
  // lf_b
  return true;
}

void
qrmsg__msg__Lf__fini(qrmsg__msg__Lf * msg)
{
  if (!msg) {
    return;
  }
  // lf_k
  // lf_b
}

bool
qrmsg__msg__Lf__are_equal(const qrmsg__msg__Lf * lhs, const qrmsg__msg__Lf * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lf_k
  if (lhs->lf_k != rhs->lf_k) {
    return false;
  }
  // lf_b
  if (lhs->lf_b != rhs->lf_b) {
    return false;
  }
  return true;
}

bool
qrmsg__msg__Lf__copy(
  const qrmsg__msg__Lf * input,
  qrmsg__msg__Lf * output)
{
  if (!input || !output) {
    return false;
  }
  // lf_k
  output->lf_k = input->lf_k;
  // lf_b
  output->lf_b = input->lf_b;
  return true;
}

qrmsg__msg__Lf *
qrmsg__msg__Lf__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Lf * msg = (qrmsg__msg__Lf *)allocator.allocate(sizeof(qrmsg__msg__Lf), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qrmsg__msg__Lf));
  bool success = qrmsg__msg__Lf__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qrmsg__msg__Lf__destroy(qrmsg__msg__Lf * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qrmsg__msg__Lf__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qrmsg__msg__Lf__Sequence__init(qrmsg__msg__Lf__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Lf * data = NULL;

  if (size) {
    data = (qrmsg__msg__Lf *)allocator.zero_allocate(size, sizeof(qrmsg__msg__Lf), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qrmsg__msg__Lf__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qrmsg__msg__Lf__fini(&data[i - 1]);
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
qrmsg__msg__Lf__Sequence__fini(qrmsg__msg__Lf__Sequence * array)
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
      qrmsg__msg__Lf__fini(&array->data[i]);
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

qrmsg__msg__Lf__Sequence *
qrmsg__msg__Lf__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__msg__Lf__Sequence * array = (qrmsg__msg__Lf__Sequence *)allocator.allocate(sizeof(qrmsg__msg__Lf__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qrmsg__msg__Lf__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qrmsg__msg__Lf__Sequence__destroy(qrmsg__msg__Lf__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qrmsg__msg__Lf__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qrmsg__msg__Lf__Sequence__are_equal(const qrmsg__msg__Lf__Sequence * lhs, const qrmsg__msg__Lf__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qrmsg__msg__Lf__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qrmsg__msg__Lf__Sequence__copy(
  const qrmsg__msg__Lf__Sequence * input,
  qrmsg__msg__Lf__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qrmsg__msg__Lf);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qrmsg__msg__Lf * data =
      (qrmsg__msg__Lf *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qrmsg__msg__Lf__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qrmsg__msg__Lf__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qrmsg__msg__Lf__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
