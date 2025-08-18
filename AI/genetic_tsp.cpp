#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <climits>

const int POP_SIZE = 10;
const int MAX_GEN = 100;
const double MUT_RATE = 0.01;

std::vector<std::vector<int>> distMatrix = {
    {0, 248, 272, 245, 245, 120, 330, 115},
    {248, 0, 500, 612, 313, 368, 650, 345},
    {272, 500, 0, 267, 510, 157, 580, 320},
    {245, 612, 267, 0, 400, 350, 210, 170},
    {245, 313, 510, 400, 0, 370, 570, 220},
    {120, 368, 157, 350, 370, 0, 450, 280},
    {330, 650, 580, 210, 570, 450, 0, 250},
    {115, 345, 320, 170, 220, 280, 250, 0}};

int getDistance(const std::vector<int> &route)
{
    int totalDist = 0;
    for (size_t i = 0; i < route.size() - 1; ++i)
    {
        totalDist += distMatrix[route[i]][route[i + 1]];
    }
    totalDist += distMatrix[route.back()][route[0]];
    return totalDist;
}

std::vector<int> generateRandomRoute(int cityCount)
{
    std::vector<int> route(cityCount);
    for (int i = 0; i < cityCount; ++i)
    {
        route[i] = i;
    }
    std::random_shuffle(route.begin(), route.end());
    return route;
}

std::vector<std::vector<int>> initializePopulation(int popSize, int cityCount)
{
    std::vector<std::vector<int>> population(popSize);
    for (int i = 0; i < popSize; ++i)
    {
        population[i] = generateRandomRoute(cityCount);
    }
    return population;
}

std::vector<int> selectParent(const std::vector<std::vector<int>> &population)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, population.size() - 1);
    int idx1 = dis(gen);
    int idx2 = dis(gen);
    return getDistance(population[idx1]) < getDistance(population[idx2]) ? population[idx1] : population[idx2];
}

std::vector<int> performCrossover(const std::vector<int> &parent1, const std::vector<int> &parent2)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, parent1.size() - 1);
    int start = dis(gen);
    int end = dis(gen);
    if (start > end)
        std::swap(start, end);

    std::vector<int> offspring(parent1.size(), -1);
    for (int i = start; i <= end; ++i)
    {
        offspring[i] = parent1[i];
    }

    for (int i = 0; i < parent2.size(); ++i)
    {
        if (std::find(offspring.begin(), offspring.end(), parent2[i]) == offspring.end())
        {
            for (int j = 0; j < offspring.size(); ++j)
            {
                if (offspring[j] == -1)
                {
                    offspring[j] = parent2[i];
                    break;
                }
            }
        }
    }
    return offspring;
}

void applyMutation(std::vector<int> &route)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    for (size_t i = 0; i < route.size(); ++i)
    {
        if (dis(gen) < MUT_RATE)
        {
            std::uniform_int_distribution<> swapDis(0, route.size() - 1);
            int j = swapDis(gen);
            std::swap(route[i], route[j]);
        }
    }
}

int main()
{
    int cityCount = distMatrix.size();
    auto population = initializePopulation(POP_SIZE, cityCount);

    for (int gen = 0; gen < MAX_GEN; ++gen)
    {
        std::vector<std::vector<int>> newPop;
        for (int i = 0; i < POP_SIZE; ++i)
        {
            auto parent1 = selectParent(population);
            auto parent2 = selectParent(population);
            auto child = performCrossover(parent1, parent2);
            applyMutation(child);
            newPop.push_back(child);
        }
        population = newPop;

        auto bestRoute = *std::min_element(population.begin(), population.end(),
                                           [](const std::vector<int> &a, const std::vector<int> &b)
                                           {
                                               return getDistance(a) < getDistance(b);
                                           });

        std::cout << "Generation " << gen << ": Best Distance = " << getDistance(bestRoute) << std::endl;
    }

    auto bestRoute = *std::min_element(population.begin(), population.end(),
                                       [](const std::vector<int> &a, const std::vector<int> &b)
                                       {
                                           return getDistance(a) < getDistance(b);
                                       });

    std::cout << "Best Route: ";
    for (int city : bestRoute)
    {
        std::cout << city << " ";
    }
    std::cout << "\nBest Distance: " << getDistance(bestRoute) << std::endl;

    return 0;
}

// write a program that takes input of number of tasks and their execution times along with the number of availabe workers.now implement genetic algorithm to find a near-optimal assignment of tasks to workers. the program should print the task distribution per worker and the makespan(i.e, time when the last worker finishes).
// output format: worker 1: task 0 (4), task 3 (8).
//minimum makespan : 16