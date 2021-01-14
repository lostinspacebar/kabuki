cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

# set the project name
project(Kabuki)

# add the executable
add_library(${PROJECT_NAME} STATIC  ./src/engine.cpp 
                                    ./src/window.cpp 
                                    ./src/stage.cpp 
                                    ./src/entity.cpp
                                    ./src/audio/audio_manager.cpp 
                                    ./src/audio/audio_emitter.cpp 
                                    ./src/audio/audio_listener.cpp 
                                    ./src/audio/wav_file.cpp 
                                    ./src/audio/ogg_file.cpp 
                                    ./src/input/input_manager.cpp 
                                    ./src/input/keyboard.cpp 
                                    ./src/utility/log.cpp)

# GLEW
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} libglew_static)

# SDL2
add_subdirectory(lib/sdl2 EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main)

# GLM
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} glm)

# SPDLOG
add_subdirectory(lib/spdlog EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} spdlog)

# OpenAL
set(CMAKE_BUILD_TYPE_SAVED "${CMAKE_BUILD_TYPE}")
set(CMAKE_BUILD_TYPE "Release")
add_subdirectory(lib/openal EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} OpenAL)
set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE_SAVED}")

# libogg
add_subdirectory(lib/libogg EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} ogg)

# libvorbis
add_subdirectory(lib/vorbis EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} vorbis vorbisfile)

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

# add libraries
target_link_libraries(${PROJECT_NAME} opengl32)