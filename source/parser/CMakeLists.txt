include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(parser_SRCS
    literal.cpp
    null_element.cpp
    operator.cpp
    parser.cpp
    statement.cpp
    statement_element.cpp
    variable.cpp
    variable_table.cpp
    variant.cpp)

add_library(parser STATIC ${parser_SRCS})
