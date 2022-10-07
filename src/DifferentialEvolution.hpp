#ifndef DIFERENTIAL_EVOLUTION_HPP
#define DIFERENTIAL_EVOLUTION_HPP

#include <vector>

class DifferentialEvolution {

    private:
        int m_populationLen;

    public:
        DifferentialEvolution(float (*fitness_func)(std::vector<float>), int individual_len);
        std::vector<float> optimize();

        float (*m_fitness)(std::vector<float>);
        int getPopulationLen();
};

#endif /* DIFERENTIAL_EVOLUTION_HPP */
