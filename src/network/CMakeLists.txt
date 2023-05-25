add_library(sockets socket.hpp socket.cpp)

add_library(tcpsocket tcpsocket.hpp tcpsocket.cpp)
add_library(udpsocket udpsocket.hpp udpsocket.cpp)

target_link_libraries(tcpsocket PUBLIC sockets)
target_link_libraries(udpsocket PUBLIC sockets)

target_include_directories(tcpsocket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(udpsocket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})