#include "RoyalEngineerAlgorithm.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

void RoyalEngineerAlgorithm::populatePileOfBricks()
{
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
}


void RoyalEngineerAlgorithm::displayBricks()
{
    std::cout << "ID  Name" << std::endl;

    for(const auto& brick : brickWall)
    {
        std::cout << brick.first << "  " << brick.second << std::endl;
    }
}

long RoyalEngineerAlgorithm::createBrickWall()
{
    // Start measuring time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Arbitrarily choose starting brick
    std::srand(std::time(nullptr));
    // Keep iterator of first element in place for posterior search
    const auto& firstBrickIterator = pileOfBricks.find(rand() % pileOfBricks.size());
    const auto& startingBrick = std::make_pair(firstBrickIterator->first, firstBrickIterator->second);
    auto currentBrick = firstBrickIterator;

    // Store first element
    brickWall.emplace_back(startingBrick);

    // This determines whether the search is going for the eastern or western bricks, starting eastern as per step 5
    bool eastBound = true;

    // Store all elements in order
    while(true)
    {
        // Increment or decrement iterator
        if(eastBound)
            currentBrick = pileOfBricks.find(currentBrick->first + 1);
        else
            currentBrick = pileOfBricks.find(currentBrick->first - 1);

        // Not found
        if(currentBrick == std::end(pileOfBricks))
        {
            if(eastBound)
            {
                currentBrick = firstBrickIterator; // Return to middle point
                eastBound = false; // Switch to westbound
                continue;
            }
            else
                break;
        }

        // Place brick in its position
        if(eastBound)
            brickWall.emplace_back(std::make_pair(currentBrick->first, currentBrick->second));
        else
            brickWall.emplace_front(std::make_pair(currentBrick->first, currentBrick->second));
    }
    // Display time difference - https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

RoyalEngineerAlgorithm::RoyalEngineerAlgorithm(long amountOfItems)
{
    // Comment out for manual input. This auto populates the data for benchmarking
    for(unsigned long i = 0; i <= amountOfItems; i++)
        this->pileOfBricks.emplace(i, "brick number " + std::to_string(i));
}
