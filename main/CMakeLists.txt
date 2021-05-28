#set(COMPONENT_SRCS "main.cpp")
#set(COMPONENT_ADD_INCLUDEDIRS ".")

#register_component()

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/main/*.*)
idf_component_register(SRCS "main.cpp" ${app_sources} )