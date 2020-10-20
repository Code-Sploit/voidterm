cmake_minimum_required(VERSION 3.5.1)

project(voidterm)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(EXEC voidterm)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/qt5/QtWidgets -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qtermwidget5 -DQt_WIDGETS_LIB, -DQT_GUI_LIB -DQT_CORE_LIB -lqtermwidget5 -lQt5Widgets -lQt5Gui -lQt5Core -fPIC -fpermissive")

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

ADD_CUSTOM_TARGET(sysinstall
        COMMAND cp ~/bin/voidterm /usr/bin/voidterm
)
