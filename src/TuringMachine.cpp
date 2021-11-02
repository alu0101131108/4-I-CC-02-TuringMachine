#include "./../include/TuringMachine.hpp"

TuringMachine::TuringMachine() 
{}

void TuringMachine::loadFromFile(std::string filename) 
{
  // Open file and store in a vector, discarding comments.
  std::ifstream ifs("./../input-files/" + filename);
  if (!ifs.is_open()) {
    std::cout << "Error - Can't open input file: " + filename << std::endl;
    exit(-1);
  }
  std::vector<std::string> text;
  std::string line;
  while (std::getline(ifs, line)) {
    if (line.size() > 0 && line[0] != '#')
      text.push_back(line);
  }
  ifs.close();

  states = StateManager();
  // State set.
  states.clear();
  std::string symbol;
  std::stringstream iss(text[0]);
  while (!iss.eof()) {
    iss >> symbol;
    states.addToAlphabet(symbol);
  }

  // Band input alphabet.
  band = Band();
  iss.clear();
  iss.str(text[1]);
  while (!iss.eof()) {
    iss >> symbol;
    band.addToInputAlphabet(symbol);
  }
  // Band alphabet.
  iss.clear();
  iss.str(text[2]);
  while (!iss.eof()) {
    iss >> symbol;
    band.addToAlphabet(symbol);
  }

  // Initial state.
  iss.clear();
  iss.str(text[3]);
  iss >> symbol;
  states.checkInAlphabet(symbol);
  states.setInitial(symbol);

  // White symbol.
  iss.clear();
  iss.str(text[4]);
  iss >> symbol;
  whiteSymbol = symbol;
  band.checkInAlphabet(whiteSymbol);
  band.setWhite(whiteSymbol);

  // Final states;
  iss.clear();
  iss.str(text[5]);
  while (!iss.eof()) {
    iss >> symbol;
    states.addToValids(symbol);
  }

  // Transitions.
  transitions.clear();
  std::string start, input, end, output, move;
  for (int i = 6; i < text.size(); i++) {
    iss.clear();
    iss.str(text[i]);
    iss >> start;
    iss >> input;
    iss >> end;
    iss >> output;
    iss >> move;
    addTransition(Transition(start, input, end, output, move));
  }

}

void TuringMachine::logInfo() 
{
  std::cout << "INFORMATION" << std::endl;
  states.logInfo();
  band.logAlphabets();
  band.logContent();
  std::cout << "White Symbol: " << whiteSymbol << std::endl;
  logTransitions();
  std::cout << std::endl;
}

void TuringMachine::log() 
{
  band.logContent();
  std::cout << "State: " << states.get() << std::endl;
}

void TuringMachine::logTransitions() 
{
  std::cout << "Transitions:" << std::endl;
  for (int i = 0; i < transitions.size(); i++) {
    transitions[i].log();
  }
  std::cout << std::endl;
}

void TuringMachine::addTransition(Transition transition) 
{
  states.checkInAlphabet(transition.getStart());
  band.checkInAlphabet(transition.getInput());
  states.checkInAlphabet(transition.getEnd());
  band.checkInAlphabet(transition.getOutput());
  
  transitions.push_back(transition);
}

bool TuringMachine::validateString(std::string string) 
{
  states.clear();
  band.clear();
  band.setContent(string);
  while (transit()) {}
  return states.isValid();
}

bool TuringMachine::transit() 
{
  bool success = false;
  for (int i = 0; i < transitions.size(); i++) {
    if (transitions[i].getStart() == states.get() && transitions[i].getInput() == band.get()) {
      applyTransition(transitions[i]);
      success = true;
      break;
    }
  }
  return success;
}

void TuringMachine::applyTransition(Transition transition) {
  states.set(transition.getEnd());
  band.set(transition.getOutput());
  transition.getMove() == "L" ? band.moveLeft() : band.moveRight();
}


