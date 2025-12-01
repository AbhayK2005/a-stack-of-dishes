#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("DishStack initial size is zero") {
    DishStack stack;
    REQUIRE(stack.size() == 0);
}

TEST_CASE("DishStack push increases size") {
    DishStack stack;
    Dish dish("Test dish");

    stack.push(dish);
    REQUIRE(stack.size() == 1);
}

TEST_CASE("DishStack peek returns top element without removing it") {
    DishStack stack;
    Dish dish1("First dish");
    Dish dish2("Second dish");

    stack.push(dish1);
    stack.push(dish2);

    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "Second dish");
    REQUIRE(stack.size() == 2);  // Size should not change
}

TEST_CASE("DishStack pop removes and returns top element") {
    DishStack stack;
    Dish dish1("First dish");
    Dish dish2("Second dish");

    stack.push(dish1);
    stack.push(dish2);

    Dish popped = stack.pop();
    REQUIRE(popped.get_description() == "Second dish");
    REQUIRE(stack.size() == 1);
}

TEST_CASE("DishStack follows LIFO order") {
    DishStack stack;
    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");
    Dish blue_dish("A dish with a blue fish pattern on it");

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    REQUIRE(stack.size() == 4);

    Dish popped1 = stack.pop();
    REQUIRE(popped1.get_description() == "A dish with a blue fish pattern on it");

    Dish popped2 = stack.pop();
    REQUIRE(popped2.get_description() == "A dish with a red fish pattern on it");

    REQUIRE(stack.size() == 2);
}

TEST_CASE("DishStack clear removes all elements") {
    DishStack stack;
    Dish dish1("Dish 1");
    Dish dish2("Dish 2");
    Dish dish3("Dish 3");

    stack.push(dish1);
    stack.push(dish2);
    stack.push(dish3);

    REQUIRE(stack.size() == 3);

    stack.clear();

    REQUIRE(stack.size() == 0);
}

TEST_CASE("DishStack can be used after clear") {
    DishStack stack;
    Dish dish1("Dish 1");
    Dish dish2("Dish 2");

    stack.push(dish1);
    stack.clear();
    stack.push(dish2);

    REQUIRE(stack.size() == 1);
    REQUIRE(stack.peek().get_description() == "Dish 2");
}

TEST_CASE("DishStack throws error when popping empty stack") {
    DishStack stack;

    REQUIRE_THROWS_AS(stack.pop(), std::runtime_error);
}

TEST_CASE("DishStack throws error when peeking empty stack") {
    DishStack stack;

    REQUIRE_THROWS_AS(stack.peek(), std::runtime_error);
}