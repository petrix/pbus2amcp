cmake_minimum_required(VERSION 3.6)
project(pbus2amcp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Network Gui Widgets SerialPort Xml REQUIRED)

set(HEADERS
    gui/casparcg.hpp
    gui/clear.hpp
    gui/console.hpp
    gui/control.hpp
    gui/pbus.hpp
    gui/reg.hpp
    gui/window.hpp
    src/amcp.hpp
    src/casparcg.hpp
    src/macro.hpp
    src/media.hpp
    src/pbus.hpp
    src/ports.hpp
    src/trigger.hpp
)

set(SOURCES
    gui/casparcg.cpp
    gui/clear.cpp
    gui/console.cpp
    gui/control.cpp
    gui/pbus.cpp
    gui/reg.cpp
    gui/window.cpp
    src/amcp.cpp
    src/casparcg.cpp
    src/main.cpp
    src/pbus.cpp
    src/ports.cpp
)

set(FORMS
    gui/casparcg.ui
    gui/clear.ui
    gui/console.ui
    gui/control.ui
    gui/pbus.ui
    gui/reg.ui
    gui/window.ui
)

set(RESOURCES
    res/icons.qrc
)

add_executable(pbus2amcp ${SOURCES} ${FORMS} ${RESOURCES})
target_link_libraries(pbus2amcp Qt5::Core Qt5::Network Qt5::Gui Qt5::Widgets Qt5::SerialPort Qt5::Xml)
