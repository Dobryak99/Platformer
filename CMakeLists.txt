cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)

project(Game)

file(GLOB CPP_FILES "src/*.cpp" )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/module")


add_executable(Game ${CPP_FILES})

file(COPY Resources DESTINATION ${CMAKE_BINARY_DIR})



# Detect and add SFML
find_package(SFML 2 REQUIRED system window graphics audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
