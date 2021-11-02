#include "./../include/Band.hpp"

Band::Band() 
{
  whiteSymbol = ".";
}

void Band::addToAlphabet(std::string symbol) 
{
  alphabet.push_back(symbol);
}

void Band::addToInputAlphabet(std::string symbol) 
{
  inputAlphabet.push_back(symbol);
}

void Band::setContent(std::string newContent) 
{
  headIndex = 1;
  content.clear();
  content.push_back(whiteSymbol);
  for (int i = 0; i < newContent.size(); i++) {
    checkInInputAlphabet(std::string(1, newContent[i]));
    content.push_back(std::string(1, newContent[i]));
  }
  content.push_back(whiteSymbol);
}

void Band::setWhite(std::string whiteSymbol_) 
{
  whiteSymbol = whiteSymbol_;
}

std::string Band::get() 
{
  if (headIndex >= content.size()) {
    std::cout << "Error - Band headIndex out of range" << std::endl;
    exit(-1);
  }
  return content[headIndex];
}

void Band::set(std::string symbol) 
{
  if (headIndex >= content.size()) {
    std::cout << "Error - Band headIndex out of range" << std::endl;
    exit(-1);
  }
  content[headIndex] = symbol;
}

void Band::moveLeft() 
{
  if (headIndex > 0) {
    // std::cout << "Band warning - Moving outside content" << std::endl;
    headIndex--;
  }
}

void Band::moveRight() 
{
  if (headIndex < content.size() - 1) {
    // std::cout << "Band warning - Moving outside content" << std::endl;
    headIndex++;
  }
}

void Band::checkInAlphabet(std::string symbol) 
{
  bool belongs = false;
  for (int i = 0; i < alphabet.size(); i++) {
    if (symbol == alphabet[i])
      belongs = true;
  }
  if (!belongs) {
    std::cout << "Error - Symbol not in band's alphabet: " << symbol << std::endl;
    exit(-1);
  }
}

void Band::checkInInputAlphabet(std::string symbol) 
{
  bool belongs = false;
  for (int i = 0; i < inputAlphabet.size(); i++) {
    if (symbol == inputAlphabet[i])
      belongs = true;
  }
  if (!belongs) {
    std::cout << "Error - Symbol not in band's input alphabet: " << symbol << std::endl;
    exit(-1);
  }
}


void Band::logAlphabets() 
{
  std::cout << "Input Alphabet: {";
  for (int i = 0; i < inputAlphabet.size(); i++) {
    std::cout << inputAlphabet[i];
    if (i != inputAlphabet.size() - 1)
      std::cout << ", "; 
  }
  std::cout << "}" << std::endl;

  std::cout << "Alphabet: {";
  for (int i = 0; i < alphabet.size(); i++) {
    std::cout << alphabet[i];
    if (i != alphabet.size() - 1)
      std::cout << ", "; 
  }
  std::cout << "}" << std::endl;
}

void Band::logContent() 
{
  std::cout << "Band Content: ";
  for (int i = 0; i < content.size(); i++) {
    if (i == headIndex) 
      std::cout << "<[" << content[i] << "]>";
    else
      std::cout << "[" << content[i] << "]";
  }
  std::cout << std::endl;
}

void Band::clear() 
{
  headIndex = 1;
  content.clear();
}

