#include "jomna.hpp"

namespace jomna {
    namespace parser {
        class Parser {
            void rep(const std::function<bool()>& f) {
                while(i < size(P) && f()) i++;
            }
            void repsep(const std::function<bool()>& f, char c) {
                while(i < size(P) && f()) if(P[i] == c) i++; else return;
                i--;
            }

            int i;
            const string P;
            void expr();
            void num();
        public:
            Parser(const string& program) : i(0), P(program) {}
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
                    std::cerr << "parse error: " << P[i] << std::endl;
                    // move to next stmt
                    while(i < size(P) && P[i] != ' ') i++;
                }
                return 1;
            }, ' ');
        }

        void Parser::expr() {
            num();
        }

        void Parser::num() {
            if(cover('a', P[i], 'z') || cover('0', P[i], '9')) {
                int n = 0;
                rep([&](){
                    int d = -1;

                    if(cover('0', P[i], '9')) d = P[i] - '0';
                    if(cover('a', P[i], 'z')) d = P[i] - 'a' + 10;
                    if(cover('A', P[i], 'Z')) d = P[i] - 'A' + 36;
                    if(cover('~', P[i], '~')) d = 62;
                    if(cover('_', P[i], '_')) d = 63;

                    if(~d) n = n * 64 + d;
                    return ~d;
                });

                std::cout << n << std::endl;
            } else {
                throw 1; // TODO
            }
        }
    }
}
