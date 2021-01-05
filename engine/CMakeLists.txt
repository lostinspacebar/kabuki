cmake_minimum_required(VERSION 3.10)

# variables for libraries
set(KABUKI_LIBRARIES ${SDL2_LIBRARIES} PARENT_SCOPE)
set(KABUKI_INCLUDES ${SDL2_INCLUDES} "./engine/include" PARENT_SCOPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

# set the project name
project(Kabuki)

# add the executable
add_library(${PROJECT_NAME} STATIC  ./src/engine.cpp 
                                    ./src/window.cpp 
                                    ./src/stage.cpp 
                                    ./src/input/input_manager.cpp 
                                    ./src/input/keyboard.cpp 
                                    ./src/utility/log.cpp)

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} libglew_static)

# SPDLOG
add_subdirectory(lib/spdlog EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} spdlog)

# OpenAL
add_subdirectory(lib/openal EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} OpenAL)

# SDL2
add_subdirectory(lib/sdl2 EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

# add libraries
target_link_libraries(${PROJECT_NAME} opengl32)
