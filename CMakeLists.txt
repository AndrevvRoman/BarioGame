#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.0)

#how the project will be called
project (Bario)

set (CMAKE_CXX_STANDARD 11)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

#set source files
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


#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

if (WIN32)
	include_directories(${CMAKE_SOURCE_DIR}/external/win32/include)
	link_directories(${CMAKE_SOURCE_DIR}/external/win32/lib/cmake/SFML)
	link_directories(${CMAKE_SOURCE_DIR}/external/win32/lib)
	add_definitions(-DSFML_STATIC)
	add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
	target_link_libraries(Bario 
								sfml-window-s
								sfml-graphics-s
								sfml-system-s
								sfml-audio-s
								opengl32.lib freetype 
								winmm.lib 
								gdi32
								openal32.lib flac.lib vorbisenc.lib vorbisfile.lib vorbis.lib ogg.lib
								)
				
elseif (UNIX)
	find_package(SFML 2 REQUIRED audio graphics window system)
	if(SFML_FOUND)
  		include_directories(${SFML_INCLUDE_DIR})
  		target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
	endif()
endif ()


