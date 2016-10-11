message(STATUS "Building LASlib")
cmake_minimum_required(VERSION 3.2)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
endif ()

project(LASlib CXX)

if(APPLE)
  set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
endif()

set(CPP_SRC_DIR "laslib")

##------------------------------------------------------------------------------
## Dependencies
##

# add_subdirectory(fmt)
# list(APPEND INCLUDE_DIRS fmt)
# list(APPEND LIBRARIES fmt)

##------------------------------------------------------------------------------
## Sources
##

set(SOURCES
  ${CPP_SRC_DIR}/LASfile.hpp
  ${CPP_SRC_DIR}/LASheader.hpp
  )

##------------------------------------------------------------------------------
## Targets
##

add_library(laslib INTERFACE)

target_include_directories(laslib INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)

##------------------------------------------------------------------------------
## MSVC Specifics
##

if(MSVC)
  if(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 3.5)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT laslib)
  endif()
endif()
