#include "test_DifferentialEvolution.hpp"


BOOST_AUTO_TEST_SUITE(unitTest_DifferentialEvolution)

BOOST_AUTO_TEST_CASE(test_members_are_stored) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    BOOST_CHECK_EQUAL(de->m_fitness, fitness_sum_all);
    BOOST_CHECK_EQUAL(de->getPopulationLen(), 40);
    BOOST_CHECK_EQUAL(de->getIndividualLen(), 10);
    BOOST_CHECK_EQUAL(de->getNumberOfGenerations(), 100);

}

BOOST_AUTO_TEST_CASE(test_population_initialization) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    de->initializePopulation();

    BOOST_CHECK_EQUAL(de->m_population[0].size(), de->m_individualLen);
    BOOST_CHECK_EQUAL(de->m_population.size(), de->m_populationLen);

    BOOST_CHECK_EQUAL(de->m_geneIdxs.size(), de->m_individualLen);
    BOOST_CHECK_EQUAL(de->m_individualIdxs.size(), de->m_populationLen);

}

BOOST_AUTO_TEST_CASE(test_get_individual_idx) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    de->initializePopulation();

    std::vector<int> unselectableIndividuals{0};
    int n1 = de->getRandomIndividualIdx(&unselectableIndividuals); // 25
    auto p = std::find(unselectableIndividuals.begin(), unselectableIndividuals.end(), n1);
    BOOST_CHECK_EQUAL(*p, n1);

    int n2 = de->getRandomIndividualIdx(&unselectableIndividuals); // 34
    p = std::find(unselectableIndividuals.begin(), unselectableIndividuals.end(), n2);
    BOOST_CHECK_EQUAL(*p, n2);

    BOOST_CHECK_EQUAL(n1==n2, false);
    BOOST_CHECK_EQUAL(n1==0, false);
    BOOST_CHECK_EQUAL(n1==0, false);

    std::vector<int> expectedUnselectableIndividuals{0, n1, n2};

    BOOST_CHECK_EQUAL_COLLECTIONS(unselectableIndividuals.begin(), unselectableIndividuals.end(), 
                                  expectedUnselectableIndividuals.begin(), expectedUnselectableIndividuals.end());

}

BOOST_AUTO_TEST_CASE(test_perform_generation_on_individual) {

    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);

    de->initializePopulation();
    de->performGenerationOnIndividual(0);

    BOOST_CHECK_EQUAL(de->m_population[0].size(), de->m_individualLen);

}

BOOST_AUTO_TEST_SUITE_END()
