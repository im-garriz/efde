#include "fitnessFunctions.hpp"

float fitness_sum_all(std::vector<float> individual) {

    float sum = 0;

    for (auto it = individual.begin(); it != individual.end(); ++it)
        sum += *it;

    return sum;
}