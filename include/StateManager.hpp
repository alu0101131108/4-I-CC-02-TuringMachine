#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__

#include <iostream>
#include <vector>
#include <string>

class StateManager {
  private:
    std::string initial;
    std::string current;
    std::vector<std::string> valid;
    std::vector<std::string> alphabet;

  public:
    StateManager();
    void setInitial(std::string state);
    std::string getInitial();
    void set(std::string state);
    std::string get();
    void addToAlphabet(std::string symbol);
    void addToValids(std::string symbol);
    bool isValid();
    void checkInAlphabet(std::string symbol);
    void logAlphabet();
    void clear();
  
};
#endif // __STATEMANAGER_H__