CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(clibhashmap)

INCLUDE_DIRECTORIES(include)

ADD_DEFINITIONS(-Wall -Werror -Wextra -g -ggdb)

ADD_SUBDIRECTORY(lib build/lib)
ADD_SUBDIRECTORY(tests build/tests)
ADD_SUBDIRECTORY(demo build/demo)


