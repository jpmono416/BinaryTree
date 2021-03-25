#pragma once
#include <unordered_map>
#include <list>

class RoyalEngineerAlgorithm {

public:
    RoyalEngineerAlgorithm(long amountOfItems);
    void populatePileOfBricks();
    long createBrickWall();
    void displayBricks();

private:
    std::list<std::pair<int, std::string>> brickWall;
    std::unordered_map<int, std::string> pileOfBricks;
};
