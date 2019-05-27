cmake_minimum_required(VERSION 3.13)
project(DateTime_Kostiukovych)

set(CMAKE_CXX_STANDARD 11)

add_executable(DateTime_Kostiukovych Datetime_test.cpp src/Date.cpp src/Date.h src/Time.cpp src/Time.h)