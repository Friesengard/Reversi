#include <stdio.h>
#include <string>

#include "Gui.hpp"

using namespace std;

static const string applicationName="reversi";


int main(int argc, char const *argv[]) {
  printf("Running %s...\n", applicationName.c_str());
  Gui::ShowIntro();
  return 0;
}
