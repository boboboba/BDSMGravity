cmake_minimum_required(VERSION 3.30)
project(untitled1)





set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME} main.cpp
        include/object.h
        include/field.h
        src/Object.cpp
        src/Field.cpp
        include/MyEvent.h
        src/MyEvent.cpp
        src/MyMath.cpp
        include/MyMath.h
        include/UI.h
        include/UiElement.h
        include/Button.h
        src/UiElement.cpp
        src/Button.cpp
        src/UI.cpp
        include/TextInput.h
        src/TextInput.cpp
        include/SomeLocator.h
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)

set(SFML_DIR "C:/Users/palka228/SFML/SFML-2.6.0-windows-vc17-64-bit/SFML-2.6.0/lib/cmake/SFML")
set(FUNCTIONS)
#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.6.0 COMPONENTS graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

set(RESOURCES
        ${CMAKE_SOURCE_DIR}/assets/fonts/sans.ttf
)

#foreach(Assets ${RESOURCES})
#    add_custom_command(
#            TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy_if_different
#            ${Assets}
#            bin
#            $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
#    )
#endforeach()