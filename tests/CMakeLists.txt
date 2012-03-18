# Adding a test: 
# ADD_EXECUTABLE($binary $source(s))
# TARGET_LINK_LIBRARIES($binary chashmap)
# ADD_TEST($testname $binary $args)

ENABLE_TESTING()

# Add a 'make test' target so tests are called when run.
ADD_CUSTOM_TARGET(test COMMAND ${CMAKE_CTEST_COMMAND})

ADD_EXECUTABLE(do_insert_null_retrieve_str do_insert_null_retrieve_str.c)
TARGET_LINK_LIBRARIES(do_insert_null_retrieve_str chashmap)
ADD_TEST(do_insert_null_retrieve_str do_insert_null_retrieve_str)

ADD_EXECUTABLE(duplicates_str duplicates_str.c)
TARGET_LINK_LIBRARIES(duplicates_str chashmap)
ADD_TEST(duplicates_str duplicates_str)

ADD_EXECUTABLE(dynamic_entries_str dynamic_entries_str.c)
TARGET_LINK_LIBRARIES(dynamic_entries_str chashmap)
ADD_TEST(dynamic_entries_str dynamic_entries_str)

ADD_EXECUTABLE(insert_remove_str insert_remove_str.c)
TARGET_LINK_LIBRARIES(insert_remove_str chashmap)
ADD_TEST(insert_remove_str insert_remove_str)

ADD_EXECUTABLE(insert_remove_int insert_remove_int.c)
TARGET_LINK_LIBRARIES(insert_remove_int chashmap)
ADD_TEST(insert_remove_int insert_remove_int)

ADD_EXECUTABLE(insert_retrieve_str insert_retrieve_str.c)
TARGET_LINK_LIBRARIES(insert_retrieve_str chashmap)
ADD_TEST(insert_retrieve_str insert_retrieve_str)

ADD_EXECUTABLE(iterator_str iterator_str.c)
TARGET_LINK_LIBRARIES(iterator_str chashmap)
ADD_TEST(iterator_str iterator_str)

ADD_EXECUTABLE(no_insert_null_retrieve_str no_insert_null_retrieve_str.c)
TARGET_LINK_LIBRARIES(no_insert_null_retrieve_str chashmap)
ADD_TEST(no_insert_null_retrieve_str no_insert_null_retrieve_str)

ADD_EXECUTABLE(small_map_bucket_test_str small_map_bucket_test_str.c)
TARGET_LINK_LIBRARIES(small_map_bucket_test_str chashmap)
ADD_TEST(small_map_bucket_test_str small_map_bucket_test_str)

ADD_EXECUTABLE(static_size_str static_size_str.c)
TARGET_LINK_LIBRARIES(static_size_str chashmap)
ADD_TEST(static_size_str static_size_str)
