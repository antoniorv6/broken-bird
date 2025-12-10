add_executable(dummy_tests dummy_tests.cpp)
add_executable(ecs_tests ecs_tests.cpp)

message(STATUS "${boost_SOURCE_DIR}")

target_include_directories(ecs_tests PRIVATE ${boost_SOURCE_DIR})
target_include_directories(dummy_tests PRIVATE ${boost_SOURCE_DIR})

target_link_libraries(ecs_tests PRIVATE Core)

target_include_directories(dummy_tests PRIVATE ../vendor/include/entt)
target_include_directories(ecs_tests PRIVATE ../vendor/include/entt)

target_compile_definitions(dummy_tests PRIVATE
    BOOST_TEST_DYN_LINK
)

target_compile_definitions(ecs_tests PRIVATE
    BOOST_TEST_DYN_LINK
)

add_test(NAME DummyTests COMMAND dummy_tests)
add_test(NAME ECSTests COMMAND ecs_tests)
