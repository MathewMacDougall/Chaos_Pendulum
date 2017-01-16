cmake_minimum_required(VERSION 3.5.1)
project(Chaos_Pendulum)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /usr/local/bin/qt/5.7/gcc_64)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
#include_directories(/usr/local/bin/qt/5.7/gcc_64/include)
#include_directories(/usr/local/bin/qt/5.7/gcc_64/include/QtGui)

# Instruct CMake to run moc automatically when needed.
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
#find_package(Qt5Widgets)
#find_package(Qt5Core)
#find_package(Qt5Gui)


set(SOURCE_FILES
        src/util/physics.cpp
        src/util/physics.hpp
        src/util/point.cpp
        src/util/point.hpp
        src/main.cpp
        src/pendulum.cpp
        src/pendulum.hpp)

set(POINT_TEST_FILES
        src/util/point.cpp
        src/util/point.hpp
        test/pointTest.cpp)

set(PENDULUM_TEST_FILES
        src/util/point.cpp
        src/util/point.hpp
        src/pendulum.cpp
        src/pendulum.hpp
        test/pendulumTest.cpp)

add_executable(Chaos_Pendulum ${SOURCE_FILES} ${QT_FILES})
add_executable(Point_Test ${POINT_TEST_FILES})
add_executable(Pendulum_Test ${PENDULUM_TEST_FILES})
target_link_libraries(Point_Test gtest gtest_main)
target_link_libraries(Pendulum_Test gtest gtest_main)
#target_link_libraries(Chaos_Pendulum Qt5::Widgets)
#target_link_libraries(Chaos_Pendulum Qt5::Core)
#target_link_libraries(Chaos_Pendulum Qt5::Gui)