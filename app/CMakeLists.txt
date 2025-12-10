set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameOverState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MainGameState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(flappybirddca)

# add_custom_command(TARGET flappybirddca POST_BUILD 
#                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} $<TARGET_FILE_DIR:flappybirddca>/assets)

# install(TARGETS flappybirddca RUNTIME DESTINATION bin)
# install(DIRECTORY ${ASSETS_DIR} DESTINATION bin)

target_sources(flappybirddca PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_include_directories(flappybirddca PRIVATE src)

target_link_libraries(flappybirddca Core)