# Adding a test: 
# ADD_EXECUTABLE($binary $source(s))
# TARGET_LINK_LIBRARIES($binary chashmap)
# ADD_TEST($testname $binary $args)

ENABLE_TESTING()

# Add a 'make test' target so tests are called when run.
ADD_CUSTOM_TARGET(test COMMAND ${CMAKE_CTEST_COMMAND})

ADD_EXECUTABLE(do_insert_null_retrieve do_insert_null_retrieve.c)
TARGET_LINK_LIBRARIES(do_insert_null_retrieve chashmap)
ADD_TEST(do_insert_null_retrieve do_insert_null_retrieve)

ADD_EXECUTABLE(duplicates duplicates.c)
TARGET_LINK_LIBRARIES(duplicates chashmap)
ADD_TEST(duplicates duplicates)

ADD_EXECUTABLE(dynamic_entries dynamic_entries.c)
TARGET_LINK_LIBRARIES(dynamic_entries chashmap)
ADD_TEST(dynamic_entries dynamic_entries)

ADD_EXECUTABLE(insert_remove insert_remove.c)
TARGET_LINK_LIBRARIES(insert_remove chashmap)
ADD_TEST(insert_remove insert_remove)

ADD_EXECUTABLE(insert_retrieve insert_retrieve.c)
TARGET_LINK_LIBRARIES(insert_retrieve chashmap)
ADD_TEST(insert_retrieve insert_retrieve)

ADD_EXECUTABLE(iterator iterator.c)
TARGET_LINK_LIBRARIES(iterator chashmap)
ADD_TEST(iterator iterator)

ADD_EXECUTABLE(no_insert_null_retrieve no_insert_null_retrieve.c)
TARGET_LINK_LIBRARIES(no_insert_null_retrieve chashmap)
ADD_TEST(no_insert_null_retrieve no_insert_null_retrieve)

ADD_EXECUTABLE(small_map_bucket_test small_map_bucket_test.c)
TARGET_LINK_LIBRARIES(small_map_bucket_test chashmap)
ADD_TEST(small_map_bucket_test small_map_bucket_test)

ADD_EXECUTABLE(static_size static_size.c)
TARGET_LINK_LIBRARIES(static_size chashmap)
ADD_TEST(static_size static_size)
