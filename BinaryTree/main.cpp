#include <iostream>
#include "RoyalEngineerAlgorithm.h"
#include "RoyalEngineerAlt.h"
#include <chrono>

int main()
{
    /*
    RoyalEngineerAlgorithm example;

    example.populatePileOfBricks();
    example.createBrickWall();
    example.displayBricks();

    std::cout << "Switching to alternative" << std::endl;

    RoyalEngineerAlt example2;
    example2.populatePileOfBricks();
    example2.createBrickWall();
    example2.displayBricks();
    */
    long avgTimeAlgorithm1, maxTimeAlgorithm1;
    long avgTimeAlgorithm2, maxTimeAlgorithm2;
    const unsigned int amountOfIterations = 5000;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i <= amountOfIterations; i++)
    {
        RoyalEngineerAlgorithm example(1500);
        const auto timeTaken = example.createBrickWall();
        if(timeTaken > maxTimeAlgorithm1)
            maxTimeAlgorithm1 = timeTaken;
        avgTimeAlgorithm1 += timeTaken;

        RoyalEngineerAlgorithm example2(1500);
        const auto timeTaken2 = example2.createBrickWall();
        if(timeTaken2 > maxTimeAlgorithm2)
            maxTimeAlgorithm2 = timeTaken2;
        avgTimeAlgorithm2 += timeTaken2;

    }

    // Calculate averages
    avgTimeAlgorithm1 = avgTimeAlgorithm1 / amountOfIterations;
    avgTimeAlgorithm2 = avgTimeAlgorithm2 / amountOfIterations;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Alg 1 max/avg time: " << maxTimeAlgorithm1 << '/' << avgTimeAlgorithm1 << std::endl;
    std::cout << "Alg 2 max/avg time: " << maxTimeAlgorithm2 << '/' << avgTimeAlgorithm2 << std::endl;
}
