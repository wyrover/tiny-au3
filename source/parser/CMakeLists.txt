include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(parser_SRCS
    list_element.cpp
    literal.cpp
    operator.cpp
    parser.cpp
    statement.cpp
    variable.cpp
    variable_table.cpp
    variant.cpp)

add_library(parser STATIC ${parser_SRCS})
