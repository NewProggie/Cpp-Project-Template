## Project Properties
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(projectname)
SET(APPLICATION_NAME "Project Name")
SET(APPLICATION_CODENAME "${PROJECT_NAME}")
SET(APPLICATION_COPYRIGHT_YEARS "2014")
SET(APPLICATION_VERSION_MAJOR 1)
SET(APPLICATION_VERSION_MINOR 0)
SET(APPLICATION_VERSION_PATCH 0)
SET(APPLICATION_VERSION_TYPE SNAPSHOT)
SET(APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")
SET(APPLICATION_VENDOR_ID "com.yourcompany")
SET(APPLICATION_VENDOR_NAME "Your Company")
SET(APPLICATION_VENDOR_URL "yourcompany.com")
SET(APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")

## Debugging/Compiler options
SET(CMAKE_VERBOSE_MAKEFILE 0)
### Show all warnings
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
### Enable some extra warning flags
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
### Warn if anything depends upn the size of a function or of void
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wpointer-arith")
### Avoid int i = i
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Winit-self")
### Dont check floats for equality
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wfloat-equal")
### Warn if an unitialized identifier is evaluated
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wundef")
### Warn whenever a local variable shadows another local/global one
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wshadow")
### Warn if a pointer is cast such that alignment of target is increased
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wcast-align")
### Warn if a function is declared of defined without specifying the arg types
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wstrict-prototypes")
### Give string consts the type const char[length}
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wwrite-strings")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Waggregate-return")
### Warn whenever a poinster is cast to remove a type qualifier from target
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wcast-qual")
### Warn whenever a switch does not have a default case
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wswitch-default")
### Warn whenever a switch has an index of enumerated type and lacks a case
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wswitch-enum")
### Warn for implicit conversions that may alter a value
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wconversion")
### Warn ifh the compiler detects code that will never be executed
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wunreachable-code")
### Issue all warnings demanded by strict ISO C++
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
## Use compiler debugging flags per default
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")

## Project Output Paths
SET(MAINFOLDER ${PROJECT_SOURCE_DIR})
SET(EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET(LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")

## Project Search Paths
LIST(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}")
LIST(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/tools")
LIST(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/thirdparty")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${MAINFOLDER}/tools/share/cmake")
INCLUDE_DIRECTORIES("${MAINFOLDER}/include")

## Add Code Coverage Target for Supported Compilers
IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	INCLUDE(CodeCoverage)
ENDIF()

## Project Dependencies

## Project Sources
FILE(GLOB_RECURSE PROJECT_SRCS ${MAINFOLDER}/src/*.cpp ${MAINFOLDER}/src/*.h)
FILE(GLOB_RECURSE TEST_SRCS ${MAINFOLDER}/test/*.cpp ${MAINFOLDER}/test/*.h)

## Configure Files
FILE(GLOB_RECURSE CONFIGINPUTS1 include/*.h.in.cmake)
FILE(GLOB_RECURSE CONFIGINPUTS2 src/*.h.in.cmake)
LIST(APPEND CONFIGINPUTS "${CONFIGINPUTS1}")
LIST(APPEND CONFIGINPUTS "${CONFIGINPUTS2}")
FOREACH(CONFIGINPUT ${CONFIGINPUTS})
    STRING(REPLACE ".h.in.cmake" ".h" CONFIGOUTPUT1 "${CONFIGINPUT}")
    CONFIGURE_FILE("${CONFIGINPUT}" "${CONFIGOUTPUT1}")
ENDFOREACH(CONFIGINPUT ${CONFIGINPUTS})

## Add Build Targets
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(thirdparty)
ADD_SUBDIRECTORY(test)

## Add Install Targets
IF(EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
    INSTALL(DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}" DESTINATION "include")
ENDIF(EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")

## Add Documentation Targets
INCLUDE(DocumentationTargets)
