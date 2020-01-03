#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.0)

#how the project will be called
project (Bario)

set (CMAKE_CXX_STANDARD 11)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

#set source files

set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
#configure_file(
# "${PROJECT_SOURCE_DIR}/config.h.in"
#  "${PROJECT_BINARY_DIR}/config.h"
#  )
include_directories("${PROJECT_BINARY_DIR}")

set(SOURCES 
	src/BaseUnit.cpp                                                                                                            
	src/Buzzer.cpp                                                                                                              
	src/FactoryBonus.cpp                                                                                                        
	src/FactoryEnemy.cpp                                                                                                        
	src/Game.cpp                                                                                                                
	src/GUI.cpp                                                                                                                 
	src/main.cpp                                                                                                                
	src/Map.cpp                                                                                                                 
	src/MapGenerator.cpp                                                                                                        
	src/Mushroom.cpp                                                                                                                                                                                                                   
	src/Player.cpp                                                                                                              
	src/Sound.cpp                                                                                                               
	src/Turtle.cpp
)
set(HEADERS 
	src/BaseUnit.h                                                                                                              
	src/Buzzer.h
	src/FactoryBonus.h                                                                                                          
	src/FactoryEnemy.h                                                                                                          
	src/Game.h                                                                                                                  
	src/GUI.h                                                                                                                   
	src/IBonus.h                                                                                                                
	src/IBoss.h                                                                                                                 
	src/IEnemy.h                                                                                                                
	src/IMap.h                                                                                                                  
	src/Map.h                                                                                                                   
	src/MapGenerator.h                                                                                                          
	src/Mushroom.h                                                                                                              
	src/Player.h                                                                                                                
	src/Sound.h                                                                                                                 
	src/Turtle.h 
)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

if (WIN32)
	include_directories(external/win32/include)
	link_directories(external/win32/lib/cmake/SFML)
	link_directories(external/win32/lib)
elseif (UNIX)
	find_package(SFML 2 REQUIRED audio graphics window system)
	if(SFML_FOUND)
  		add_definitions(-DSFML_STATIC)
  		include_directories(${SFML_INCLUDE_DIR})
  		target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
	endif()
endif ()


INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/res DESTINATION ${EXECUTABLE_OUTPUT_PATH})

#install(TARGETS ${EXECUTABLE_NAME} DESTINATION build)

#include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
#set(CPACK_PACKAGE_VERSION_MAJOR "${Bario_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${Bario_VERSION_MINOR}")
#include(CPack)