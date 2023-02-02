/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "TEAM MANKERSAM",    /* Team Name */

        "e252213",      /* First student ID */
        "Meriç Kerem Yalçın",       /* First student name */

        "e223713",             /* Second student ID */
        "Şamil Candemir",           /* Second student name */

        "e265083",             /* Third student ID */
        "Madiya Bano"            /* Third student Name */
};


/********************
 * CONVOLUTION KERNEL
 ********************/

/***************************************************************
 * Your different versions of the convolution functions  go here
 ***************************************************************/

/*
 * naive_conv - The naive baseline version of convolution
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[RIDX(i, j, dim)] = 0;
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
                }

        }
}

char test2_descr[] = "test version 2";
void test2_convolution(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j, ridx, checkVal = dim - 7, accumulator = 0, rt;
    unsigned long val1, val2 ,val3;

    for(i = 0; i < checkVal; ++i) {
      rt = accumulator;
        for(j = 0; j < checkVal; ++j) {

            val1 = 0;
    	      val2 = 0;
	          val3 = 0;

            ridx = rt;

            val1 += (src[ridx].red * ker[0].red);
            val2 += (src[ridx].green * ker[0].green);
            val3 += (src[ridx].blue * ker[0].blue);

            ridx++;

            val1 += (src[ridx].red * ker[1].red);
            val2 += (src[ridx].green * ker[1].green);
            val3 += (src[ridx].blue * ker[1].blue);

            ridx++;

            val1 += (src[ridx].red * ker[2].red);
            val2 += (src[ridx].green * ker[2].green);
            val3 += (src[ridx].blue * ker[2].blue);

            ridx++;

            val1 += (src[ridx].red * ker[3].red);
            val2 += (src[ridx].green * ker[3].green);
            val3 += (src[ridx].blue * ker[3].blue);

            ridx++;

            val1 += (src[ridx].red * ker[4].red);
            val2 += (src[ridx].green * ker[4].green);
            val3 += (src[ridx].blue * ker[4].blue);

            ridx++;

            val1 += (src[ridx].red * ker[5].red);
            val2 += (src[ridx].green * ker[5].green);
            val3 += (src[ridx].blue * ker[5].blue);

            ridx++;

            val1 += (src[ridx].red * ker[6].red);
            val2 += (src[ridx].green * ker[6].green);
            val3 += (src[ridx].blue * ker[6].blue);

            ridx++;

            val1 += (src[ridx].red * ker[7].red);
            val2 += (src[ridx].green * ker[7].green);
            val3 += (src[ridx].blue * ker[7].blue);

            ///////////////////////////////////////////////////////////////////////////////////////



            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[8].red;
            val2 += src[ridx].green * ker[8].green;
            val3 += src[ridx].blue * ker[8].blue;

            ridx++;

            val1 += src[ridx].red * ker[9].red;
            val2 += src[ridx].green * ker[9].green;
            val3 += src[ridx].blue * ker[9].blue;

            ridx++;

            val1 += src[ridx].red * ker[10].red;
            val2 += src[ridx].green * ker[10].green;
            val3 += src[ridx].blue * ker[10].blue;

            ridx++;

            val1 += src[ridx].red * ker[11].red;
            val2 += src[ridx].green * ker[11].green;
            val3 += src[ridx].blue * ker[11].blue;

            ridx++;

            val1 += src[ridx].red * ker[12].red;
            val2 += src[ridx].green * ker[12].green;
            val3 += src[ridx].blue * ker[12].blue;

            ridx++;

            val1 += src[ridx].red * ker[13].red;
            val2 += src[ridx].green * ker[13].green;
            val3 += src[ridx].blue * ker[13].blue;

            ridx++;

            val1 += src[ridx].red * ker[14].red;
            val2 += src[ridx].green * ker[14].green;
            val3 += src[ridx].blue * ker[14].blue;

            ridx++;

            val1 += src[ridx].red * ker[15].red;
            val2 += src[ridx].green * ker[15].green;
            val3 += src[ridx].blue * ker[15].blue;


            ///////////////////////////////////////////////////////////////////////////////////////

            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[16].red;
            val2 += src[ridx].green * ker[16].green;
            val3 += src[ridx].blue * ker[16].blue;

            ridx++;

            val1 += src[ridx].red * ker[17].red;
            val2 += src[ridx].green * ker[17].green;
            val3 += src[ridx].blue * ker[17].blue;

            ridx++;

            val1 += src[ridx].red * ker[18].red;
            val2 += src[ridx].green * ker[18].green;
            val3 += src[ridx].blue * ker[18].blue;

            ridx++;

            val1 += src[ridx].red * ker[19].red;
            val2 += src[ridx].green * ker[19].green;
            val3 += src[ridx].blue * ker[19].blue;

            ridx++;

            val1 += src[ridx].red * ker[20].red;
            val2 += src[ridx].green * ker[20].green;
            val3 += src[ridx].blue * ker[20].blue;

            ridx++;

            val1 += src[ridx].red * ker[21].red;
            val2 += src[ridx].green * ker[21].green;
            val3 += src[ridx].blue * ker[21].blue;

            ridx++;

            val1 += src[ridx].red * ker[22].red;
            val2 += src[ridx].green * ker[22].green;
            val3 += src[ridx].blue * ker[22].blue;

            ridx++;

            val1 += src[ridx].red * ker[23].red;
            val2 += src[ridx].green * ker[23].green;
            val3 += src[ridx].blue * ker[23].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[24].red;
            val2 += src[ridx].green * ker[24].green;
            val3 += src[ridx].blue * ker[24].blue;

            ridx++;

            val1 += src[ridx].red * ker[25].red;
            val2 += src[ridx].green * ker[25].green;
            val3 += src[ridx].blue * ker[25].blue;

            ridx++;

            val1 += src[ridx].red * ker[26].red;
            val2 += src[ridx].green * ker[26].green;
            val3 += src[ridx].blue * ker[26].blue;

            ridx++;

            val1 += src[ridx].red * ker[27].red;
            val2 += src[ridx].green * ker[27].green;
            val3 += src[ridx].blue * ker[27].blue;

            ridx++;

            val1 += src[ridx].red * ker[28].red;
            val2 += src[ridx].green * ker[28].green;
            val3 += src[ridx].blue * ker[28].blue;

            ridx++;

            val1 += src[ridx].red * ker[29].red;
            val2 += src[ridx].green * ker[29].green;
            val3 += src[ridx].blue * ker[29].blue;

            ridx++;

            val1 += src[ridx].red * ker[30].red;
            val2 += src[ridx].green * ker[30].green;
            val3 += src[ridx].blue * ker[30].blue;

            ridx++;

            val1 += src[ridx].red * ker[31].red;
            val2 += src[ridx].green * ker[31].green;
            val3 += src[ridx].blue * ker[31].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[32].red;
            val2 += src[ridx].green * ker[32].green;
            val3 += src[ridx].blue * ker[32].blue;

            ridx++;

            val1 += src[ridx].red * ker[33].red;
            val2 += src[ridx].green * ker[33].green;
            val3 += src[ridx].blue * ker[33].blue;

            ridx++;

            val1 += src[ridx].red * ker[34].red;
            val2 += src[ridx].green * ker[34].green;
            val3 += src[ridx].blue * ker[34].blue;

            ridx++;

            val1 += src[ridx].red * ker[35].red;
            val2 += src[ridx].green * ker[35].green;
            val3 += src[ridx].blue * ker[35].blue;

            ridx++;

            val1 += src[ridx].red * ker[36].red;
            val2 += src[ridx].green * ker[36].green;
            val3 += src[ridx].blue * ker[36].blue;

            ridx++;

            val1 += src[ridx].red * ker[37].red;
            val2 += src[ridx].green * ker[37].green;
            val3 += src[ridx].blue * ker[37].blue;

            ridx++;

            val1 += src[ridx].red * ker[38].red;
            val2 += src[ridx].green * ker[38].green;
            val3 += src[ridx].blue * ker[38].blue;

            ridx++;

            val1 += src[ridx].red * ker[39].red;
            val2 += src[ridx].green * ker[39].green;
            val3 += src[ridx].blue * ker[39].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[40].red;
            val2 += src[ridx].green * ker[40].green;
            val3 += src[ridx].blue * ker[40].blue;

            ridx++;

            val1 += src[ridx].red * ker[41].red;
            val2 += src[ridx].green * ker[41].green;
            val3 += src[ridx].blue * ker[41].blue;

            ridx++;

            val1 += src[ridx].red * ker[42].red;
            val2 += src[ridx].green * ker[42].green;
            val3 += src[ridx].blue * ker[42].blue;

            ridx++;

            val1 += src[ridx].red * ker[43].red;
            val2 += src[ridx].green * ker[43].green;
            val3 += src[ridx].blue * ker[43].blue;

            ridx++;

            val1 += src[ridx].red * ker[44].red;
            val2 += src[ridx].green * ker[44].green;
            val3 += src[ridx].blue * ker[44].blue;

            ridx++;

            val1 += src[ridx].red * ker[45].red;
            val2 += src[ridx].green * ker[45].green;
            val3 += src[ridx].blue * ker[45].blue;

            ridx++;

            val1 += src[ridx].red * ker[46].red;
            val2 += src[ridx].green * ker[46].green;
            val3 += src[ridx].blue * ker[46].blue;

            ridx++;

            val1 += src[ridx].red * ker[47].red;
            val2 += src[ridx].green * ker[47].green;
            val3 += src[ridx].blue * ker[47].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[48].red;
            val2 += src[ridx].green * ker[48].green;
            val3 += src[ridx].blue * ker[48].blue;

            ridx++;

            val1 += src[ridx].red * ker[49].red;
            val2 += src[ridx].green * ker[49].green;
            val3 += src[ridx].blue * ker[49].blue;

            ridx++;

            val1 += src[ridx].red * ker[50].red;
            val2 += src[ridx].green * ker[50].green;
            val3 += src[ridx].blue * ker[50].blue;

            ridx++;

            val1 += src[ridx].red * ker[51].red;
            val2 += src[ridx].green * ker[51].green;
            val3 += src[ridx].blue * ker[51].blue;

            ridx++;

            val1 += src[ridx].red * ker[52].red;
            val2 += src[ridx].green * ker[52].green;
            val3 += src[ridx].blue * ker[52].blue;

            ridx++;

            val1 += src[ridx].red * ker[53].red;
            val2 += src[ridx].green * ker[53].green;
            val3 += src[ridx].blue * ker[53].blue;

            ridx++;

            val1 += src[ridx].red * ker[54].red;
            val2 += src[ridx].green * ker[54].green;
            val3 += src[ridx].blue * ker[54].blue;

            ridx++;

            val1 += src[ridx].red * ker[55].red;
            val2 += src[ridx].green * ker[55].green;
            val3 += src[ridx].blue * ker[55].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[56].red;
            val2 += src[ridx].green * ker[56].green;
            val3 += src[ridx].blue * ker[56].blue;

            ridx++;

            val1 += src[ridx].red * ker[57].red;
            val2 += src[ridx].green * ker[57].green;
            val3 += src[ridx].blue * ker[57].blue;

            ridx++;

            val1 += src[ridx].red * ker[58].red;
            val2 += src[ridx].green * ker[58].green;
            val3 += src[ridx].blue * ker[58].blue;

            ridx++;

            val1 += src[ridx].red * ker[59].red;
            val2 += src[ridx].green * ker[59].green;
            val3 += src[ridx].blue * ker[59].blue;

            ridx++;

            val1 += src[ridx].red * ker[60].red;
            val2 += src[ridx].green * ker[60].green;
            val3 += src[ridx].blue * ker[60].blue;

            ridx++;

            val1 += src[ridx].red * ker[61].red;
            val2 += src[ridx].green * ker[61].green;
            val3 += src[ridx].blue * ker[61].blue;

            ridx++;

            val1 += src[ridx].red * ker[62].red;
            val2 += src[ridx].green * ker[62].green;
            val3 += src[ridx].blue * ker[62].blue;

            ridx++;

            val1 += src[ridx].red * ker[63].red;
            val2 += src[ridx].green * ker[63].green;
            val3 += src[ridx].blue * ker[63].blue;

            dst[rt] = val1 + val2 + val3;
            rt++;

        }
        accumulator += dim;
	}
}

char test3_descr[] = "Test version 3";
void test3_convolution(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[RIDX(i, j, dim)] = 0;
            
            
            k = 0;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
		k = 1;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            k = 2;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 3;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 4;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 5;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 6;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 7;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            

        }



}

char test4_descr[] = "Test version 4";
void test4_convolution(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l, checkVal = dim - 7;
    unsigned long val;

    for(i = 0; i < checkVal; i++)
        for(j = 0; j < checkVal; j++) {
            dst[RIDX(i, j, dim)] = 0;
            
            
            k = 0;    l = 0;
            
            val = src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            val += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            val += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
		k = 1;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            k = 2;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 3;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 4;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 5;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 6;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            ///////////////////////////////////////////////////////////////////////////////////////
            
            
            k = 7;    l = 0;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 1;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 2;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 3;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 4;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 5;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            l = 6;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            
            l = 7;
            
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
            dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
            
            

        }

}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: Current working version";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    int i,j, ridx, checkVal = dim - 7, accumulator = 0, rt;
    unsigned long val1, val2 ,val3;

    for(i = 0; i < checkVal; ++i) {
      rt = accumulator;
        for(j = 0; j < checkVal; ++j) {

            val1 = 0;
    	      val2 = 0;
	          val3 = 0;

            ridx = rt;

            val1 += (src[ridx].red * ker[0].red);
            val2 += (src[ridx].green * ker[0].green);
            val3 += (src[ridx].blue * ker[0].blue);

            ridx++;

            val1 += (src[ridx].red * ker[1].red);
            val2 += (src[ridx].green * ker[1].green);
            val3 += (src[ridx].blue * ker[1].blue);

            ridx++;

            val1 += (src[ridx].red * ker[2].red);
            val2 += (src[ridx].green * ker[2].green);
            val3 += (src[ridx].blue * ker[2].blue);

            ridx++;

            val1 += (src[ridx].red * ker[3].red);
            val2 += (src[ridx].green * ker[3].green);
            val3 += (src[ridx].blue * ker[3].blue);

            ridx++;

            val1 += (src[ridx].red * ker[4].red);
            val2 += (src[ridx].green * ker[4].green);
            val3 += (src[ridx].blue * ker[4].blue);

            ridx++;

            val1 += (src[ridx].red * ker[5].red);
            val2 += (src[ridx].green * ker[5].green);
            val3 += (src[ridx].blue * ker[5].blue);

            ridx++;

            val1 += (src[ridx].red * ker[6].red);
            val2 += (src[ridx].green * ker[6].green);
            val3 += (src[ridx].blue * ker[6].blue);

            ridx++;

            val1 += (src[ridx].red * ker[7].red);
            val2 += (src[ridx].green * ker[7].green);
            val3 += (src[ridx].blue * ker[7].blue);

            ///////////////////////////////////////////////////////////////////////////////////////



            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[8].red;
            val2 += src[ridx].green * ker[8].green;
            val3 += src[ridx].blue * ker[8].blue;

            ridx++;

            val1 += src[ridx].red * ker[9].red;
            val2 += src[ridx].green * ker[9].green;
            val3 += src[ridx].blue * ker[9].blue;

            ridx++;

            val1 += src[ridx].red * ker[10].red;
            val2 += src[ridx].green * ker[10].green;
            val3 += src[ridx].blue * ker[10].blue;

            ridx++;

            val1 += src[ridx].red * ker[11].red;
            val2 += src[ridx].green * ker[11].green;
            val3 += src[ridx].blue * ker[11].blue;

            ridx++;

            val1 += src[ridx].red * ker[12].red;
            val2 += src[ridx].green * ker[12].green;
            val3 += src[ridx].blue * ker[12].blue;

            ridx++;

            val1 += src[ridx].red * ker[13].red;
            val2 += src[ridx].green * ker[13].green;
            val3 += src[ridx].blue * ker[13].blue;

            ridx++;

            val1 += src[ridx].red * ker[14].red;
            val2 += src[ridx].green * ker[14].green;
            val3 += src[ridx].blue * ker[14].blue;

            ridx++;

            val1 += src[ridx].red * ker[15].red;
            val2 += src[ridx].green * ker[15].green;
            val3 += src[ridx].blue * ker[15].blue;


            ///////////////////////////////////////////////////////////////////////////////////////

            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[16].red;
            val2 += src[ridx].green * ker[16].green;
            val3 += src[ridx].blue * ker[16].blue;

            ridx++;

            val1 += src[ridx].red * ker[17].red;
            val2 += src[ridx].green * ker[17].green;
            val3 += src[ridx].blue * ker[17].blue;

            ridx++;

            val1 += src[ridx].red * ker[18].red;
            val2 += src[ridx].green * ker[18].green;
            val3 += src[ridx].blue * ker[18].blue;

            ridx++;

            val1 += src[ridx].red * ker[19].red;
            val2 += src[ridx].green * ker[19].green;
            val3 += src[ridx].blue * ker[19].blue;

            ridx++;

            val1 += src[ridx].red * ker[20].red;
            val2 += src[ridx].green * ker[20].green;
            val3 += src[ridx].blue * ker[20].blue;

            ridx++;

            val1 += src[ridx].red * ker[21].red;
            val2 += src[ridx].green * ker[21].green;
            val3 += src[ridx].blue * ker[21].blue;

            ridx++;

            val1 += src[ridx].red * ker[22].red;
            val2 += src[ridx].green * ker[22].green;
            val3 += src[ridx].blue * ker[22].blue;

            ridx++;

            val1 += src[ridx].red * ker[23].red;
            val2 += src[ridx].green * ker[23].green;
            val3 += src[ridx].blue * ker[23].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[24].red;
            val2 += src[ridx].green * ker[24].green;
            val3 += src[ridx].blue * ker[24].blue;

            ridx++;

            val1 += src[ridx].red * ker[25].red;
            val2 += src[ridx].green * ker[25].green;
            val3 += src[ridx].blue * ker[25].blue;

            ridx++;

            val1 += src[ridx].red * ker[26].red;
            val2 += src[ridx].green * ker[26].green;
            val3 += src[ridx].blue * ker[26].blue;

            ridx++;

            val1 += src[ridx].red * ker[27].red;
            val2 += src[ridx].green * ker[27].green;
            val3 += src[ridx].blue * ker[27].blue;

            ridx++;

            val1 += src[ridx].red * ker[28].red;
            val2 += src[ridx].green * ker[28].green;
            val3 += src[ridx].blue * ker[28].blue;

            ridx++;

            val1 += src[ridx].red * ker[29].red;
            val2 += src[ridx].green * ker[29].green;
            val3 += src[ridx].blue * ker[29].blue;

            ridx++;

            val1 += src[ridx].red * ker[30].red;
            val2 += src[ridx].green * ker[30].green;
            val3 += src[ridx].blue * ker[30].blue;

            ridx++;

            val1 += src[ridx].red * ker[31].red;
            val2 += src[ridx].green * ker[31].green;
            val3 += src[ridx].blue * ker[31].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[32].red;
            val2 += src[ridx].green * ker[32].green;
            val3 += src[ridx].blue * ker[32].blue;

            ridx++;

            val1 += src[ridx].red * ker[33].red;
            val2 += src[ridx].green * ker[33].green;
            val3 += src[ridx].blue * ker[33].blue;

            ridx++;

            val1 += src[ridx].red * ker[34].red;
            val2 += src[ridx].green * ker[34].green;
            val3 += src[ridx].blue * ker[34].blue;

            ridx++;

            val1 += src[ridx].red * ker[35].red;
            val2 += src[ridx].green * ker[35].green;
            val3 += src[ridx].blue * ker[35].blue;

            ridx++;

            val1 += src[ridx].red * ker[36].red;
            val2 += src[ridx].green * ker[36].green;
            val3 += src[ridx].blue * ker[36].blue;

            ridx++;

            val1 += src[ridx].red * ker[37].red;
            val2 += src[ridx].green * ker[37].green;
            val3 += src[ridx].blue * ker[37].blue;

            ridx++;

            val1 += src[ridx].red * ker[38].red;
            val2 += src[ridx].green * ker[38].green;
            val3 += src[ridx].blue * ker[38].blue;

            ridx++;

            val1 += src[ridx].red * ker[39].red;
            val2 += src[ridx].green * ker[39].green;
            val3 += src[ridx].blue * ker[39].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[40].red;
            val2 += src[ridx].green * ker[40].green;
            val3 += src[ridx].blue * ker[40].blue;

            ridx++;

            val1 += src[ridx].red * ker[41].red;
            val2 += src[ridx].green * ker[41].green;
            val3 += src[ridx].blue * ker[41].blue;

            ridx++;

            val1 += src[ridx].red * ker[42].red;
            val2 += src[ridx].green * ker[42].green;
            val3 += src[ridx].blue * ker[42].blue;

            ridx++;

            val1 += src[ridx].red * ker[43].red;
            val2 += src[ridx].green * ker[43].green;
            val3 += src[ridx].blue * ker[43].blue;

            ridx++;

            val1 += src[ridx].red * ker[44].red;
            val2 += src[ridx].green * ker[44].green;
            val3 += src[ridx].blue * ker[44].blue;

            ridx++;

            val1 += src[ridx].red * ker[45].red;
            val2 += src[ridx].green * ker[45].green;
            val3 += src[ridx].blue * ker[45].blue;

            ridx++;

            val1 += src[ridx].red * ker[46].red;
            val2 += src[ridx].green * ker[46].green;
            val3 += src[ridx].blue * ker[46].blue;

            ridx++;

            val1 += src[ridx].red * ker[47].red;
            val2 += src[ridx].green * ker[47].green;
            val3 += src[ridx].blue * ker[47].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[48].red;
            val2 += src[ridx].green * ker[48].green;
            val3 += src[ridx].blue * ker[48].blue;

            ridx++;

            val1 += src[ridx].red * ker[49].red;
            val2 += src[ridx].green * ker[49].green;
            val3 += src[ridx].blue * ker[49].blue;

            ridx++;

            val1 += src[ridx].red * ker[50].red;
            val2 += src[ridx].green * ker[50].green;
            val3 += src[ridx].blue * ker[50].blue;

            ridx++;

            val1 += src[ridx].red * ker[51].red;
            val2 += src[ridx].green * ker[51].green;
            val3 += src[ridx].blue * ker[51].blue;

            ridx++;

            val1 += src[ridx].red * ker[52].red;
            val2 += src[ridx].green * ker[52].green;
            val3 += src[ridx].blue * ker[52].blue;

            ridx++;

            val1 += src[ridx].red * ker[53].red;
            val2 += src[ridx].green * ker[53].green;
            val3 += src[ridx].blue * ker[53].blue;

            ridx++;

            val1 += src[ridx].red * ker[54].red;
            val2 += src[ridx].green * ker[54].green;
            val3 += src[ridx].blue * ker[54].blue;

            ridx++;

            val1 += src[ridx].red * ker[55].red;
            val2 += src[ridx].green * ker[55].green;
            val3 += src[ridx].blue * ker[55].blue;


            ///////////////////////////////////////////////////////////////////////////////////////


            ridx = ridx - 7 + dim;

            val1 += src[ridx].red * ker[56].red;
            val2 += src[ridx].green * ker[56].green;
            val3 += src[ridx].blue * ker[56].blue;

            ridx++;

            val1 += src[ridx].red * ker[57].red;
            val2 += src[ridx].green * ker[57].green;
            val3 += src[ridx].blue * ker[57].blue;

            ridx++;

            val1 += src[ridx].red * ker[58].red;
            val2 += src[ridx].green * ker[58].green;
            val3 += src[ridx].blue * ker[58].blue;

            ridx++;

            val1 += src[ridx].red * ker[59].red;
            val2 += src[ridx].green * ker[59].green;
            val3 += src[ridx].blue * ker[59].blue;

            ridx++;

            val1 += src[ridx].red * ker[60].red;
            val2 += src[ridx].green * ker[60].green;
            val3 += src[ridx].blue * ker[60].blue;

            ridx++;

            val1 += src[ridx].red * ker[61].red;
            val2 += src[ridx].green * ker[61].green;
            val3 += src[ridx].blue * ker[61].blue;

            ridx++;

            val1 += src[ridx].red * ker[62].red;
            val2 += src[ridx].green * ker[62].green;
            val3 += src[ridx].blue * ker[62].blue;

            ridx++;

            val1 += src[ridx].red * ker[63].red;
            val2 += src[ridx].green * ker[63].green;
            val3 += src[ridx].blue * ker[63].blue;

            dst[rt] = val1 + val2 + val3;
            rt++;

        }
        accumulator += dim;
	}

}

char test1_descr[] = "Test version 1";
void test1_convolution(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l;
    int checkVal = dim - 8 + 1;
    unsigned long val;
    //long h1, h2, h3, h4;
    pixel p1, p2, p3, p4, k1, k2, k3 ,k4;

    for(i = 0; i < checkVal; i++)
        for(j = 0; j < checkVal; j++) {
            val = 0;
            for(k = 0; k < 8; k+=2) {
                for(l = 0; l < 8; l+=2) {
                    p1 = src[RIDX((i+k),(j+l), dim)];
                    p2 = src[RIDX((i+k+1),(j+l), dim)];
                    p3 = src[RIDX((i+k),(j+l+1), dim)];
                    p4 = src[RIDX((i+k+1),(j+l+1), dim)];
                    k1 = ker[RIDX(k, l, 8)];
                    k2 = ker[RIDX(k+1, l, 8)];
                    k3 = ker[RIDX(k, l+1, 8)];
                    k4 = ker[RIDX(k+1, l+1, 8)];
                    val += ((p1.red * k1.red + p1.green * k1.green + p1.blue * k1.blue) + (p2.red * k2.red + p2.green * k2.green + p2.blue * k2.blue) + (p3.red * k3.red + p3.green * k3.green + p3.blue * k3.blue) + (p4.red * k4.red + p4.green * k4.green + p4.blue * k4.blue));

                }
            }
            dst[RIDX(i, j, dim)] = val;
        }
}



/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);
    add_conv_function(&convolution, convolution_descr);
    //add_conv_function(&test1_convolution, test1_descr);
    //add_conv_function(&test2_convolution, test2_descr);
    //add_conv_function(&test3_convolution, test3_descr);
    //add_conv_function(&test4_convolution, test4_descr);
    /* ... Register additional test functions here */
}




