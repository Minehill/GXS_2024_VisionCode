// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice
#include "qrmsg/srv/detail/qr__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
qrmsg__srv__Qr_Request__init(qrmsg__srv__Qr_Request * msg)
{
  if (!msg) {
    return false;
  }
  // num
  // way
  return true;
}

void
qrmsg__srv__Qr_Request__fini(qrmsg__srv__Qr_Request * msg)
{
  if (!msg) {
    return;
  }
  // num
  // way
}

bool
qrmsg__srv__Qr_Request__are_equal(const qrmsg__srv__Qr_Request * lhs, const qrmsg__srv__Qr_Request * rhs)
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
  return true;
}

bool
qrmsg__srv__Qr_Request__copy(
  const qrmsg__srv__Qr_Request * input,
  qrmsg__srv__Qr_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // num
  output->num = input->num;
  // way
  output->way = input->way;
  return true;
}

qrmsg__srv__Qr_Request *
qrmsg__srv__Qr_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Request * msg = (qrmsg__srv__Qr_Request *)allocator.allocate(sizeof(qrmsg__srv__Qr_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qrmsg__srv__Qr_Request));
  bool success = qrmsg__srv__Qr_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qrmsg__srv__Qr_Request__destroy(qrmsg__srv__Qr_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qrmsg__srv__Qr_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qrmsg__srv__Qr_Request__Sequence__init(qrmsg__srv__Qr_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Request * data = NULL;

  if (size) {
    data = (qrmsg__srv__Qr_Request *)allocator.zero_allocate(size, sizeof(qrmsg__srv__Qr_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qrmsg__srv__Qr_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qrmsg__srv__Qr_Request__fini(&data[i - 1]);
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
qrmsg__srv__Qr_Request__Sequence__fini(qrmsg__srv__Qr_Request__Sequence * array)
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
      qrmsg__srv__Qr_Request__fini(&array->data[i]);
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

qrmsg__srv__Qr_Request__Sequence *
qrmsg__srv__Qr_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Request__Sequence * array = (qrmsg__srv__Qr_Request__Sequence *)allocator.allocate(sizeof(qrmsg__srv__Qr_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qrmsg__srv__Qr_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qrmsg__srv__Qr_Request__Sequence__destroy(qrmsg__srv__Qr_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qrmsg__srv__Qr_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qrmsg__srv__Qr_Request__Sequence__are_equal(const qrmsg__srv__Qr_Request__Sequence * lhs, const qrmsg__srv__Qr_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qrmsg__srv__Qr_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qrmsg__srv__Qr_Request__Sequence__copy(
  const qrmsg__srv__Qr_Request__Sequence * input,
  qrmsg__srv__Qr_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qrmsg__srv__Qr_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qrmsg__srv__Qr_Request * data =
      (qrmsg__srv__Qr_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qrmsg__srv__Qr_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qrmsg__srv__Qr_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qrmsg__srv__Qr_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
qrmsg__srv__Qr_Response__init(qrmsg__srv__Qr_Response * msg)
{
  if (!msg) {
    return false;
  }
  // finish
  // way
  return true;
}

void
qrmsg__srv__Qr_Response__fini(qrmsg__srv__Qr_Response * msg)
{
  if (!msg) {
    return;
  }
  // finish
  // way
}

bool
qrmsg__srv__Qr_Response__are_equal(const qrmsg__srv__Qr_Response * lhs, const qrmsg__srv__Qr_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // finish
  if (lhs->finish != rhs->finish) {
    return false;
  }
  // way
  if (lhs->way != rhs->way) {
    return false;
  }
  return true;
}

bool
qrmsg__srv__Qr_Response__copy(
  const qrmsg__srv__Qr_Response * input,
  qrmsg__srv__Qr_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // finish
  output->finish = input->finish;
  // way
  output->way = input->way;
  return true;
}

qrmsg__srv__Qr_Response *
qrmsg__srv__Qr_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Response * msg = (qrmsg__srv__Qr_Response *)allocator.allocate(sizeof(qrmsg__srv__Qr_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qrmsg__srv__Qr_Response));
  bool success = qrmsg__srv__Qr_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qrmsg__srv__Qr_Response__destroy(qrmsg__srv__Qr_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qrmsg__srv__Qr_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qrmsg__srv__Qr_Response__Sequence__init(qrmsg__srv__Qr_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Response * data = NULL;

  if (size) {
    data = (qrmsg__srv__Qr_Response *)allocator.zero_allocate(size, sizeof(qrmsg__srv__Qr_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qrmsg__srv__Qr_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qrmsg__srv__Qr_Response__fini(&data[i - 1]);
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
qrmsg__srv__Qr_Response__Sequence__fini(qrmsg__srv__Qr_Response__Sequence * array)
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
      qrmsg__srv__Qr_Response__fini(&array->data[i]);
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

qrmsg__srv__Qr_Response__Sequence *
qrmsg__srv__Qr_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qrmsg__srv__Qr_Response__Sequence * array = (qrmsg__srv__Qr_Response__Sequence *)allocator.allocate(sizeof(qrmsg__srv__Qr_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qrmsg__srv__Qr_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qrmsg__srv__Qr_Response__Sequence__destroy(qrmsg__srv__Qr_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qrmsg__srv__Qr_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qrmsg__srv__Qr_Response__Sequence__are_equal(const qrmsg__srv__Qr_Response__Sequence * lhs, const qrmsg__srv__Qr_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qrmsg__srv__Qr_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qrmsg__srv__Qr_Response__Sequence__copy(
  const qrmsg__srv__Qr_Response__Sequence * input,
  qrmsg__srv__Qr_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qrmsg__srv__Qr_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qrmsg__srv__Qr_Response * data =
      (qrmsg__srv__Qr_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qrmsg__srv__Qr_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qrmsg__srv__Qr_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qrmsg__srv__Qr_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
