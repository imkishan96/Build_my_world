cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(welcome_world SHARED script/welcome_world.cpp)
target_link_libraries(welcome_world ${GAZEBO_LIBRARIES})

add_library(SimpleCar_plugin SHARED script/SimpleCar_plugin.cpp)
target_link_libraries(SimpleCar_plugin ${GAZEBO_LIBRARIES})

add_library(SimpleCar_plugin_1 SHARED script/SimpleCar_plugin_1.cpp)
target_link_libraries(SimpleCar_plugin_1 ${GAZEBO_LIBRARIES})

add_library(contact SHARED script/ContactPlugin.cpp)
target_link_libraries(contact ${GAZEBO_LIBRARIES})

