#include <map>
#include <unordered_map>

class RoyalEngineerAlt {

public:
    void populatePileOfBricks();
    void createBrickWall();
    void displayBricks();

private:
    std::unordered_map<int, std::string> pileOfBricks;
    std::map<int, std::string> brickWall;


};