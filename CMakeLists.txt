cmake_minimum_required(VERSION 3.17)
project(curves3d_exe)

set(CMAKE_CXX_STANDARD 17)
set(CURVES_3D_lib curves3d)

add_library(${CURVES_3D_lib}
    SHARED
        Curves3D/Circle3D.cpp
        Curves3D/Ellipse3D.cpp
        Curves3D/Helix3D.cpp
)

target_include_directories(${CURVES_3D_lib}
    PUBLIC
        Curves3D/Include
)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${CURVES_3D_lib}
)

