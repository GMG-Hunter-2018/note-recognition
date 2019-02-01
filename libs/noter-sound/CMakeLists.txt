file(GLOB SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(noter-sound STATIC ${SOURCES} ${HEADERS})
target_include_directories(noter-sound PUBLIC ${CMAKE_SOURCE_DIR}/include)       # Public interface headers
target_include_directories(noter-sound PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})      # Local headers

target_link_libraries(noter-sound PRIVATE portaudio_static)
