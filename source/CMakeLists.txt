include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(tiny_au3_SRCS
    debug.cpp
    error.cpp
    functions.cpp
    keywords.cpp
    literal.cpp
    operator.cpp
    parser.cpp
    program_options.cpp
    script.cpp
    statement.cpp
    tiny_au3.cpp
    variable.cpp
    variable_table.cpp
    variant.cpp)

add_executable(tiny-au3 ${tiny_au3_SRCS})
target_link_libraries(tiny-au3 lexer)

install(TARGETS tiny-au3 DESTINATION bin)

add_subdirectory(lexer)
