#include "jomna.hpp"

#define PARSE_FN_IMP(fn) int fn(const string& program, int i)
#define PARSE_FN_DEC(fn) int fn(const string&, int);

namespace jomna {
    namespace parser {
        PARSE_FN_DEC(stmts);
        PARSE_FN_DEC(expr);
        PARSE_FN_DEC(num);

        void run(const string& program) {
            stmts(program, 0);
        }

        PARSE_FN_IMP(stmts) {
            do
                try{
                    i = expr(program, i);
                }catch(int){ // TODO
                    // move to next stmt
                    while(i < size(program) && program[i] != ' ') i++;
                }
            while(i < size(program) && program[i++] == ' ');
            return i;
        }

        PARSE_FN_IMP(expr) {
            i = num(program, i);
            return i;
        }

        PARSE_FN_IMP(num) {
            char c = program[i];
            if(cover('a', c, 'z') || cover('0', c, '9')) {
                int n = 0;
                do {
                    c = program[i];

                    #define NUM_UPDATE(from, to, start) \
                        if(cover(from, c, to)) n = n * 64 + c - from + start;

                    NUM_UPDATE('0', '9', 0) else
                    NUM_UPDATE('a', 'z', 10) else
                    NUM_UPDATE('A', 'Z', 36) else
                    NUM_UPDATE('~', '~', 62) else
                    NUM_UPDATE('_', '_', 63) else break;
                } while(++i < size(program));

                std::cout << n << std::endl;
                return i;
            } else {
                std::cerr << "parse error: " << c << std::endl;
                throw 1; // TODO
            }
        }
    }
}
