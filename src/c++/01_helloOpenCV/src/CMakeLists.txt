set(SOURCE_FILES "main.cpp")

# TODO implement linux and mac versions as well!

set(OPENCV_INCLUDE ${OPENCV_LOCATION}/include)

if (WIN32)
	if (${CMAKE_GENERATOR} STREQUAL "Visual Studio 14 2015 Win64")
		set(OPENCV_LIBRARY ${OPENCV_LOCATION}/x64/vc14/lib)
		set(OPENCV_LIBS opencv_world310d.lib)
	endif()
endif()


include_directories(${OPENCV_INCLUDE})
link_directories(${OPENCV_LIBRARY})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIBS})