/************************
 * AVERAGE POOLING KERNEL
 ************************/

/*********************************************************
 * Your different versions of the average pooling  go here
 *********************************************************/

/*
 * naive_average_pooling - The naive baseline version of average pooling
 */
char naive_average_pooling_descr[] = "Naive Average Pooling: Naive baseline implementation";
void naive_average_pooling(int dim, pixel *src, pixel *dst) {
    int i,j,k,l;
    for(i = 0; i < dim/2; i++)
        for(j = 0; j < dim/2; j++) {
            dst[RIDX(i, j, dim/2)].red = 0;
            dst[RIDX(i, j, dim/2)].green = 0;
            dst[RIDX(i, j, dim/2)].blue = 0;
            for(k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    dst[RIDX(i, j, dim/2)].red += src[RIDX(i*2 + k, j*2 + l, dim)].red;
                    dst[RIDX(i, j, dim/2)].green += src[RIDX(i*2 + k, j*2 + l, dim)].green;
                    dst[RIDX(i, j, dim/2)].blue += src[RIDX(i*2 + k, j*2 + l, dim)].blue;
                }
            }
            dst[RIDX(i, j, dim/2)].red /= 4;
            dst[RIDX(i, j, dim/2)].green /= 4;
            dst[RIDX(i, j, dim/2)].blue /= 4;
        }
}


