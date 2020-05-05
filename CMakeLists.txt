cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER}) 
    project(editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(editor VERSION 0.0.3)
endif()

configure_file(version.h.in "${CMAKE_CURRENT_SOURCE_DIR}/version.h")

add_executable(editor main.cpp)
add_library(version.lib STATIC lib.cpp)

set_target_properties(editor version.lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(editor
    PUBLIC "${CMAKE_SOURCE_DIR}"
)

target_link_libraries(editor
        version.lib
)

if (MSVC)
    target_compile_options(editor PRIVATE
        /W4
    )
    target_compile_options(version.lib PRIVATE
        /W4
    )
else ()
    target_compile_options(editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(version.lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT lismut@gmail.com)

include(CPack)