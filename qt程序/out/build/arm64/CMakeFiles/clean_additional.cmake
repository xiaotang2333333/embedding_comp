# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/qtccm_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtccm_autogen.dir/ParseCache.txt"
  "qtccm_autogen"
  )
endif()
