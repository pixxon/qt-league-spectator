cmake_minimum_required(VERSION 3.20.4)

project(qt-league-spectator
	VERSION 1.0.0
	LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 REQUIRED CONFIG)

include(windeployqt)

qt6_wrap_cpp(MOC_SOURCES
    src/rasterwindow.h
)

set(HEADERS
    src/rasterwindow.h
)

set(SOURCES
	src/main.cpp
	src/rasterwindow.cpp
)

add_executable(qt-league-spectator
	WIN32
	${MOC_SOURCES}
	${HEADERS}
	${SOURCES}
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
