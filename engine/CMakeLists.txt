cmake_minimum_required(VERSION 3.10)

# variables for libraries
set(GLEW_INCLUDES "" CACHE FILEPATH "GLEW includes directory")
set(GLEW_LIBRARIES "" CACHE FILEPATH "GLEW lib directory")
set(SPDLOG_INCLUDES "" CACHE FILEPATH "SPDLOG includes directory")
set(SPDLOG_LIBRARIES "" CACHE FILEPATH "SPDLOG lib directory")
set(SDL2_INCLUDES "" CACHE FILEPATH "SDL2 includes directory")
set(SDL2_LIBRARIES "" CACHE FILEPATH "SDL2 lib directory")
set(OPENAL_INCLUDES "" CACHE FILEPATH "OpenAL includes directory")
set(OPENAL_LIBRARIES "" CACHE FILEPATH "OpenAL lib directory")
set(KABUKI_LIBRARIES ${GLEW_LIBRARIES} ${SPDLOG_LIBRARIES} ${SDL2_LIBRARIES} ${OPENAL_LIBRARIES} PARENT_SCOPE)
set(KABUKI_INCLUDES ${GLEW_INCLUDES} ${SPDLOG_INCLUDES} ${SDL2_INCLUDES} ${OPENAL_INCLUDES} "./engine/include" PARENT_SCOPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

list(APPEND CMAKE_PREFIX_PATH "./lib/glew")
find_package(GLEW REQUIRED)

# set the project name
project(Kabuki)

# set where linker looks for libraries
link_directories(${GLEW_LIBRARIES} ${SDL2_LIBRARIES} ${SPDLOG_LIBRARIES})

# add the executable
add_library(${PROJECT_NAME} STATIC  ./src/engine.cpp 
                                    ./src/window.cpp 
                                    ./src/stage.cpp 
                                    ./src/input/input_manager.cpp 
                                    ./src/input/keyboard.cpp 
                                    ./src/utility/log.cpp)

# add includes
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDES} ${SDL2_INCLUDES} ${SPDLOG_INCLUDES} ${OPENAL_INCLUDES} "./include")

# add libraries
target_link_libraries(${PROJECT_NAME} SDL2 SDL2main glew32s opengl32 spdlog OpenAL32)
