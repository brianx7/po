
ADD_EXECUTABLE(po_test test.cpp)

MESSAGE (STATUS "Boost_PROGRAM_OPTIONS ${Boost_PROGRAM_OPTIONS_LIBRARY}")
TARGET_LINK_LIBRARIES(po_test ${Boost_PROGRAM_OPTIONS_LIBRARY} gtest gtest_main)
add_test(runTest po_test)
