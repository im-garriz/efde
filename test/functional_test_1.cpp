#include "functional_test_1.hpp"

BOOST_AUTO_TEST_SUITE(functionalTest1)


BOOST_AUTO_TEST_CASE(test_trivial_all_0_problem_converges) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    std::vector<float> result;
    float result_fitness;

    result = de->optimize();

    for (auto it=result.begin(); it!=result.end(); ++it)
        std::cout << *it << ',';

    result_fitness = fitness_sum_all(result);

    std::cout << std::endl << result_fitness << std::endl;
    
    BOOST_CHECK_CLOSE(result_fitness, 0.f, 0.01f);
  
    //for (auto it=result.begin(); it!=result.end(); it++)
    //    BOOST_CHECK_CLOSE(*it, 0.f, 0.001f);
}

BOOST_AUTO_TEST_SUITE_END()
