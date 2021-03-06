#pragma once
#include <map>
#include <unordered_map>

class RoyalEngineerAlt {

public:
    RoyalEngineerAlt(long amountOfItems);
    void populatePileOfBricks();
    long createBrickWall();
    void displayBricks();

private:
    std::unordered_map<int, std::string> pileOfBricks;
    std::map<int, std::string> brickWall;


};