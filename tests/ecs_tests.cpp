#define BOOST_TEST_MODULE ECSTestsSuite
#include <boost/test/included/unit_test.hpp>
#include <entt.hpp>
#include <Components.hpp>

BOOST_AUTO_TEST_SUITE(ECSTesting)

BOOST_AUTO_TEST_CASE(ComponentInsertionTest)
{
    entt::registry registry;
    auto player_entity = registry.create();
    registry.emplace<PhysicsComponent>(player_entity, 128.0f, 256.0f, 0.0f, 0.0f, 500.f, 500.f, 1);
    
    registry.try_get<PhysicsComponent>(player_entity);

    BOOST_TEST(registry.try_get<PhysicsComponent>(player_entity) != nullptr, "The player entity has no Physics Component registered");
}

BOOST_AUTO_TEST_SUITE_END()