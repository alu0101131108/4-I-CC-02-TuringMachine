#ifndef __TURINGMACHINE_H__
#define __TURINGMACHINE_H__

#include "./StateManager.hpp"
#include "./Band.hpp"
#include "./Transition.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


class TuringMachine {
  private:
    StateManager states;
    Band band;
    std::vector<Transition> transitions;
    std::string whiteSymbol;

  public:
    TuringMachine();
    void loadFromFile(std::string filename);
    void logInfo();
    void logBandContent();
    void logTransitions();
    void addTransition(Transition transition);
    bool validateString(std::string string);
    bool transit();
    void applyTransition(Transition transition);

};
#endif // __TURINGMACHINE_H__