#ifndef DIFERENTIAL_EVOLUTION_HPP
#define DIFERENTIAL_EVOLUTION_HPP

#include <vector>
#include "utils/random.hpp"
#include <iostream> // DEL
#include<thread>

#define RANDOM_THREAD_LOCAL

#ifdef RANDOM_LOCAL
auto Random = effolkronium::random_local{ };
#endif

#ifdef RANDOM_STATIC
using Random = effolkronium::random_static;
#endif

#ifdef RANDOM_THREAD_LOCAL
using Random = effolkronium::random_thread_local;
#endif

#ifndef RANDOM_LOCAL
using Random_t = Random;
#define DOT ::
#else
using Random_t = effolkronium::random_local;
#define DOT .
#endif


class DifferentialEvolution {

    public:
    //private:
        int m_populationLen;
        int m_individualLen;
        int m_nOfGenerations;
        float m_F;
        float m_CR;

        std::vector<std::vector<float>> m_population;
        std::vector<int> m_individualIdxs;
        std::vector<float> m_fitnessValues;
        std::vector<int> m_geneIdxs;

    public:
        DifferentialEvolution(float (*fitness_func)(std::vector<float>), int individual_len);
        
        float (*m_fitness)(std::vector<float>);
        int getPopulationLen();
        int getIndividualLen();
        int getNumberOfGenerations();

        // DE methods
        std::vector<float> optimize();
        void initializePopulation();
        void performGeneration();
        void performGenerationOnIndividual(int individualIdx);
        int getRandomIndividualIdx(std::vector<int>* unselectable_individuals);
        void mutateIndividual(int individualIdx, std::vector<float>* mutated);
        void mateIndividual(int individualIdx, std::vector<float>* mutated);
        void selectDescendant(int individualIdx, std::vector<float>* variatedIndividual);
        bool allThreadsFinished();

};

#endif /* DIFERENTIAL_EVOLUTION_HPP */
