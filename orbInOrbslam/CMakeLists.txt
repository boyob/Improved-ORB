cmake_minimum_required( VERSION 2.8 )
project(orbInOrbslam)

#set(OpenCV_DIR )
find_package(OpenCV REQUIRED)

include_directories(
	${OpenCV_DIRS}
	include
)

add_library(ORBextractor
	src/ORBextractor.cc
)
target_link_libraries(ORBextractor ${OpenCV_LIBS})

add_executable(main src/main.cc)
target_link_libraries(main ${OpenCV_LIBS} ORBextractor)
