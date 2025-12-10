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


set(CPACK_PACKAGE_NAME "FlappyBirdDCA")
set(CPACK_PACKAGE_VENDOR "antoniorv6")
set(CPACK_PACKAGE_VERSION "1.0.0")

if(WIN32)
    install(TARGETS flappybirddca RUNTIME DESTINATION .)
    install(DIRECTORY ${PROJECT_SOURCE_DIR}/assets DESTINATION assets)
    set(CPACK_GENERATOR "NSIS")
    
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "FlappyBirdDCA")
    set(CPACK_NSIS_DISPLAY_NAME "FlappyBirdDCA")
    set(CPACK_NSIS_PACKAGE_NAME "FlappyBirdDCA")
    
    set(CPACK_NSIS_INSTALLED_ICON_NAME "flappybirddca.exe")
    set(CPACK_NSIS_MENU_LINKS "flappybirddca.exe" "FlappyBirdDCA")

endif()

if(UNIX AND NOT APPLE)
    install(TARGETS flappybirddca DESTINATION bin)
    install(DIRECTORY ${PROJECT_SOURCE_DIR}/assets 
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/assets)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Antonio Rios Vila")
    set(CPACK_DEBIAN_PACKAGE_SECTION "games")
    set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libraylib (>=5.0)")
endif()

include(CPack)