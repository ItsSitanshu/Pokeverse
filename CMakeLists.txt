cmake_minimum_required(VERSION 3.7)
set(PROJECT_VERSION 0.0.0)
project(Pokeverse LANGUAGES CXX VERSION ${PROJECT_VERSION} DESCRIPTION "A pokemon game with SDL2")

find_package(PkgConfig REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(CMAKE_CXX_FLAGS "-fpermissive -ggdb")

set(SOURCES
    src/enc/sha526.cpp
    src/enc/seasoning.cpp
    src/main.cpp
)

set(S_SOURCES
    src/server.cpp
)

add_executable(Pokeverse ${SOURCES})
add_executable(Server ${S_SOURCES})

target_include_directories(Pokeverse
    PRIVATE src/include
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2IMAGE_INCLUDE_DIRS}
)

target_link_libraries(Pokeverse
    PUBLIC ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}
)