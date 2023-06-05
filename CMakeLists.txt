cmake_minimum_required(VERSION 3.25)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FETCHCONTENT_DECLARE(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(Hexxagon Board.cpp Board.h Logic.cpp Logic.h Positions.cpp Positions.h Game.cpp Game.h Move.cpp Move.h SavingLoading.cpp SavingLoading.h main.cpp AI.cpp AI.h GUI.cpp GUI.h GUI.h)
target_link_libraries(Hexxagon PRIVATE sfml-system sfml-window
        sfml-graphics)