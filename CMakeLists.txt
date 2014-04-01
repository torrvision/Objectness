project(BING_linux)
cmake_minimum_required(VERSION 2.8)

find_package(OpenMP REQUIRED)

add_library(LIBLINEAR LibLinear/linear.cpp LibLinear/linear.h LibLinear/train.c LibLinear/tron.cpp LibLinear/tron.h)
add_library(BLAS LibLinear/blas/blas.h LibLinear/blas/blasp.h LibLinear/blas/daxpy.c LibLinear/blas/ddot.c LibLinear/blas/dnrm2.c LibLinear/blas/dscal.c)

#OPENCV
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftree-vectorize")
#list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftest-coverage -fprofile-arcs")

add_executable(${PROJECT_NAME} main.cpp CmShow.h CmShow.cpp kyheader.h kyheader.cpp CmFile.h CmFile.cpp CmTimer.h
FilterTIG.h FilterTIG.cpp DataSetVOC.cpp DataSetVOC.h ImgContrastBB.h Objectness.cpp Objectness.h ValStructVec.h
LibLinear/linear.h LibLinear/linear.cpp LibLinear/tron.h LibLinear/tron.cpp LibLinear/blas/blas.h LibLinear/blas/blasp.h
LibLinear/blas/daxpy.c LibLinear/blas/ddot.c LibLinear/blas/dnrm2.c LibLinear/blas/dscal.c)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
target_link_libraries(BING_linux opencv_core opencv_imgproc opencv_highgui ${EXTERNAL_LIBS})
