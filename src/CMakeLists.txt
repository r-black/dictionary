project(app)

add_library(app_lib STATIC container.h container.cpp dictionary.h dictionary.cpp)
target_include_directories(app_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app main.cpp)
target_link_libraries(app PRIVATE app_lib)

