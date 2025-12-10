#define BOOST_TEST_MODULE DummyTestsSuite
#include <boost/test/included/unit_test.hpp>
#include <entt.hpp>

BOOST_AUTO_TEST_SUITE(ECS_Basic_Tests)

BOOST_AUTO_TEST_CASE(PlayerEntityCreation)
{
    entt::registry registry;
    auto player_entity = registry.create();
    int a = 1;

    BOOST_TEST(a==1, "Variable a is not equal to 1");
}

BOOST_AUTO_TEST_SUITE_END()