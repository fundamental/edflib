project(edflib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(EDF EDFAnnotation.cpp EDFDate.cpp EDFFile.cpp EDFHeader.cpp
                EDFParser.cpp EDFPatient.cpp EDFSignalData.cpp
                EDFTime.cpp EDFUtil.cpp)

add_executable(test test.cpp)
target_link_libraries(test EDF)
