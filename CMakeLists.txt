# NOTE: this was only tested with MinGW 7.2 x64

# TODO: if (GCC) define USE_GCC

# We need to use CMake 3.0+
cmake_minimum_required(VERSION 3.0)

# Define the project's name
set(PROJECT_NAME ESFE)

# Tell 'findSFML.cmake' where our SFML directory is.
# You can change the text in the quotes to use a
# custom SFML directory
set (SFML_ROOT "${CMAKE_CURRENT_LIST_DIR}/SFML")

# While in dev, compile an entry point
# for the executable
set(SOURCE_FILES 
    src/main.cpp
)

#define all the core components (game, scenes, etc.)
set(CORE_SOURCE_FILES
    src/ESFE/Core/Game.cpp
    src/ESFE/Core/SceneManager.cpp
)

# Define all the Utility source files
set(UTIL_SOURCE_FILES
    #src/ESFE/Util/ArgParser.cpp
    #src/ESFE/Util/ConfigManager.cpp
    src/ESFE/Util/Logger.cpp
    src/ESFE/Util/Random.cpp
    src/ESFE/Util/ResourceManager.cpp
)

# Define all the GUI source files
set(GUI_SOURCE_FILES
    src/ESFE/GUI/Button.cpp
    src/ESFE/GUI/Checkbox.cpp
    src/ESFE/GUI/Label.cpp
    # src/ESFE/GUI/GUILayer.cpp
)

# Define all the GameObject source files
set(GAMEOBJECT_SOURCE_FILES
    src/ESFE/GameObject/RigidBody.cpp
)

# Define all the Graphics source files
set(GRAPHICS_SOURCE_FILES
    src/ESFE/Graphics/Animation.cpp
    src/ESFE/Graphics/DisplaySurf.cpp
    src/ESFE/Graphics/EllipseShape.cpp
    src/ESFE/Graphics/ParticleSystem.cpp
)

# Tell the compiler to use c++11 standard library
set(CMAKE_CXX_STANDARD 11)

# Define the CMake project
project(${PROJECT_NAME})

# Add ESFE include directory
include_directories("${CMAKE_SOURCE_DIR}/include" "${SFML_ROOT}/include")

# Add an executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${CORE_SOURCE_FILES} ${UTIL_SOURCE_FILES} ${GRAPHICS_SOURCE_FILES} ${GUI_SOURCE_FILES})

# Add the library
# add_library(${PROJECT_NAME} ${CORE_SOURCE_FILES} ${UTIL_SOURCE_FILES} ${GRAPHICS_SOURCE_FILES})

# Add filesystem library
target_link_libraries(${PROJECT_NAME} stdc++fs gdi32)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
