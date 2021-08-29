cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(Shield)


#Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()


# Setup Geant4 include directories and compile definitions
include(${Geant4_USE_FILE})


# Locate sources and headers for this project
include_directories(${PROJECT_SOURCE_DIR}/include
        ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)


# Add the executable, and link it to the Geant4 libraries
add_executable(Shield Shield.cpp ${sources} ${headers})
target_link_libraries(Shield ${Geant4_LIBRARIES} )


set(Shield_SCRIPTS
  SingleLayerGeometry.txt
  DoubleLayerGeometry.txt
  TripleLayerGeometry.txt
  Geometry.txt
  source.mac
  vis.mac
  scorer.mac
  run1.mac)
  
  
foreach(_script ${Shield_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY)
endforeach()
