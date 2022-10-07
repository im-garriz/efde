#include "test_DifferentialEvolution.hpp"


BOOST_AUTO_TEST_SUITE(unitTest_DifferentialEvolution)

BOOST_AUTO_TEST_CASE(test_members_are_stored) {

    //float (*pointer_to_fitness)(std::vector<float>) = fitness_sum_all;

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    BOOST_CHECK_EQUAL(de->m_fitness, fitness_sum_all);
    BOOST_CHECK_EQUAL(de->getPopulationLen(), 10);

    //delete de;
}

BOOST_AUTO_TEST_SUITE_END()
