cmake_minimum_required(VERSION 3.25.2)

project(gameoflife VERSION 0.01)

set(CMAKE_BUILD_TYPE RELEASE)
set(OpenGL_GL_PREFERENCE LEGACY)

add_subdirectory(vendors/raylib-4.5.0)
add_subdirectory(vendors/raygui-3.2/projects/CMake)

add_subdirectory(src)

