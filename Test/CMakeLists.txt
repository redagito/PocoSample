project(PocoSampleTest)

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

# Download automatically
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()

include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES 
	gtest/1.10.0
	
	OPTIONS
	poco:shared=False
	
	BASIC_SETUP 
	CMAKE_TARGETS
	
	BUILD missing
)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties (${PROJECT_NAME} PROPERTIES 
	CXX_STANDARD 17
)

target_link_libraries (${PROJECT_NAME}
	PRIVATE CONAN_PKG::gtest
	PRIVATE PocoSampleLib
) 

target_include_directories(${PROJECT_NAME} 
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source
)