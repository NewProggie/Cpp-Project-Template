## Set compiler frlags to turn off optimization and enable coverage

## Build test executables
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include)                                   
SET(TEST_BIN ${PROJECT_NAME}-unittests)
FILE(GLOB_RECURSE TEST_SRCS
    ${MAINFOLDER}/test/*.cpp ${MAINFOLDER}/test/*.h)
ADD_EXECUTABLE(${TEST_BIN} ${TEST_SRCS})                                       
TARGET_LINK_LIBRARIES(${TEST_BIN} gtest_main)
