cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(tom VERSION 0.1.4 LANGUAGES CXX) 

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX /usr/ CACHE PATH "Default install prefix" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif()

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB tom_SRC ${CMAKE_CURRENT_LIST_DIR}/libtom/*.*pp)
file(GLOB tom_HDR ${CMAKE_CURRENT_LIST_DIR}/libtom/*.hpp)
add_library(tom SHARED ${tom_SRC})
target_link_libraries(tom dl stdc++fs)

add_library(tom-demo-greeter SHARED ${CMAKE_CURRENT_LIST_DIR}/greeter/greeter.cpp)
target_link_libraries(tom-demo-greeter tom)

add_executable(tom-demo ${CMAKE_CURRENT_LIST_DIR}/demo/main.cpp)
target_link_libraries(tom-demo tom)

configure_file(${CMAKE_SOURCE_DIR}/tom.pc.in ${CMAKE_BINARY_DIR}/tom.pc)
install(FILES ${CMAKE_BINARY_DIR}/tom.pc DESTINATION lib/pkgconfig)

install(
  TARGETS tom
  LIBRARY DESTINATION lib
)
install(FILES ${tom_HDR} DESTINATION include/libtom)
