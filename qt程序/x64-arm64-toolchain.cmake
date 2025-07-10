# x64-arm64-toolchain.cmake
# This toolchain file is used for cross-compiling for ARM64 from an x64 host

# System information
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8-a")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a")
# Cache variables
set(CMAKE_CROSSCOMPILING TRUE CACHE BOOL "Cross-compiling for ARM64")

# Qt6 configuration for cross-compiling
set(Qt6_DIR /usr/lib/aarch64-linux-gnu/cmake/Qt6)
set(CMAKE_PREFIX_PATH ${Qt6_DIR} ${CMAKE_PREFIX_PATH})
set(CMAKE_FIND_ROOT_PATH /usr/aarch64-linux-gnu /usr/lib/aarch64-linux-gnu)

# Don't look in host paths
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
