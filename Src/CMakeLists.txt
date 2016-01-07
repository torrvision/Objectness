project(BING_linux)
cmake_minimum_required(VERSION 2.8)

find_package(OpenMP REQUIRED)

# compile LibLinear
include_directories("LibLinear")
file(GLOB SOURCES "LibLinear/*.cpp" "LibLinear/blas/*.c")
add_library(LibLinear STATIC ${SOURCES})

#OPENCV
#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)
##if this does not work, then try to uncomment the things below.
find_package( OpenCV REQUIRED )
if(OpenCV_FOUND)
 include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftree-vectorize")
#list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftest-coverage -fprofile-arcs")

# compile BING
file(GLOB SOURCES "*.cpp")
add_library(BING STATIC ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
target_link_libraries(${PROJECT_NAME} opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs ${EXTERNAL_LIBS} BING LibLinear)
