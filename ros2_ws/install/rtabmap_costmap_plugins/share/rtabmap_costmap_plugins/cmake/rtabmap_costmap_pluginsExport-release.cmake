#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rtabmap_costmap_plugins::rtabmap_costmap_plugins" for configuration "Release"
set_property(TARGET rtabmap_costmap_plugins::rtabmap_costmap_plugins APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rtabmap_costmap_plugins::rtabmap_costmap_plugins PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librtabmap_costmap_plugins.so"
  IMPORTED_SONAME_RELEASE "librtabmap_costmap_plugins.so"
  )

list(APPEND _cmake_import_check_targets rtabmap_costmap_plugins::rtabmap_costmap_plugins )
list(APPEND _cmake_import_check_files_for_rtabmap_costmap_plugins::rtabmap_costmap_plugins "${_IMPORT_PREFIX}/lib/librtabmap_costmap_plugins.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
