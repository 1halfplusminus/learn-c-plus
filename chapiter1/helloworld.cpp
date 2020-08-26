// This program outputs the message “Hello, World!” to the monitor

#include "std_lib_facilities.h"

int main() // C++ programs start by executing the function main
{
  std::cout << "Hello, World!\n"
            << "Here we go !"
            << "\n"
            << std::endl; // output “Hello, World!”
  keep_window_open();
  return 0;
}