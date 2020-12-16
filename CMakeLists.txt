cmake_minimum_required(VERSION 3.10)

# variables for libraries
set(GLEW_INCLUDES "" CACHE FILEPATH "GLEW includes directory")
set(GLFW_INCLUDES "" CACHE FILEPATH "GLFW includes directory")
set(SPDLOG_INCLUDES "" CACHE FILEPATH "SPDLOG includes directory")
set(GLEW_LIBRARIES "" CACHE FILEPATH "GLEW lib directory")
set(GLFW_LIBRARIES "" CACHE FILEPATH "GLFW lib directory")
set(SPDLOG_LIBRARIES "" CACHE FILEPATH "SPDLOG lib directory")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

# set the project name
project(Kabuki_Test)

# set where linker looks for libraries
link_directories(${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${SPDLOG_LIBRARIES})

# add the executable
add_executable(${PROJECT_NAME} main.cpp 
                               ./engine/engine.cpp 
                               ./engine/window.hpp 
                               ./engine/utility/log.cpp)

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDES} ${GLFW_INCLUDES} ${SPDLOG_INCLUDES})

# add libraries
target_link_libraries(${PROJECT_NAME} glfw3 glew32s opengl32 spdlog)
