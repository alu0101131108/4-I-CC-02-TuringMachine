#include "./../include/TuringMachine.hpp"
#include <iostream>
#include <vector>
#include <string>


int main()
{
  TuringMachine MT;
  std::string filename, string;
  std::system("clear");
  std::cout << "Turing Machine Simulator" << std::endl;
  std::cout << "Enter description file name: ";
  std::cin >> filename;
  std::cout << std::endl;
  MT.loadFromFile(filename);
  MT.logInfo();
  std::cout << "Escriba \"reload\" para cargar otra descripción" << std::endl;
  while(true) {
    std::cout << "Cadena: ";
    std::cin >> string;
    if (string == "reload") main();
    std::cout << (MT.validateString(string) ? "Valid" : "Not valid") << std::endl;
    MT.log();
  }
}