/*
 * average_pooling - Your current working version of average_pooling
 * IMPORTANT: This is the version you will be graded on
 */
char average_pooling_descr[] = "Average Pooling: Current working version";
void average_pooling(int dim, pixel *src, pixel *dst)
{

    int i,j, ridx, addr, checkVal = dim >> 1, mult = 0, mult2 = 0;
    unsigned long val1, val2, val3;

    for(i = 0; i < checkVal; i++) {
        for(j = 0; j < checkVal; j++) {
            addr = mult + j;
            ridx = mult2 + (j << 1);
            val1 = val2 = val3 = 0;

            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;


            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx = ridx + (dim - 1);
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;


            val1 >>= 2;
            val2 >>= 2;
            val3 >>= 2;
            dst[addr].red = val1;
            dst[addr].green = val2;
            dst[addr].blue = val3;


        }
        mult += (dim >> 1);
        mult2 += (dim << 1);
        }
}


char test_pooling_descr[] = "Test Pooling: Current testing version";
void test_pooling(int dim, pixel *src, pixel *dst)
{

   int i,j, ridx, addr, checkVal = dim >> 1, mult;
    switch(dim) {
        case 32:
            mult = 5;
            break;
        case 64:
            mult = 6;
            break;
        case 128:
            mult = 7;
            break;
        case 256:
            mult = 8;
            break;
        case 512:
            mult = 9;
            break;
        default:
            mult = 0;
    }
    for(i = 0; i < checkVal; i++)
        for(j = 0; j < checkVal; j++) {
            if(mult) {
                addr = ((i << (mult - 1))) + j;
                ridx = ((i << 1) << mult) + (j << 1);
            }
            else {
                addr = RIDX(i, j, checkVal);
                ridx = RIDX(i << 1, j << 1, dim);
            }
            dst[addr].red = dst[addr].green = dst[addr].blue = 0;

            dst[addr].red += src[ridx].red;
            dst[addr].green += src[ridx].green;
            dst[addr].blue += src[ridx].blue;

            ridx++;
            dst[addr].red += src[ridx].red;
            dst[addr].green += src[ridx].green;
            dst[addr].blue += src[ridx].blue;

            ridx = ridx - 1 + dim;
            dst[addr].red += src[ridx].red;
            dst[addr].green += src[ridx].green;
            dst[addr].blue += src[ridx].blue;

            ridx++;
            dst[addr].red += src[ridx].red;
            dst[addr].green += src[ridx].green;
            dst[addr].blue += src[ridx].blue;

            dst[addr].red >>= 2;
            dst[addr].green >>= 2;
            dst[addr].blue >>= 2;
        }
}

