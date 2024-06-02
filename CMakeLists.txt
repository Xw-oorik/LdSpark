cmake_minimum_required(VERSION 3.5)

project(LdSpark VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 传递项目根目录路径到编译器
add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Charts WebEngineWidgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        http.h 
        http.cpp
        task.h 
        task.cpp
        addtask.h addtask.cpp addtask.ui
        model.h model.cpp
        tasklistitem.h tasklistitem.cpp tasklistitem.ui
        addproxywidget.h addproxywidget.cpp addproxywidget.ui
        responseinfowidget.h responseinfowidget.cpp responseinfowidget.ui
        exportgraphwidget.h exportgraphwidget.cpp exportgraphwidget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LdSpark
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        style.qrc
        
        
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LdSpark APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LdSpark SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LdSpark
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LdSpark PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(LdSpark PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(LdSpark PRIVATE Qt${QT_VERSION_MAJOR}::Charts)
target_link_libraries(LdSpark PRIVATE Qt${QT_VERSION_MAJOR}::WebEngineWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LdSpark)
endif()
set_target_properties(LdSpark PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LdSpark
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LdSpark)
endif()
