cmake_minimum_required (VERSION 3.20.0)
project (PocoSample)

# Project with Lib with dependency on Poco and GTest App with dependency on the Lib

# Lib
add_subdirectory (Lib)

# App
add_subdirectory (App)

# Tests
add_subdirectory (Test)