char test2_pooling_descr[] = "Test2 Pooling: Current testing version 2";
void test2_pooling(int dim, pixel *src, pixel *dst) {
    int i,j, ridx, addr, checkVal = dim >> 1, mult;
    unsigned long val1, val2, val3;
    switch(dim) {
        case 32:
            mult = 5;
            break;
        case 64:
            mult = 6;
            break;
        case 128:
            mult = 7;
            break;
        case 256:
            mult = 8;
            break;
        case 512:
            mult = 9;
            break;
        default:
            mult = 0;
    }
    if(mult) {
        for(i = 0; i < checkVal; i++)
        for(j = 0; j < checkVal; j++) {
            addr = ((i << (mult - 1))) + j;
            ridx = ((i << 1) << mult) + (j << 1);
            val1 = val2 = val3 = 0;

            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx = ridx - 1 + dim;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            val1 >>= 2;
            val2 >>= 2;
            val3 >>= 2;

            dst[addr].red = val1;
            dst[addr].green = val2;
            dst[addr].blue = val3;
        }
    }
    else {
        for(i = 0; i < checkVal; i++)
        for(j = 0; j < checkVal; j++) {
            addr = RIDX(i, j, checkVal);
            ridx = RIDX(i << 1, j << 1, dim);
            val1 = val2 = val3 = 0;

            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx = ridx - 1 + dim;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            ridx++;
            val1 += src[ridx].red;
            val2 += src[ridx].green;
            val3 += src[ridx].blue;

            val1 >>= 2;
            val2 >>= 2;
            val3 >>= 2;

            dst[addr].red = val1;
            dst[addr].green = val2;
            dst[addr].blue = val3;
        }
    }
}

/******************************************************************************
 * register_average_pooling_functions - Register all of your different versions
 *     of the average pooling  with the driver by calling the
 *     add_average_pooling_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 ******************************************************************************/

void register_average_pooling_functions() {
    add_average_pooling_function(&naive_average_pooling, naive_average_pooling_descr);
    add_average_pooling_function(&average_pooling, average_pooling_descr);
    //add_average_pooling_function(&test_pooling, test_pooling_descr);
    //add_average_pooling_function(&test2_pooling, test2_pooling_descr);
    /* ... Register additional test functions here */
}

