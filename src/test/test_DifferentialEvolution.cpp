#include "test_DifferentialEvolution.hpp"


DifferentialEvolution* getDE() {
    DifferentialEvolution* de = new DifferentialEvolution(fitness_sum_all, 10);
    return de;
}


BOOST_AUTO_TEST_SUITE(unitTest_DifferentialEvolution)


BOOST_AUTO_TEST_CASE(test_m_function) {

    auto de = getDE();

    BOOST_CHECK_EQUAL(de->m_fitness, fitness_sum_all);

    std::vector<float> individual{1.5, 0.8, 23.0, 0.0, -5.0}; // Sum abs = 30.3

    float fitness_from_f = fitness_sum_all(individual);
    float fitness_from_de = de->m_fitness(individual);

    BOOST_CHECK_EQUAL(fitness_from_f, fitness_from_de);
    BOOST_CHECK_EQUAL(fitness_from_f, 30.3f);
    BOOST_CHECK_EQUAL(fitness_from_de, 30.3f);

}

BOOST_AUTO_TEST_CASE(test_members_are_stored) {

    auto de = getDE();

    BOOST_CHECK_EQUAL(de->m_fitness, fitness_sum_all);
    BOOST_CHECK_EQUAL(de->getPopulationLen(), 40);
    BOOST_CHECK_EQUAL(de->getIndividualLen(), 10);
    BOOST_CHECK_EQUAL(de->getNumberOfGenerations(), 100);

}

BOOST_AUTO_TEST_CASE(test_population_initialization) {

    auto de = getDE();

    de->initializePopulation();

    BOOST_CHECK_EQUAL(de->m_population[0].size(), de->m_individualLen);
    BOOST_CHECK_EQUAL(de->m_population.size(), de->m_populationLen);

    BOOST_CHECK_EQUAL(de->m_geneIdxs.size(), de->m_individualLen);
    BOOST_CHECK_EQUAL(de->m_individualIdxs.size(), de->m_populationLen);

}

BOOST_AUTO_TEST_CASE(test_get_individual_idx) {

    auto de = getDE();

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

BOOST_AUTO_TEST_CASE(test_individual_mating) {

    auto de = getDE();

    de->initializePopulation();

    std::vector<float> variatedIndividual;
    variatedIndividual.reserve(de->m_individualLen);
    de->mutateIndividual(0, &variatedIndividual);
    std::vector<float> mutatedIndividual = variatedIndividual;
    de->mateIndividual(0, &variatedIndividual);

    bool passed = true;

    for(uint i=0; i<variatedIndividual.size(); ++i) {
        if (variatedIndividual[i] != mutatedIndividual[i] && variatedIndividual[i] != de->m_population[0][i]) {
            passed = false;
            break;
        }
    }

    BOOST_CHECK_EQUAL(passed, true);

}

BOOST_AUTO_TEST_SUITE_END()
