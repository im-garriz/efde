#include "functional_test_1.hpp"


float fitness(std::vector<float> individual)
{
    float sum = 0;

    for (auto it = individual.begin(); it != individual.end(); ++it)
        sum += *it;

    return sum;
}


BOOST_AUTO_TEST_SUITE(functionalTest1)

BOOST_AUTO_TEST_CASE(test_fitness_function) {

    //float individual[] = {1, 2, 3, 4};
    std::vector<float> individual = {1, 2, 3, 4};

    BOOST_CHECK_EQUAL(fitness(individual), 10.);
}

BOOST_AUTO_TEST_CASE(test_trivial_all_0_problem_converges) {

    
    float (*pointer_to_fitness)(std::vector<float>) = fitness;
    de = DiferentialEvolution(pointer_to_fitness, 10);

    std::vector<float> result;
    float result_fitness;

    result = de.optimize();
    result_fitness = fitness(result);
    
    BOOST_CHECK_CLOSE(result_fitness, 0f, 0.01f);
  
    for (auto it=result.begin(); it!=result.end(); it++)
        BOOST_CHECK_CLOSE(*it, 0f, 0.001f);
}

BOOST_AUTO_TEST_SUITE_END()
