cmake_minimum_required(VERSION 3.16)

project(NeonLauncher VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Sql)

qt_add_executable(NeonLauncher
    src/main.cpp
    src/core/Database.cpp
    src/core/Database.h
    src/core/SteamScanner.cpp
    src/core/SteamScanner.h
)

qt_add_qml_module(NeonLauncher
    URI NeonLauncher
    VERSION 1.0
    QML_FILES
        src/ui/qml/Main.qml
        src/ui/qml/GameCard.qml
        src/ui/qml/Sidebar.qml
)

target_include_directories(NeonLauncher PRIVATE src src/core)

target_link_libraries(NeonLauncher PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Sql
)
