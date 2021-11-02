#ifndef __TRANSITION_H__
#define __TRANSITION_H__

#include <iostream>
#include <vector>
#include <string>

class Transition {
  private:
    std::string start;
    std::string input;
    std::string end;
    std::string output;
    std::string move;

  public:
    Transition();
    Transition(std::string start_, std::string input_, 
        std::string end_, std::string output_, std::string move_);

    std::string getStart();
    std::string getInput();
    std::string getEnd();
    std::string getOutput();
    std::string getMove();
    void log();

};

#endif // __TRANSITION_H__