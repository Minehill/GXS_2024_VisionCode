# generated from rosidl_generator_py/resource/_idl.py.em
# with input from qrmsg:srv/Qr.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Qr_Request(type):
    """Metaclass of message 'Qr_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('qrmsg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'qrmsg.srv.Qr_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__qr__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__qr__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__qr__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__qr__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__qr__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Qr_Request(metaclass=Metaclass_Qr_Request):
    """Message class 'Qr_Request'."""

    __slots__ = [
        '_num',
        '_way',
        '_is_new',
    ]

    _fields_and_field_types = {
        'num': 'int64',
        'way': 'int64',
        'is_new': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.num = kwargs.get('num', int())
        self.way = kwargs.get('way', int())
        self.is_new = kwargs.get('is_new', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.num != other.num:
            return False
        if self.way != other.way:
            return False
        if self.is_new != other.is_new:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def num(self):
        """Message field 'num'."""
        return self._num

    @num.setter
    def num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'num' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._num = value

    @builtins.property
    def way(self):
        """Message field 'way'."""
        return self._way

    @way.setter
    def way(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'way' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'way' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._way = value

    @builtins.property
    def is_new(self):
        """Message field 'is_new'."""
        return self._is_new

    @is_new.setter
    def is_new(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_new' field must be of type 'bool'"
        self._is_new = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_Qr_Response(type):
    """Metaclass of message 'Qr_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('qrmsg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'qrmsg.srv.Qr_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__qr__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__qr__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__qr__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__qr__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__qr__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Qr_Response(metaclass=Metaclass_Qr_Response):
    """Message class 'Qr_Response'."""

    __slots__ = [
        '_finish',
        '_way',
        '_dis',
    ]

    _fields_and_field_types = {
        'finish': 'boolean',
        'way': 'int64',
        'dis': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.finish = kwargs.get('finish', bool())
        self.way = kwargs.get('way', int())
        self.dis = kwargs.get('dis', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.finish != other.finish:
            return False
        if self.way != other.way:
            return False
        if self.dis != other.dis:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def finish(self):
        """Message field 'finish'."""
        return self._finish

    @finish.setter
    def finish(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'finish' field must be of type 'bool'"
        self._finish = value

    @builtins.property
    def way(self):
        """Message field 'way'."""
        return self._way

    @way.setter
    def way(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'way' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'way' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._way = value

    @builtins.property
    def dis(self):
        """Message field 'dis'."""
        return self._dis

    @dis.setter
    def dis(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dis' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dis' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dis = value


class Metaclass_Qr(type):
    """Metaclass of service 'Qr'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('qrmsg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'qrmsg.srv.Qr')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__qr

            from qrmsg.srv import _qr
            if _qr.Metaclass_Qr_Request._TYPE_SUPPORT is None:
                _qr.Metaclass_Qr_Request.__import_type_support__()
            if _qr.Metaclass_Qr_Response._TYPE_SUPPORT is None:
                _qr.Metaclass_Qr_Response.__import_type_support__()


class Qr(metaclass=Metaclass_Qr):
    from qrmsg.srv._qr import Qr_Request as Request
    from qrmsg.srv._qr import Qr_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
