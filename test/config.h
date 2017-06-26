// (c) 2017 OpenMapper

#ifndef TEST_CONFIG_H_
#define TEST_CONFIG_H_

#include <string>

// TODO(gocarlos): the path to the files should be the full path, when debugging
// with dbg the relative path does not work.
std::string path_to_vocabulary =
    "../thirdparty/slam_engine/ORB_SLAM2/Vocabulary/ORBvoc.txt";
std::string path_to_settings =
    "../thirdparty/slam_engine/ORB_SLAM2/Vocabulary/iphone.yaml";

std::string static_video = "../test/test_data/static.mov";
std::string dynamic_video = "../test/test_data/dynamic.mov";

#endif  // TEST_CONFIG_H_