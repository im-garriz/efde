#include "DifferentialEvolution.hpp"

DifferentialEvolution::DifferentialEvolution(float (*fitness_func)(std::vector<float>), int individual_len) {
    m_fitness = fitness_func;

    m_populationLen = 80000;
    m_individualLen = individual_len;
    m_nOfGenerations = 5000;

    m_F = 0.5;
    m_CR = 0.5;

    Random::seed( 42 );
}

std::vector<float> DifferentialEvolution::optimize() {

    initializePopulation();

    for(int i=0; i<m_nOfGenerations; ++i) {
        performGeneration();
        std::cout << "Gen " << i+1 << " finished\n";
    }

    int bestIndIdx = 0;
    float bestFitness = m_fitness(m_population[bestIndIdx]);
    for(int i=1; i<m_populationLen; ++i) {
        float currentFitness = m_fitness(m_population[i]);

        if (currentFitness < bestFitness) {
            bestFitness = currentFitness;
            bestIndIdx = i;
        }
            
    }

    return m_population[bestIndIdx];
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
    for(int i=0; i<m_individualLen; ++i) {
        performGenerationOnIndividual(i);
    }

    //performGenerationOnIndividual(0);
}

void DifferentialEvolution::performGenerationOnIndividual(int individualIdx) {

    std::vector<float> variatedIndividual;
    variatedIndividual.reserve(m_individualLen);

    /*std::cout << "\nInd\n";
    auto ind = m_population[individualIdx];
    for (auto it=ind.begin(); it!=ind.end(); ++it)
        std::cout << *it << ',';*/

    mutateIndividual(individualIdx, &variatedIndividual);

    mateIndividual(individualIdx, &variatedIndividual);

    /*std::cout << "\nMated\n";
    for (auto it=variatedIndividual.begin(); it!=variatedIndividual.end(); ++it)
        std::cout << *it << ',';*/


    selectDescendant(individualIdx, &variatedIndividual);
    
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

void DifferentialEvolution::mateIndividual(int individualIdx, std::vector<float>* mutated) {

    int alpha = *(Random::get(m_geneIdxs.begin(), m_geneIdxs.end()));

    for (int i=0; i<m_individualLen; i++) {
        float beta = Random::get(1.f, 0.f);

        //if not (beta > m_CR || i == alpha)
        if (beta <= m_CR && i != alpha)
            (*mutated)[i] = m_population[individualIdx][i];
    }
}

void DifferentialEvolution::selectDescendant(int individualIdx, std::vector<float>* variatedIndividual) {

    float variatedIndividualsFitness = m_fitness(*variatedIndividual);
    float currentIndividualsFitness = m_fitness(m_population[individualIdx]);

    if (variatedIndividualsFitness < currentIndividualsFitness) // MINIMIZATION
        // MUTEX
        m_population[individualIdx] = *variatedIndividual;
}