#ifndef __BAND_H__
#define __BAND_H__

#include <iostream>
#include <vector>
#include <string>

class Band {
  private:
    int headIndex;
    std::vector<std::string> content;
    std::vector<std::string> inputAlphabet;
    std::vector<std::string> alphabet;
    std::string whiteSymbol;

  public:
    Band();
    void addToAlphabet(std::string symbol);
    void addToInputAlphabet(std::string symbol);
    void setContent(std::string newContent);
    void setWhite(std::string whiteSymbol_);
    std::string get();
    void set(std::string symbol);
    void moveLeft();
    void moveRight();
    void checkInAlphabet(std::string symbol);
    void checkInInputAlphabet(std::string symbol);
    void logAlphabets();
    void logContent();
    void clear();
  
};

#endif // __BAND_H__