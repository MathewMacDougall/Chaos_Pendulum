cmake_minimum_required(VERSION 3.6)
project(Chaos_Pendulum)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/util/angle.cpp
        src/util/angle.hpp
        src/util/physics.cpp
        src/util/physics.hpp
        src/util/point.cpp
        src/util/point.hpp
        src/util/util.cpp
        src/util/util.hpp
        src/main.cpp
        src/pendulum.cpp
        src/pendulum.hpp
        test/pointTest.cpp)

add_executable(Chaos_Pendulum ${SOURCE_FILES})
target_link_libraries(Chaos_Pendulum gtest gtest_main)