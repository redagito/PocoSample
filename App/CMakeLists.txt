project(PocoSampleApp)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cxx
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hxx
)

# Use folder structure
set_property (GLOBAL PROPERTY USE_FOLDERS ON)
set (CXX_STANDARD_REQUIRED ON)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties (${PROJECT_NAME} PROPERTIES 
	CXX_STANDARD 17
)

target_link_libraries (${PROJECT_NAME}
	PRIVATE PocoSampleLib
) 

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source
)