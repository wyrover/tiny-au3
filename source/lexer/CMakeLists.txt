include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(lexer_SRCS
    lexer.cpp
    operator_table.cpp
    token.cpp
    token_null.cpp
    token_factory.cpp
    token_literal.cpp
    token_operator.cpp
    token_variable.cpp)

add_library(lexer STATIC ${lexer_SRCS})
