## Set compiler flags to turn off optimization and enable coverage
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

## Build Test Executables
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include)                                   
SET(TEST_BIN ${PROJECT_NAME}-unittests)
ADD_EXECUTABLE(${TEST_BIN} ${TEST_SRCS} ${PROJECT_SRCS})                                       
TARGET_LINK_LIBRARIES(${TEST_BIN} gtest_main)

## Setup (Automatic) Unit Testing
ADD_CUSTOM_TARGET(check ALL ${EXECUTABLE_OUTPUT_PATH}/${TEST_BIN} 
    DEPENDS ${TEST_BIN} COMMENT "Executing unit tests..." SOURCES ${TEST_SRCS})
ADD_CUSTOM_TARGET(tests ${EXECUTABLE_OUTPUT_PATH}/${TEST_BIN}
    DEPENDS ${TEST_BIN} COMMENT "Executing unit tests..." SOURCES ${TEST_SRCS})

## Setup Code Coverage if feature is available via compiler
IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SETUP_TARGET_FOR_COVERAGE(${PROJECT_NAME}-coverage ${TEST_BIN} coverage)
ENDIF()

