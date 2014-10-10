cmake_minimum_required(VERSION 2.8)
project(edflib)
find_package(HDF5 COMPONENTS CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(EDF EDFAnnotation.cpp EDFDate.cpp EDFFile.cpp EDFHeader.cpp
                EDFParser.cpp EDFPatient.cpp EDFSignalData.cpp
                EDFTime.cpp EDFUtil.cpp)

add_executable(test test.cpp)
target_link_libraries(test EDF)

if(HDF5_FOUND)
    add_executable(edf2h5 edf2h5.cpp)
    target_link_libraries(edf2h5 EDF ${HDF5_LIBRARIES})
endif()
