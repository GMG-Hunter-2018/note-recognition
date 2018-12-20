file(GLOB SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(noter-sound STATIC ${SOURCES} ${HEADERS})

target_link_libraries(noter-sound PRIVATE portaudio_static)
