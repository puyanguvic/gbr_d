cmake_minimum_required(VERSION 3.10)

project(gbr_daemon VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tests)

include_directories(include)

add_executable(gbr_daemon src/main.cpp)

target_link_libraries(gbr_daemon, utils)
# target_link_libraries(gbr_daemon PRIVATE router neighbor packet lsa lsdb table utils buffer priority path_selection)

install(TARGETS gbr_daemon DESTINATION /usr/local/bin)
