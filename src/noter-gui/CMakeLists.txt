file(GLOB SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB UIS LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")
file(GLOB RESOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc")

add_executable(noter-gui WIN32 ${SOURCES} ${HEADERS} ${UIS} ${RESOURCES})
target_link_libraries(noter-gui PRIVATE noter)

target_link_libraries(noter-gui PRIVATE portaudio_static)
target_link_libraries(noter-gui PRIVATE noter-sound)


# QT Settings
target_include_directories(noter-gui PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(noter-gui PRIVATE Qt5::Widgets)
set_target_properties(noter-gui PROPERTIES AUTOMOC On
	                                       AUTOUIC On
	                                       AUTORCC On)
