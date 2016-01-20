// C++11
#include "jomna.hpp"

int main(int argc, char** argv) {
    vector<string> args(--argc);
    for(int i = 0; i < argc; i++) args[i] = argv[i + 1];

    jomna::command::options opt = jomna::command::parse(args);

    if(opt.run) jomna::parser::run(opt.program);

    return 0;
}
