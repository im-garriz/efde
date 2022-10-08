#include "DifferentialEvolution.hpp"

DifferentialEvolution::DifferentialEvolution(float (*fitness_func)(std::vector<float>), int individual_len) {
    m_fitness = fitness_func;

    m_populationLen = 40;
    m_individualLen = individual_len;
    m_nOfGenerations = 100;

    m_F = 0.5;

    Random::seed( 42 );
}

std::vector<float> DifferentialEvolution::optimize() {

    initializePopulation();

    for(int i=0; i<m_nOfGenerations; ++i) {
        performGeneration();
    }

    return std::vector<float> {0., 0., 0., 0., 0., 0., 0. ,0., 0., 0.};
}

int DifferentialEvolution::getPopulationLen() {
    return m_populationLen;
}

int DifferentialEvolution::getIndividualLen() {
    return m_individualLen;
}

int DifferentialEvolution::getNumberOfGenerations() {
    return m_nOfGenerations;
}

void DifferentialEvolution::initializePopulation() {

    std::vector<std::vector<float>> population(m_populationLen, std::vector<float> (m_individualLen) );
    m_population = population;

    m_individualIdxs.reserve(m_populationLen);
    m_geneIdxs.reserve(m_individualLen);

    int gene_idx = 0;
    int ind_idx = 0;
    for (auto it=m_population.begin(); it!=m_population.end(); ++it) {
        
        for (auto itv=it->begin(); itv!=it->end(); ++itv) {
            *itv = Random::get(1.0f, 0.0f) * 10.f;

            // Fill individual idx with first individual
            if (it == m_population.begin()) {
                m_geneIdxs.push_back(gene_idx);
                ++gene_idx;
            }
        }

        m_individualIdxs.push_back(ind_idx);
        ind_idx++;
    }

    /*std::cout << "\nFirst ind\n";
    for (auto it=m_population[0].begin(); it!=m_population[0].end(); ++it)
        std::cout << *it << ',';

    std::cout << "\nm_individualIdxs\n";
    for (auto it=m_geneIdxs.begin(); it!=m_geneIdxs.end(); ++it)
        std::cout << *it << ',';*/

    //void* void_ptr = &m_population;

    
}

void DifferentialEvolution::performGeneration() {

    // Multithreading
    /*for(int i=0; i<m_individualLen; ++i) {
        performGenerationOnIndividual(i, &m_population);
    }*/

    performGenerationOnIndividual(0);
}

void DifferentialEvolution::performGenerationOnIndividual(int individualIdx) {

    //std::vector<std::vector<float>> population = *population_ptr;

    /*std::cout << "\nFirst ind\n";
    for (auto it=(*population_ptr)[0].begin(); it!=(*population_ptr)[0].end(); ++it)
        std::cout << *it << ',';

    
    std::cout << "\nFirst ind2\n";
    for (auto it=m_population[0].begin(); it!=m_population[0].end(); ++it)
        std::cout << *it << ',';*/

    std::vector<float> mutated;
    mutated.reserve(m_individualLen);
    mutateIndividual(individualIdx, &mutated);

    // LOGGING
    std::cout << "\nFirst ind2\n";
    for (auto it=mutated.begin(); it!=mutated.end(); ++it)
        std::cout << *it << ',';

}

int DifferentialEvolution::getRandomIndividualIdx(std::vector<int>* unselectableIndividuals) {
    auto n_it = Random::get(m_individualIdxs.begin(), m_individualIdxs.end());
    while(std::find((*unselectableIndividuals).begin(), (*unselectableIndividuals).end(), *n_it) != (*unselectableIndividuals).end()) {
        n_it = Random::get(m_individualIdxs.begin(), m_individualIdxs.end());
    }
    (*unselectableIndividuals).push_back(*n_it);

    return *n_it;
}

void DifferentialEvolution::mutateIndividual(int individualIdx, std::vector<float>* mutated) {

    std::vector<int> unselectableIndividuals;
    unselectableIndividuals.reserve(4);
    unselectableIndividuals.push_back(individualIdx);

    int p = getRandomIndividualIdx(&unselectableIndividuals);
    int q = getRandomIndividualIdx(&unselectableIndividuals);
    int r = getRandomIndividualIdx(&unselectableIndividuals);

    for (int i=0; i<m_individualLen; i++)
        mutated->push_back(m_population[r][i] + m_F * (m_population[p][i] - m_population[q][i]));
}