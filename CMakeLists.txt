cmake_minimum_required(VERSION 3.16)
project(qml LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
qt_standard_project_setup()

qt_add_executable(app
    src/main.cpp
    src/MainApp.hpp src/MainApp.cpp
    src/Storage.hpp
)

include_directories(
    models
)

qt_add_qml_module(app
    URI qml
    OUTPUT_DIRECTORY qml
    VERSION 1.0
    RESOURCE_PREFIX /qt/qml
    QML_FILES
        qml/MainWindow.qml
    SOURCES
        models/ToDoItem.hpp models/ToDoItem.cpp
        models/ToDoItems.hpp models/ToDoItems.cpp
        models/ApplicationModel.hpp
)

target_link_libraries(app
    PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Qml
        Qt::Quick
)
