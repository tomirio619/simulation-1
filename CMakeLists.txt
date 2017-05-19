cmake_minimum_required(VERSION 3.8)
project(simulation_1)

set(GCC_COVERAGE_COMPILE_FLAGS "-D FREEGLUT_STATIC")

set(CMAKE_EXE_LINKER_FLAGS "-lfreeglut_static -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -fpermissive")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ParticleToy/CircularWireConstraint.cpp
        ParticleToy/CircularWireConstraint.h
        ParticleToy/linearSolver.cpp
        ParticleToy/linearSolver.h
        ParticleToy/Particle.cpp
        ParticleToy/Particle.h
        ParticleToy/ParticleToy.cpp
        ParticleToy/RodConstraint.cpp
        ParticleToy/RodConstraint.h
        ParticleToy/Solver.cpp
        ParticleToy/SpringForce.cpp
        ParticleToy/SpringForce.h
        ParticleToy/stdafx.cpp
        ParticleToy/stdafx.h
        ParticleToy/targetver.h)

find_package (OpenGL REQUIRED)
#find_package (GLUT REQUIRED)

link_directories(ParticleToy/lib/freeglut)

include_directories(${OPENGL_INCLUDE_DIR} ParticleToy/include)

add_executable(simulation_1 ${SOURCE_FILES})

target_link_libraries(simulation_1 ${OPENGL_LIBRARIES} freeglut)

MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )

add_custom_command(TARGET simulation_1 POST_BUILD           # Adds a post-build event to simulation_1
        COMMAND ${CMAKE_COMMAND} -E copy_if_different       # which executes "cmake - E copy_if_different..."
        ${CMAKE_CURRENT_SOURCE_DIR}/ParticleToy/lib/freeglut/bin/freeglut.dll         # <--this is in-file
        $<TARGET_FILE_DIR:simulation_1>)                    # <--this is out-file path
