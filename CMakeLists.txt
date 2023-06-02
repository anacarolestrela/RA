cmake_minimum_required(VERSION 3.16...3.25)

project(bahiart VERSION 1.0
                DESCRIPTION ""
                LANGUAGES CXX) 
 
add_subdirectory(src)

#using network manager debug main
add_executable(bahiart tests/networkmodel/testNetworkModel.cpp)
target_link_libraries(bahiart LINK_PUBLIC tcpsocket)


add_executable(jurema src/agent/jurema.cpp)
target_link_libraries(jurema LINK_PUBLIC tcpsocket)
 

