include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(tiny_au3_SRCS
    debug.cpp
    error.cpp
    functions.cpp
    program_options.cpp
    script.cpp
    tiny_au3.cpp)

add_executable(tiny-au3 ${tiny_au3_SRCS})
target_link_libraries(tiny-au3 lexer parser)

install(TARGETS tiny-au3 DESTINATION bin)

add_subdirectory(lexer)
add_subdirectory(parser)
