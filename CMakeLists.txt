cmake_minimum_required(VERSION 3.10)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

add_subdirectory("engine")

# set the project name
project(Kabuki_Test)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE "./engine/include")

# add libraries
target_link_libraries(${PROJECT_NAME} Kabuki)

# JANK. This is to copy over SDL2 and OpenAL shared libraries. Need to do this
# better. Or maybe not. Who cares for now.
message(STATUS "Output Directory is ${CMAKE_CURRENT_BINARY_DIR}")
file(GLOB OPENAL_DLLS "${OpenAL_BINARY_DIR}/*.dll")
file(COPY ${OPENAL_DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB SDL2_DLLS "${SDL2_BINARY_DIR}/*.dll")
file(COPY ${SDL2_DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})