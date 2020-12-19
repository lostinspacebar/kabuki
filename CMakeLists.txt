cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

add_subdirectory("engine")

# set the project name
project(Kabuki_Test)

# set where linker looks for libraries
link_directories(${KABUKI_LIBRARIES})

# add the executable
add_executable(${PROJECT_NAME} main.cpp 
                               ./engine/src/engine.cpp 
                               ./engine/src/window.cpp 
                               ./engine/src/input/keyboard.cpp 
                               ./engine/src/utility/log.cpp)

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE ${KABUKI_INCLUDES})

# add libraries
target_link_libraries(${PROJECT_NAME} Kabuki)
