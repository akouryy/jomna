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
                    while(i < (signed)program.size() && program[i] != ' ') i++;
                }
            while(i < (signed)program.size() && program[i++] == ' ');
            return i;
        }

        PARSE_FN_IMP(expr) {
            i = num(program, i);
            return i;
        }

        PARSE_FN_IMP(num) {
            char c = program[i];
            if('a' <= c && c <= 'z' || '0' <= c && c <= '9') {
                int n = 0;
                do {
                    c = program[i];
                    if('0' <= c && c <= '9') n = n * 64 + c - '0';
                    else if('a' <= c && c <= 'z') n = n * 64 + c - 'a' + 10;
                    else if('A' <= c && c <= 'Z') n = n * 64 + c - 'A' + 36;
                    else if(c == '~') n = n * 64 + 62;
                    else if(c == '_') n = n * 64 + 63;
                    else break;
                } while(++i < (signed)program.size());

                std::cout << n << std::endl;
                return i;
            } else {
                std::cerr << "parse error: " << c << std::endl;
                throw 1; // TODO
            }
        }
    }
}
