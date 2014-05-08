
#ADD_EXECUTABLE(testme test.cpp test_fact.cpp test_it.cpp test_rev.cpp test_byte.cpp test_constraints.cpp test_lambda.cpp)
ADD_EXECUTABLE(testme test_fact.cpp test_it.cpp test_rev.cpp test_byte.cpp test_constraints.cpp test_lambda.cpp test_thread.cpp test_async.cpp)

FIND_PACKAGE(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
MESSAGE(STATUS "PYTHON INCLUDE DIRS:  ${PYTHON_INCLUDE_DIRS}")
#ADD_LIBRARY(exception_translator_ext SHARED bex.cpp)

#TARGET_LINK_LIBRARIES(exception_translator_ext ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )

MESSAGE (STATUS "Boost_PROGRAM_OPTIONS ${Boost_PROGRAM_OPTIONS_LIBRARY}")
TARGET_LINK_LIBRARIES(testme  ${Boost_PROGRAM_OPTIONS_LIBRARY} ${PYTHON_LIBRARIES} gtest gtest_main)

add_test(runTest testme)
add_test(runtTest, double_test)
add_test(runTest, fact_test)
add_test(runTest, rev_test) 
add_test(runTest, lambda_test)
add_test(runTest, thread_test)

