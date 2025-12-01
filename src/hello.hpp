#pragma once
#include "dish.hpp"
#include <iostream>

class DishStack {
private:
    static const int MAX_SIZE = 100;
    Dish* dishes[MAX_SIZE];
    int top_index;

public:
    DishStack() : top_index(-1) {
        for (int i = 0; i < MAX_SIZE; i++) {
            dishes[i] = nullptr;
        }
    }

    ~DishStack() {
        clear();
    }

    void push(Dish dish) {
        if (top_index >= MAX_SIZE - 1) {
            std::cout << "Stack is full! Cannot push dish." << std::endl;
            return;
        }
        top_index++;
        dishes[top_index] = new Dish(dish.get_description());
    }

    Dish pop() {
        if (top_index < 0) {
            throw std::runtime_error("Stack is empty! Cannot pop.");
        }
        Dish* dish = dishes[top_index];
        Dish result = *dish;
        delete dish;
        dishes[top_index] = nullptr;
        top_index--;
        return result;
    }

    Dish peek() const {
        if (top_index < 0) {
            throw std::runtime_error("Stack is empty! Cannot peek.");
        }
        return *dishes[top_index];
    }

    int size() const {
        return top_index + 1;
    }

    void clear() {
        while (top_index >= 0) {
            delete dishes[top_index];
            dishes[top_index] = nullptr;
            top_index--;
        }
    }
};