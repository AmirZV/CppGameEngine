cmake_minimum_required(VERSION 3.24)

project(CppGameEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# --------------------------
# SFML 3
# --------------------------
FetchContent_Declare(sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
)
FetchContent_MakeAvailable(sfml)

# --------------------------
# ImGui (required by ImGui-SFML)
# --------------------------
FetchContent_Declare(imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.1
)
FetchContent_MakeAvailable(imgui)

# --------------------------
# ImGui-SFML
# --------------------------
set(IMGUI_DIR ${imgui_SOURCE_DIR} CACHE PATH "" FORCE)
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "" FORCE)
set(IMGUI_SFML_IMGUI_DEMO ON CACHE BOOL "" FORCE)

FetchContent_Declare(imgui_sfml
        GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git
        GIT_TAG v3.0
)
FetchContent_MakeAvailable(imgui_sfml)

# --------------------------
# Executable
# --------------------------
add_executable(CppGameEngine
        src/main.cpp
)

target_include_directories(CppGameEngine PRIVATE include)

target_link_libraries(CppGameEngine PRIVATE
        SFML::Graphics
        ImGui-SFML::ImGui-SFML
)

# --------------------------
# Copy DLLs on Windows
# --------------------------
if (WIN32)
    add_custom_command(TARGET CppGameEngine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            $<TARGET_FILE_DIR:SFML::Graphics>
            $<TARGET_FILE_DIR:CppGameEngine>
    )
    add_custom_command(TARGET CppGameEngine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
            $<TARGET_FILE_DIR:CppGameEngine>
    )
endif()
