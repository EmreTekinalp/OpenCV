set(SOURCE_FILES
	"main.cpp"
	"mainWindow.cpp")
set(HEADER_FILES
	"helloQtOpenCV.h"
	"mainWindow.h")
set(UI_FILES
	"helloQtOpenCV.ui")	

set(CMAKE_INCLUDE_CURRENT_DIR ON)
	
# find Qt5
find_package(Qt5Widgets REQUIRED)

# get lib path and specify required libs
set(QT_LIBRARY_DIRS ${_qt5Widgets_install_prefix}/lib)
set(QT_LIBS qtmaind.lib Qt5Cored Qt5Guid Qt5Widgetsd Qt5OpenGLd)

# IMPORTANT environmentVariable OPENCV_DIR needs to be set to make this works
set(OPENCV_LOCATION $ENV{OPENCV_DIR})
# this is the include path of opencv
set(OPENCV_INCLUDE ${OPENCV_LOCATION}/include)

if (WIN32)
	if (${CMAKE_GENERATOR} STREQUAL "Visual Studio 14 2015 Win64")
		# Visual Studio 2015 setup
		set(OPENCV_LIBRARY ${OPENCV_LOCATION}/x64/vc14/lib)
		set(OPENCV_LIBS opencv_world310d.lib)
	endif()
endif()

# setup include and library paths
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${OPENCV_INCLUDE})
link_directories(${QT_LIBRARY_DIRS} ${OPENCV_LIBRARY})
add_definitions(${Qt5Widgets_DEFINITIONS})

qt5_wrap_cpp(MOCS_HDRS ${HEADER_FILES})
qt5_wrap_ui(UI_HDRS ${UI_FILES})

# setup as an executable and add libs to linker inputs
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${MOCS_HDRS} ${UI_HDRS})
target_link_libraries(${PROJECT_NAME} ${QT_LIBS} ${OPENCV_LIBS})

