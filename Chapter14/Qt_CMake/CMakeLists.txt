cmake_minimum_required(VERSION 3.0.0)
project(MyProject)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
add_executable(MyProject main.cpp mainwindow.cpp mainwindow.ui resource.qrc)
target_link_libraries(MyProject Qt5::Widgets)
