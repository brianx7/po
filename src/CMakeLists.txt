
ADD_EXECUTABLE(testme test.cpp test_fact.cpp test_it.cpp test_rev.cpp)

MESSAGE (STATUS "Boost_PROGRAM_OPTIONS ${Boost_PROGRAM_OPTIONS_LIBRARY}")
TARGET_LINK_LIBRARIES(testme  ${Boost_PROGRAM_OPTIONS_LIBRARY} gtest gtest_main)

add_test(runTest testme)
add_test(runtTest, double_test)
add_test(runTest, fact_test)
add_test(runTest, rev_test) 