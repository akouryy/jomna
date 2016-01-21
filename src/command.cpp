#include "jomna.hpp"

namespace jomna {
    namespace command {
        options parse(const vector<string>& args) {
            if(args.empty()) {
                // help();
                return {false};
            }

            options opt;

            for(auto i = args.begin(); i != args.end(); i++) {
                if((*i)[0] == '-') {
                    if((*i)[1] == '-') {
                        // long option
                    } else {
                        // short option
                    }
                } else {
                    std::ifstream program(*i);
                    opt.run = true;
                    opt.program = string(std::istreambuf_iterator<char>(program), {});
                    break;
                }
            }

            return opt;
        }
    }
}
