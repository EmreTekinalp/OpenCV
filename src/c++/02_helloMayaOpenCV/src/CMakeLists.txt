set(SOURCE_FILES "helloMayaOpenCV.cpp"
				 "pluginMain.cpp")
set(HEADER_FILES "helloMayaOpenCV.h")

find_package(Maya REQUIRED)

# this is the include path of opencv!
set(OPENCV_INCLUDE ${OPENCV_LOCATION}/include)

if (WIN32)
	if (${CMAKE_GENERATOR} STREQUAL "Visual Studio 14 2015 Win64")
		# Visual Studio 2015 setup
		set(OPENCV_LIBRARY ${OPENCV_LOCATION}/x64/vc14/lib)
		set(OPENCV_LIBS opencv_world310d.lib)
	endif()
endif()

# setup include and library paths
include_directories(${OPENCV_INCLUDE};${MAYA_INCLUDE})
link_directories(${OPENCV_LIBRARY};${MAYA_LIBRARY})

# setup as an executable and add libs to linker inputs
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES};${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIBS};${MAYA_LIBS})

MAYA_PLUGIN(${PROJECT_NAME})