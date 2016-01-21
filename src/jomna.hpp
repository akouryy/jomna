#ifndef JOMNA_HPP_INCLUDE
#define JOMNA_HPP_INCLUDE

#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#include "lib.hpp"
#include "command.hpp"
#include "parser.hpp"

namespace jomna {
    const int MAJOR_VERSION = 0,
              MINOR_VERSION = 0,
              TINY_VERSION = 0;
    const string VERSION = "0.0.0";
}

#endif
