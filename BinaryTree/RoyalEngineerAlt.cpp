#include <iostream>
#include <chrono>
#include "RoyalEngineerAlt.h"
#include <string>

void RoyalEngineerAlt::populatePileOfBricks()
{

    for(unsigned int i = 0; i <= 10; i++)
    {
        this->pileOfBricks.emplace(i, "brick number" + std::to_string(i));
    }
    /*
     * Uncomment for manual input
     std::cout << "Please enter the unordered brick's information: id and then name";

    while(true)
    {
        std::cout << std::endl;
        int brickId;
        std::string name;

        std::cin >> brickId;
        std::cin >> name;

        this->pileOfBricks.emplace(brickId, name);

        // Again?
        std::cout << "Stop? y/n";
        std::string answer;
        std::cin >> answer;
        if(answer == "y")
            break;
    }
     */
}

/**
 * Alternative version of the algorithm which I expect to perform better than the original
 * taking into account the data structures used and their characteristics.
 */
long RoyalEngineerAlt::createBrickWall()
{
    // Start measuring time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for(const auto& brick : pileOfBricks)
    {
        brickWall[brick.first] = brick.second;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}


void RoyalEngineerAlt::displayBricks()
{


    std::cout << "ID  Name" << std::endl;

    for(const auto& brick : brickWall)
    {
        std::cout << brick.first << "  " << brick.second << std::endl;
    }
}

RoyalEngineerAlt::RoyalEngineerAlt(long amountOfItems)
{
    // Comment out for manual input. This auto populates the data for benchmarking
    for(unsigned long i = 0; i <= amountOfItems; i++)
        this->pileOfBricks.emplace(i, "brick number " + std::to_string(i));
}
