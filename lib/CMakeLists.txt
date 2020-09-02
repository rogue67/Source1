#Add library 
add_library (lib resekostnad.cpp)

target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
