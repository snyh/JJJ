cmake_minimum_required(VERSION 2.6.8)
project(JJJ)
set(CMAKE_CPP_FLAGS "-DBOOST_THREAD_USE_LIB")

find_package(wxWidgets COMPONENTS core base adv html REQUIRED)
find_package(Boost 1.44.0 COMPONENTS filesystem thread system REQUIRED) 
include (${wxWidgets_USE_FILE})
if(WIN32)
	set(WINSRC src/excel.cpp src/templ.cpp)
endif(WIN32)
add_executable(JJJ src/main.cpp src/dir.cpp src/gui.cpp src/entry.hpp src/strip.cpp ${WINSRC})

target_link_libraries(JJJ ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES} crypto) 
