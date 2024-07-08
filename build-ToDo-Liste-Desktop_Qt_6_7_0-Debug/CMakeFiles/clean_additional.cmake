# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ToDo-Liste_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ToDo-Liste_autogen.dir/ParseCache.txt"
  "ToDo-Liste_autogen"
  )
endif()
