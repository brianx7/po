
ADD_EXECUTABLE(testme test.cpp test_fact.cpp)
#ADD_EXECUTABLE(fact_test test_fact.cpp)

MESSAGE (STATUS "Boost_PROGRAM_OPTIONS ${Boost_PROGRAM_OPTIONS_LIBRARY}")
TARGET_LINK_LIBRARIES(testme  ${Boost_PROGRAM_OPTIONS_LIBRARY} gtest gtest_main)
#TARGET_LINK_LIBRARIES(fact_test gtest gtest_main)
add_test(runTest testme)
#add_test(runTest fact_test)