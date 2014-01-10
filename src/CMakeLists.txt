
#ADD_EXECUTABLE(testme test.cpp test_fact.cpp test_it.cpp test_rev.cpp test_byte.cpp test_constraints.cpp test_lambda.cpp)
ADD_EXECUTABLE(testme test_fact.cpp test_it.cpp test_rev.cpp test_byte.cpp test_constraints.cpp test_lambda.cpp)

MESSAGE (STATUS "Boost_PROGRAM_OPTIONS ${Boost_PROGRAM_OPTIONS_LIBRARY}")
TARGET_LINK_LIBRARIES(testme  ${Boost_PROGRAM_OPTIONS_LIBRARY} gtest gtest_main)

add_test(runTest testme)
add_test(runtTest, double_test)
add_test(runTest, fact_test)
add_test(runTest, rev_test) 
add_test(runTest, lambda_test)
