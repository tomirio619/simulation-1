cmake_minimum_required(VERSION 3.7)
project(simulation_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Set Compile and Linker flags

set(GCC_COVERAGE_COMPILE_FLAGS "-D FREEGLUT_STATIC")
set(GCC_COVERAGE_LINK_FLAGS    "-static")


set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(SOURCE_FILES
        ParticleToy/constraints/CircularWireConstraint.cpp
        ParticleToy/constraints/CircularWireConstraint.h
        ParticleToy/linearSolver.cpp
        ParticleToy/linearSolver.h
        ParticleToy/Particle.cpp
        ParticleToy/Particle.h
        ParticleToy/ParticleToy.cpp
        ParticleToy/constraints/RodConstraint.cpp
        ParticleToy/constraints/RodConstraint.h
        ParticleToy/solvers/Solver.cpp
        ParticleToy/forces/SpringForce.cpp
        ParticleToy/forces/SpringForce.h
        ParticleToy/forces/Force.cpp
        ParticleToy/forces/Force.h
        ParticleToy/forces/GravityForce.cpp
        ParticleToy/forces/GravityForce.h
        ParticleToy/forces/ConstraintForce.cpp
        ParticleToy/forces/ConstraintForce.h
        ParticleToy/solvers/ForwardEuler.cpp
        ParticleToy/solvers/ForwardEuler.h
        ParticleToy/solvers/RK4.cpp
        ParticleToy/solvers/RK4.h
        ParticleToy/solvers/Midpoint.cpp
        ParticleToy/solvers/Midpoint.h
        ParticleToy/LambdaSolver.cpp
        ParticleToy/LambdaSolver.h
        ParticleToy/constraints/SlidingWireConstraint.cpp
        ParticleToy/constraints/SlidingWireConstraint.h
        ParticleToy/forces/HorizontalForce.cpp
        ParticleToy/forces/HorizontalForce.h
        ParticleToy/forces/WallForce.cpp
        ParticleToy/forces/WallForce.h
        ParticleToy/forces/AngularSpringForce.cpp
        ParticleToy/forces/AngularSpringForce.h
        ParticleToy/SetUp.cpp
        ParticleToy/SetUp.h
        ParticleToy/forces/DampForce.cpp
        ParticleToy/forces/DampForce.h
        )

find_package (OpenGL REQUIRED)

link_directories(ParticleToy/lib/freeglut ParticleToy/lib/lib_win64)

include_directories(${OPENGL_INCLUDE_DIR} ParticleToy/include ParticleToy/include/Eigen/)

add_executable(simulation_1 ${SOURCE_FILES})

target_link_libraries(simulation_1 ${OPENGL_LIBRARIES} freeglut_static glu32 opengl32 winmm gdi32)

MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )