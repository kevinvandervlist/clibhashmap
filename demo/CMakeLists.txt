SET(EXAMPLE_SRC example.c)

ADD_EXECUTABLE(example ${EXAMPLE_SRC})

TARGET_LINK_LIBRARIES(example chashmap) 
