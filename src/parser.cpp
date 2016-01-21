#include "jomna.hpp"

namespace jomna {
    namespace parser {
        class Parser {
            void rep(const std::function<bool(char)>& f) {
                while(i < size(program) && f(program[i])) ++i;
            }
            void repsep(const std::function<void()>& f, char c) {
                do f(); while(i < size(program) && program[i++] == c);
            }

            int i;
            const string program;
            void expr();
            void num();
        public:
            Parser(const string& program) : i(0), program(program) {}
            void run();
        };


        void run(const string& program) {
            Parser(program).run();
        }

        void Parser::run() {
            repsep([&](){
                try{
                    expr();
                }catch(int){ // TODO
                    std::cerr << "parse error: " << program[i] << std::endl;
                    // move to next stmt
                    while(i < size(program) && program[i] != ' ') i++;
                }
            }, ' ');
        }

        void Parser::expr() {
            num();
        }

        void Parser::num() {
            if(cover('a', program[i], 'z') || cover('0', program[i], '9')) {
                int n = 0;
                rep([&](char c){
                    #define NUM_UPDATE(from, to, start) \
                        if(cover(from, c, to)) { n = n * 64 + c - from + start; return true; }

                    NUM_UPDATE('0', '9', 0) else
                    NUM_UPDATE('a', 'z', 10) else
                    NUM_UPDATE('A', 'Z', 36) else
                    NUM_UPDATE('~', '~', 62) else
                    NUM_UPDATE('_', '_', 63) else return false;
                });

                std::cout << n << std::endl;
            } else {
                throw 1; // TODO
            }
        }
    }
}
