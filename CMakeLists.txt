cmake_minimum_required(VERSION 3.20.4)

project(qt-league-spectator
	VERSION 1.0.0
	LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 Widgets REQUIRED CONFIG)

include(windeployqt)

qt6_add_resources(QRC_SOURCES
	src/view/view.qrc
)

qt6_wrap_cpp(MOC_SOURCES
	src/model/playerspectator.hpp
	src/viewmodel/data.hpp
	src/viewmodel/players.hpp
	src/viewmodel/window.hpp
)

set(HEADERS
	src/persistance/player.hpp
	src/persistance/playerdatabase.hpp
	src/model/playerspectator.hpp
	src/viewmodel/data.hpp
	src/viewmodel/players.hpp
	src/viewmodel/window.hpp
)

set(SOURCES
	src/persistance/playerdatabase.cpp
	src/model/playerspectator.cpp
	src/viewmodel/data.cpp
	src/viewmodel/players.cpp
	src/viewmodel/window.cpp
	src/main.cpp
)

add_executable(qt-league-spectator
	WIN32
    ${QRC_SOURCES}
	${MOC_SOURCES}
	${HEADERS}
	${SOURCES}
)

target_include_directories(qt-league-spectator
PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(qt-league-spectator
PUBLIC
	cxx_std_17
)

target_link_libraries(qt-league-spectator
PUBLIC
	Qt6::Core
	Qt6::Gui
	Qt6::Quick
	Qt6::QuickControls2
	Qt6::Widgets
	dxgi
	dxguid
	d3d11
)

include(GNUInstallDirs)

install(TARGETS qt-league-spectator
    DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

windeployqt(qt-league-spectator ${CMAKE_INSTALL_BINDIR})

set(CMAKE_APP_TARGET_NAME "qt-league-spectator.exe")

configure_file(
    installer/installer.iss.in
    installer.generated.iss
)
