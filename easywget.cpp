#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


int main() {
  std::string website;
  int proto;
  std::string options;
  int optionextra;
  std::string directory;
  std::string extras;
  std::string beginpro;

  std::cout << "Welcome to EasyWget, the easy way to use wget.\n";
  std::cout << "Please enter a website.\n";
  std::cout << "Input website here: ";
  std::cin >> website;
  std::cout << "\nHttp or Https?\n";
  std::cout << "[1]: Http\n";
  std::cout << "[2]: Https\n";
  std::cout << "Enter option 1-2: ";
  std::cin >> proto;
  std::cout << "\nAny other options? [y/n]: ";
  std::cin >> options;
  if (options == "y") {
    std::cout << "\nThe options are:\n";
    std::cout << "[1]: --recursive: download the entire Web site.\n";
    std::cout << "[2]: --domains: don't follow links outside the domain.\n";
    std::cout << "[3]: --no-parent: don't follow links outside a directory. (Must specifiy directory afterwards)\n";
    std::cout << "[4]: --page-requisites: get all the elements that compose the page (images, CSS and so on).\n";
    std::cout << "[5]: --html-extension: save files with the .html extension.\n";
    std::cout << "[6]: --convert-links: convert links so that they work locally, offline.\n";
    std::cout << "[7]: --restrict-file-names=windows: modify filenames so that they will work in Windows as well.\n";
    std::cout << "[8]: --no-clobber: don't overwrite any existing files (used in case the download is interrupted and resumed).\n";
    std::cout << "\nEnter option 1-10: ";
    std::cin >> optionextra;
  } else if (options == "n") {
    std::cout << "\nOkay. Skipping additional options...\n";
  }
  else {
    std::cout << "\nThe options are:\n";
    std::cout << "[1]: --recursive: download the entire Web site.\n";
    std::cout << "[2]: --domains: don't follow links outside the domain.\n";
    std::cout << "[3]: --no-parent: don't follow links outside a directory. (Must specifiy directory afterwards)\n";
    std::cout << "[4]: --page-requisites: get all the elements that compose the page (images, CSS and so on).\n";
    std::cout << "[5]: --html-extension: save files with the .html extension.\n";
    std::cout << "[6]: --convert-links: convert links so that they work locally, offline.\n";
    std::cout << "[7]: --restrict-file-names=windows: modify filenames so that they will work in Windows as well.\n";
    std::cout << "[8]: --no-clobber: don't overwrite any existing files (used in case the download is interrupted and resumed).\n";
    std::cout << "\nEnter option 1-10: ";
    std::cin >> optionextra;
  }

  if (optionextra == 3) {
    std::cout << "\nPlease specify directory: ";
    std::cin >>  directory;
  }

  std::cout << "\nExecuting wget...\n";
  switch (optionextra) {
    case 1 :
    extras = "--recursive";
    break;
    case 2 :
    extras = "--domains";
    break;
    case 3 :
    extras = "--no-parent " + directory;
    break;
    case 4 :
    extras = "--page-requisites";
    break;
    case 5 :
    extras = "--html-extension";
    break;
    case 6 :
    extras = "--convert-links";
    break;
    case 7 :
    extras = "--restrict-file-names=windows";
    break;
    case 8 :
    extras = "--no-clobber";
    break;
  }

  switch (proto) {
    case 1 :
    beginpro = "http://";
    break;
    case 2 :
    beginpro = "https://";
    break;
    default :
    std::cout << "\nProtocol error, using http as default\n";
    beginpro = "http://";
    break;
  }

  if (options == "y") {
    system(("sudo wget " + extras + " " + beginpro + website).c_str() );
  }
  else {
    system(("sudo wget " + beginpro + website).c_str() );
  }

  std::cout << "\nWget completed.\n";
}
