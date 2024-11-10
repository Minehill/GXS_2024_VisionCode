// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from qrmsg:srv/Qr.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "qrmsg/srv/detail/qr__struct.h"
#include "qrmsg/srv/detail/qr__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool qrmsg__srv__qr__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[25];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("qrmsg.srv._qr.Qr_Request", full_classname_dest, 24) == 0);
  }
  qrmsg__srv__Qr_Request * ros_message = _ros_message;
  {  // num
    PyObject * field = PyObject_GetAttrString(_pymsg, "num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // way
    PyObject * field = PyObject_GetAttrString(_pymsg, "way");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->way = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // is_new
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_new");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_new = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * qrmsg__srv__qr__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Qr_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("qrmsg.srv._qr");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Qr_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  qrmsg__srv__Qr_Request * ros_message = (qrmsg__srv__Qr_Request *)raw_ros_message;
  {  // num
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // way
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->way);
    {
      int rc = PyObject_SetAttrString(_pymessage, "way", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_new
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_new ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_new", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "qrmsg/srv/detail/qr__struct.h"
// already included above
// #include "qrmsg/srv/detail/qr__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool qrmsg__srv__qr__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[26];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("qrmsg.srv._qr.Qr_Response", full_classname_dest, 25) == 0);
  }
  qrmsg__srv__Qr_Response * ros_message = _ros_message;
  {  // finish
    PyObject * field = PyObject_GetAttrString(_pymsg, "finish");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->finish = (Py_True == field);
    Py_DECREF(field);
  }
  {  // way
    PyObject * field = PyObject_GetAttrString(_pymsg, "way");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->way = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // dis
    PyObject * field = PyObject_GetAttrString(_pymsg, "dis");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dis = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * qrmsg__srv__qr__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Qr_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("qrmsg.srv._qr");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Qr_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  qrmsg__srv__Qr_Response * ros_message = (qrmsg__srv__Qr_Response *)raw_ros_message;
  {  // finish
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->finish ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "finish", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // way
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->way);
    {
      int rc = PyObject_SetAttrString(_pymessage, "way", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dis
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}