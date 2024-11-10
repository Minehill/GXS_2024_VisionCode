# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_adjust_hsv_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED adjust_hsv_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(adjust_hsv_FOUND FALSE)
  elseif(NOT adjust_hsv_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(adjust_hsv_FOUND FALSE)
  endif()
  return()
endif()
set(_adjust_hsv_CONFIG_INCLUDED TRUE)

# output package information
if(NOT adjust_hsv_FIND_QUIETLY)
  message(STATUS "Found adjust_hsv: 0.0.0 (${adjust_hsv_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'adjust_hsv' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${adjust_hsv_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(adjust_hsv_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${adjust_hsv_DIR}/${_extra}")
endforeach()
