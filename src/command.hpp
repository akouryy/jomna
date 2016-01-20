#ifndef COMMAND_HPP_INCLUDE
#define COMMAND_HPP_INCLUDE
#include "jomna.hpp"

namespace jomna {
    namespace command {
        struct options {
            bool run;
            string program;
        };

        options parse(const vector<string>&);
    }
}

#endif
