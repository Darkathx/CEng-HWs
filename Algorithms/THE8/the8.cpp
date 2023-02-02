#include "the8.h"

//DO NOT ADD OTHER LIBRARIES


std::vector<std::vector<int>> fsaConstructor(const std::string& pattern, const std::pair<std::string,std::string> mapping) {
    int pattern_size = pattern.size(), i, j, x, y, prevCheck;
    int bigA = 'A';
    std::vector<std::vector<int>> transitionTable(pattern_size+1);
    char first = mapping.first[0], second = mapping.second[0];
    for(i = 0; i < pattern_size + 1; i++) {
        transitionTable[i].resize(26);
    }
    for(i = 0; i < pattern_size + 1; i++) {
        for(j = 0; j < 26; j++) {
            //checking if current character is the current needed character in pattern, or can mapping substitution fix it
            if((i != pattern_size + 1) && (((pattern[i]  - bigA) == j) || ((pattern[i] == first) && (second - bigA == j)) || ((pattern[i] == second) && (first - bigA == j)))) {
                transitionTable[i][j] = i+1;
                continue;
            }
            for(x = i; x > 0; x--) {
                if((pattern[x-1] - bigA) == j) {
                    //checking if all previous characters are equal
                    prevCheck = i - x + 1;
                    for(y = 0; y < x - 1; y++) {
                        if(pattern[y] != pattern[prevCheck++]) {
                            break;
                        }
                    }
                    if(y == x - 1) {
                        transitionTable[i][j] = x;
                        break;
                    }
                }
            }
            if(!x) {
                //no matching substring
                transitionTable[i][j] = 0;
            }
        }
    }
    return transitionTable;
}

void matchPattern(const std::string& sequence, const std::pair<std::string,std::string> mapping, const std::string& pattern){


    /*****************
     *
     * 
     * YOU SHOULD PRINT THE STARTING INDEX OF EACH MATCH 
     * IN THE SAME LINE, SEPARATED BY A SINGLE SPACE
     * 
     * IF THERE IS NO MATCH, YOU SHOULD PRINT "NONE"
     *
     * *************/
     // applying transition table to incoming character
     int seq_len = sequence.size(), stateHolder = 0, i, pat_len = pattern.size();
     bool match = false;
     int bigA = 'A';
     std::vector<std::vector<int>> transitionTable = fsaConstructor(pattern, mapping);
     for(i = 0; i < seq_len; i++) {
         stateHolder = transitionTable[stateHolder][sequence[i] - bigA];
         if(stateHolder == pat_len) {
             if(match) {
                std::cout << " " << i- pat_len + 1;
             }
             else {
                match = true;
                std::cout << i- pat_len + 1;
             }
         }
     }
     if(!match) {
         std::cout << "NONE";
     }
     return;
}


