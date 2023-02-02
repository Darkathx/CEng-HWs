#include "the4.h"

// '-' = 45 , 'A' = 65 in ASCII
int dp_sln(char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem){ //dynamic programming
    int i, j, k, ins, del, reord, rep, ins_del, temp, min, min2;
    bool reord_check;
    int reord_record1[50], reord_record2[50];
    mem[0][0] = 0;
    // TOP ROW
    for(i = 1; i < ncol2+1; i++) {
        ins = 0;
        for(j = 0; j < nrow; j++) {
            if(arr2[j][i-1] != '-') {
                ins++;
            }
        }
        mem[0][i] = mem[0][i-1] + ins;
    }
    //LEFT COLUMN
    for(i = 1; i < ncol1 + 1; i++) {
        del = 0;
        for(j = 0; j < nrow; j++) {
           if(arr1[j][i-1] != '-') {
                del++;
            } 
        }
        mem[i][0] = mem[i-1][0] + del;
    }
    //LAST ELEMENT (REORDER PROBLEM)
    for(i = 1; i < ncol1 + 1; i++) {
        for(j = 1; j < ncol2 + 1; j++) {
            rep = reord = 0;
            reord_check = true;
            for(int q = 0; q < 50; q++) {
                reord_record1[q] = 0;
                reord_record2[q] = 0;
            }
            for(k = 0; k < nrow; k++) {
                if(arr1[k][i-1] != arr2[k][j-1]) {
                    reord++;
                    reord_record1[int(arr1[k][i-1]) - 45]++;
                    reord_record2[int(arr2[k][j-1]) - 45]++;
                    rep++;
                    if(arr1[k][i-1] == '-' || arr2[k][j-1] == '-') {
                        rep++;
                    }
                }
            }
            
            for(k = 0; k < 26; k++) {
                    if(reord_record1[k] != reord_record2[k]) {
                        reord_check = false;
                        break;
                    }
                }
            ins_del = mem[0][j] - mem[0][j-1] + mem[i][0] - mem[i-1][0];
            min = fmin(ins_del, rep);
            if(reord_check) min = fmin(reord, ins_del);
            min += mem[i-1][j-1];
            min = fmin(min, mem[0][j] - mem[0][j-1] + mem[i][j-1]);
            min = fmin(min, mem[i][0] - mem[i-1][0] + mem[i-1][j]);
            mem[i][j] = min;
        }
    }

    return mem[ncol1][ncol2]; 
}

