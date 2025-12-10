set(SOURCES 
${CMAKE_CURRENT_SOURCE_DIR}/src/GameState.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/StateMachine.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/systems/InputSystem.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/systems/PhysicsSystem.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/systems/RenderSystem.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_include_directories(Core PUBLIC src src/components src/systems ../vendor/include/entt ../vendor/include/)
target_link_libraries(Core PUBLIC raylib)
target_link_directories(Core PUBLIC "../vendor/lib")

