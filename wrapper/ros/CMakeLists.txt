CMAKE_MINIMUM_REQUIRED (VERSION 3.1)

################################
# OpenMapper
################################

PROJECT("OpenMapperROS")

SET(OPENMAPPER_ROS_NODE "OpenMapperROS")

# Request C++11 standard from compiler.
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Suppress warnings from the compiler.
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -w")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

################################
# Define Sources and Headers
################################

FILE(GLOB_RECURSE OM_WRAPPER_ROS_NODE_HEADERS "${CMAKE_CURRENT_LIST_DIR}/src/ros/*.h")
FILE(GLOB OM_WRAPPER_ROS_NODE_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/ros/*.cc")


################################
# Define Dependencies
################################

# Include OpenMapper lib
INCLUDE("${CMAKE_CURRENT_LIST_DIR}../../CMakeLists.txt")

FIND_PACKAGE(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
)

CATKIN_PACKAGE(CATKIN_DEPENDS
  roscpp
  std_msgs
  sensor_msgs
  cv_bridge
  opencv
  image_transport
  pthread
)

SET(THREADS_PREFER_PTHREAD_FLAG ON)
INCLUDE_DIRECTORIES(${catkin_INCLUDE_DIRS})

################################
# Define OpenMapper ROS Node
################################

ADD_EXECUTABLE(${OPENMAPPER_ROS_NODE}
  ${OPENMAPPER_ROS_NODE_HEADERS}
  ${OPENMAPPER_ROS_NODE_SOURCES}
)

TARGET_LINK_LIBRARIES(${OPENMAPPER_ROS_NODE}
  debug ${OPENMAPPER_LIB} optimized ${OPENMAPPER_LIB}
)


# Uncomment to display all CMAKE variables:
# GET_CMAKE_PROPERTY(VARIABLE_NAMES VARIABLES)
# FOREACH (VARIABLE_NAME ${VARIABLE_NAMES})
#    MESSAGE(STATUS "${VARIABLE_NAME}=${${VARIABLE_NAME}}")
# ENDFOREACH()