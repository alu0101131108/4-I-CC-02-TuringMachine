#include "./../include/StateManager.hpp"
StateManager::StateManager() 
{}

void StateManager::setInitial(std::string state) 
{
  initial = state;
  current = initial;
}

std::string StateManager::getInitial() 
{
  return initial;
}

void StateManager::set(std::string state) 
{
  current = state;
}

std::string StateManager::get() 
{
  return current;
}

void StateManager::addToAlphabet(std::string state) 
{
  alphabet.push_back(state);
}

void StateManager::addToValids(std::string symbol) 
{
  valid.push_back(symbol);
}

bool StateManager::isValid() 
{
  bool isValid = false;
  for (int i = 0; i < valid.size(); i++) {
    if (valid[i] == current)
      isValid = true;
  }
  return isValid;
}

void StateManager::checkInAlphabet(std::string state) 
{
  bool belongs = false;
  for (int i = 0; i < alphabet.size(); i++) {
    if (state == alphabet[i])
      belongs = true;
  }
  if (!belongs) {
    std::cout << "Error - Unknown state: " << state << std::endl;
    exit(-1);
  }
}

void StateManager::logAlphabet() 
{
  std::cout << "Q: {";
  for (int i = 0; i < alphabet.size(); i++) {
    std::cout << alphabet[i];
    if (i != alphabet.size() - 1)
      std::cout << ", "; 
  }
  std::cout << "}" << std::endl;
}

void StateManager::logInfo() 
{
  logAlphabet();
  std::cout << "Initial State: " << initial << std::endl;
  std::cout << "Current State: " << current << std::endl;
  std::cout << "Final States: {";
  for (int i = 0; i < valid.size(); i++)
    std::cout << valid[i] << (i != valid.size() - 1 ? ", " : "");
  std::cout << "}" << std::endl;
}

void StateManager::clear() 
{
  current = initial;
}
