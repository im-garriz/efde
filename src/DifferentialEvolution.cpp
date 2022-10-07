#include "DifferentialEvolution.hpp"

DifferentialEvolution::DifferentialEvolution(float (*fitness_func)(std::vector<float>), int individual_len) {
    m_fitness = fitness_func;
    m_populationLen = individual_len;
}

std::vector<float> DifferentialEvolution::optimize() {
    std::vector<float> result = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};
    return result;
}

int DifferentialEvolution::getPopulationLen() {
    return m_populationLen;
}