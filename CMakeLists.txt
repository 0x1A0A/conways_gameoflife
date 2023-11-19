cmake_minimum_required(VERSION 3.25.2)

project(gameoflife VERSION 0.01)

set(CMAKE_BUILD_TYPE RELEASE)
set(OpenGL_GL_PREFERENCE LEGACY)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendors/raylib)
add_subdirectory(vendors/raygui/projects/CMake)

add_subdirectory(src)

