#ifndef FUNCTIONAL_TEST_1_HPP
#define FUNCTIONAL_TEST_1_HPP

#define BOOST_TEST_MODULE FunctionalTest
#include "functional_test_config.hpp"

#include <vector>

#include "../src/DiferentialEvolution.hpp"

float fitness(std::vector<float>);

#endif /* FUNCTIONAL_TEST_1_HPP */