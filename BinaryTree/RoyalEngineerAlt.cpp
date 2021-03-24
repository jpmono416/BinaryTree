#include <iostream>
#include "RoyalEngineerAlt.h"

void RoyalEngineerAlt::populatePileOfBricks()
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

/**
 * Alternative version of the algorithm which I expect to perform better than the original
 * taking into account the data structures used and their characteristics.
 */
void RoyalEngineerAlt::createBrickWall()
{
    for(const auto& brick : pileOfBricks)
    {
        brickWall[brick.first] = brick.second;
    }
}


void RoyalEngineerAlt::displayBricks()
{
    std::cout << "ID  Name" << std::endl;

    for(const auto& brick : brickWall)
    {
        std::cout << brick.first << "  " << brick.second << std::endl;
    }
}
