cmake_minimum_required(VERSION 3.23.2)
project(Chess)
set(CMAKE_CXX_STANDARD 17)
add_executable(Chess main.cpp Game.h Game.cpp Game.h Piece.cpp Piece.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Chess sfml-system sfml-window sfml-graphics sfml-audio sfml-audio)
