#include <iostream>

#include "src/hello.hpp"

int main() {
  DishStack stack;
  Dish one_dish = Dish("A dish with one fish pattern on it");
  Dish two_dish = Dish("A dish with two fish patterns on it");
  Dish red_dish = Dish("A dish with a red fish pattern on it");
  Dish blue_dish = Dish("A dish with a blue fish pattern on it");

  int stack_size = stack.size();
  std::cout << "Initial stack size: " << stack_size << std::endl;

  stack.push(one_dish);
  stack.push(two_dish);
  stack.push(red_dish);
  stack.push(blue_dish);

  int size_after_pushes = stack.size();
  std::cout << "Size after pushes: " << size_after_pushes << std::endl;

  Dish peeked_dish = stack.peek();
  std::cout << "Peeked dish: " << peeked_dish.get_description() << std::endl;

  Dish popped_dish = stack.pop();
  std::cout << "Popped dish: " << popped_dish.get_description() << std::endl;

  Dish another_popped_dish = stack.pop();
  std::cout << "Another popped dish: " << another_popped_dish.get_description() << std::endl;

  int final_size = stack.size();
  std::cout << "Final size: " << final_size << std::endl;

  std::cout << "Size before clear: " << stack.size() << std::endl;
  stack.clear();
  std::cout << "Size after clear: " << stack.size() << std::endl;
}
