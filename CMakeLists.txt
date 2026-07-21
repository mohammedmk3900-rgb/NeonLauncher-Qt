cmake_minimum_required(VERSION 3.16)

project(NeonLauncher VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# رفع خطای MSVC در ویندوز
if(MSVC)
    add_compile_definitions(_SILENCE_STDEXT_ARR_IT_DEPRECATION_WARNINGS _ITERATOR_DEBUG_LEVEL=0)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Sql)

# تعریف برنامه
qt_add_executable(NeonLauncherApp
    src/main.cpp
    src/core/Database.cpp
    src/core/Database.h
    src/core/SteamScanner.cpp
    src/core/SteamScanner.h
    src/core/GameModel.cpp
    src/core/GameModel.h
)

# تغییر اسم خروجی فایل اجرایی به NeonLauncher
set_target_properties(NeonLauncherApp PROPERTIES
    OUTPUT_NAME "NeonLauncher"
)

qt_add_qml_module(NeonLauncherApp
    URI NeonLauncher
    VERSION 1.0
    QML_FILES
        src/ui/qml/Main.qml
        src/ui/qml/GameCard.qml
        src/ui/qml/Sidebar.qml
)

target_include_directories(NeonLauncherApp PRIVATE src src/core)

target_link_libraries(NeonLauncherApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Sql
)

target_include_directories(NeonLauncher PRIVATE src src/core)

target_link_libraries(NeonLauncher PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Sql
)
