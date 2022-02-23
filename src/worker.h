#pragma once

// robot class, the robot knows where it is and what direction it is facing.
// The calls are made to the robot to place/rotate and move it.

#include <vector>
#include <string>

namespace ShapeShifterTest{

class Worker{
  public:
    Worker();
    virtual ~Worker(){}


    int factors(int n);

    void work(const std::string& filename);
    
  private:

};

}
