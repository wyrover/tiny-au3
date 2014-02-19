include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(tiny_au3_SRCS
    debug.cpp
    keywords.cpp
    lexer.cpp
    program_options.cpp
    script.cpp
    token.cpp
    tiny_au3.cpp)

add_executable(tiny-au3 ${tiny_au3_SRCS})

install(TARGETS tiny-au3 DESTINATION bin)
