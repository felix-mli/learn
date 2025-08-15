aux_source_directory(./src SOURCES)

add_executable(oop_demo 
    main.c
    ${SOURCES}
)

target_include_directories(oop_demo
    PUBLIC
    ${CMAKE_SOURCE_DIR}/tools/base/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(oop_demo
    base
)