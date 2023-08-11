cmake_minimum_required(VERSION 3.0.0)
project(newbuuz VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(newbuuz src/newbuuz.c)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
find_library( APPLICATIONSERVICES_LIBRARY ApplicationServices )

message(STATUS "ApplicationServices Found: ${APPLICATIONSERVICES_LIBRARY}")

target_link_libraries(newbuuz "-framework CoreFoundation")
target_link_libraries(newbuuz "-framework ApplicationServices")
set_target_properties(newbuuz PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")
