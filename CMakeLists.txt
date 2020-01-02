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

if (WIN32)
	include_directories(external/win32/include)
	link_directories(external/win32/lib/cmake/SFML)
	link_directories(external/win32/lib)
elseif (UNIX)
	include_directories(external/linux64/include)
	link_directories(external/linux64/lib/cmake/SFML)
	link_directories(external/linux64/lib)
else ()
	message (FATAL_ERROR "Неизвестная система")
endif ()


#add_definitions(-DSFML_STATIC)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#target_link_libraries(Bario sfml-graphics-s sfml-window-s sfml-system-s opengl32 freetype winmm gdi32)
target_link_libraries(Bario sfml-graphics sfml-window sfml-system sfml-audio)