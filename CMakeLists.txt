cmake_minimum_required(VERSION 3.12)
project(Hotel)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hotel main.cpp Logica.cpp Logica.hpp Quarto.cpp Quarto.hpp Estoque.cpp Estoque.hpp)