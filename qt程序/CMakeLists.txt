cmake_minimum_required(VERSION 3.16)
project(qtccm VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Charts DataVisualization Qml)
set(QT_DEBUG_FIND_PACKAGE ON)
find_package(OpenCV REQUIRED)
find_package(GSL REQUIRED)
qt_standard_project_setup()
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)
set(HARDWARE ${CMAKE_CURRENT_SOURCE_DIR}/hardware)
# 收集所有源文件
file(GLOB UI_FILES
    ${CMAKE_AUTOUIC_SEARCH_PATHS}/*.ui
)

file(GLOB HEADER_FILES
    ${CMAKE_AUTOUIC_SEARCH_PATHS}/inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h
    ${HARDWARE}/hkcam/inc/*.h
    ${HARDWARE}/dm542/inc/*.h
)
file(GLOB SOURCE_FILES
    ${CMAKE_AUTOUIC_SEARCH_PATHS}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${HARDWARE}/hkcam/src/*.cpp
    ${HARDWARE}/dm542/src/*.cpp
)

# 添加可执行文件
qt_add_executable(qtccm
    ${UI_FILES}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(qtccm PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/qtccm_autogen/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${HARDWARE}/hkcam/inc
    ${HARDWARE}/dm542/inc
)
find_library(
    HKCAM_LIB
    NAMES MvCameraControl
    PATHS ${HARDWARE}/hkcam/lib/aarch64
    NO_DEFAULT_PATH
)
target_link_libraries(qtccm PRIVATE 
    Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Charts Qt6::DataVisualization
    GSL::gsl
    ${OpenCV_LIBS}
    ${HKCAM_LIB}
)
