################################
# Google Test Setup
################################

ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/../thirdparty/googletest/googletest gtest_build)
ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# OpenMapper Tests
################################

SET(OM_WRAPPER_TESTS "OpenMapperTests")
# Add test src files
ADD_EXECUTABLE(${OM_WRAPPER_TESTS}
  ${CMAKE_CURRENT_LIST_DIR}/main.cc
  ${CMAKE_CURRENT_LIST_DIR}/pose_test.cc)

# Link test executable against gtest & gtest_main
TARGET_LINK_LIBRARIES(${OM_WRAPPER_TESTS}
  gtest gtest_main
  debug ${OM_WRAPPER_LIB} optimized ${OM_WRAPPER_LIB})

ADD_TEST(${OM_WRAPPER_TESTS} ${OM_WRAPPER_TESTS})

TARGET_INCLUDE_DIRECTORIES(${OM_WRAPPER_TESTS} PUBLIC include)

SET_TARGET_PROPERTIES(${OM_WRAPPER_TESTS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/ )
SET_TARGET_PROPERTIES(${OM_WRAPPER_TESTS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin/ )
SET_TARGET_PROPERTIES(${OM_WRAPPER_TESTS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin/ )
SET_TARGET_PROPERTIES(${OM_WRAPPER_TESTS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ../bin/)
SET_TARGET_PROPERTIES(${OM_WRAPPER_TESTS} PROPERTIES DEBUG_POSTFIX "_d" )