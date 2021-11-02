#include "./../include/Transition.hpp"

Transition::Transition() 
{}

Transition::Transition(std::string start_, std::string input_, 
    std::string end_, std::string output_, std::string move_) 
{
  start = start_;
  input = input_;
  end = end_;
  output = output_;
  move = move_;
}

std::string Transition::getStart() 
{
  return start;
}

std::string Transition::getInput() 
{
  return input;
}

std::string Transition::getEnd() 
{
  return end;
}

std::string Transition::getOutput() 
{
  return output;
}

std::string Transition::getMove() 
{
  return move;
}

void Transition::log() 
{
  std::cout << "(" << start << ", " << input << ", ";
  std::cout << end << ", " << output << ", " << move;
  std::cout << ")" << std::endl;
}
