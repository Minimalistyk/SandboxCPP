cmake_minimum_required(VERSION 3.14)
project(SandSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------------------------
# ZYSK: Wymuszamy kompilację statyczną. Zero plików .dll. Wszystko w jednym .exe.
# -----------------------------------------------------------------------------
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Force static compilation" FORCE)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
)

if(APPLE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(SFML_INSTALL OFF CACHE BOOL "" FORCE)
endif()

message(STATUS "Sprawdzanie/Pobieranie SFML...")
FetchContent_MakeAvailable(SFML)
message(STATUS "SFML gotowy.")

# -----------------------------------------------------------------------------
# Wasz Kod
# -----------------------------------------------------------------------------
add_executable(SandSim main.cpp)

# Mówimy kompilatorowi: Używamy wersji statycznej
target_compile_definitions(SandSim PRIVATE SFML_STATIC)

# Podpinamy moduły graficzne, okienkowe i systemowe (dla pewności wszystko)
target_link_libraries(SandSim PRIVATE sfml-graphics sfml-window sfml-system)