#include "functional_test_1.hpp"

BOOST_AUTO_TEST_SUITE(functionalTest1)


BOOST_AUTO_TEST_CASE(test_trivial_all_0_problem_converges) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 50);

    std::vector<float> result;
    float result_fitness;

    auto start = std::chrono::high_resolution_clock::now();
    result = de->optimize();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "\nElapsed time: " << duration.count() << " seconds\n";

    for (auto it=result.begin(); it!=result.end(); ++it)
        std::cout << *it << ',';

    result_fitness = fitness_sum_all(result);

    std::cout << std::endl << result_fitness << std::endl;
    
    BOOST_CHECK_SMALL(result_fitness, 0.0001f);
  
    for (auto it=result.begin(); it!=result.end(); it++)
        BOOST_CHECK_SMALL(*it, 0.0001f);
}

BOOST_AUTO_TEST_SUITE_END()
