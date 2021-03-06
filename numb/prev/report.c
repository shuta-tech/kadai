#include <stdio.h>
#include <math.h>

#define EPS 0.000000001

int gauss_judg(double Mat1[][9], int NUM)
{
    double Matrix[NUM][NUM];
    double amn = 0.0;

    for(int p = 0; p < NUM; p++){
        for(int q = 0; q < NUM; q++){
            if(p =! q){
                amn += Mat1[p][q];
            }else if(Mat1[p][p] <= amn){
                printf("Divergence");
                break;
            }else{
                return 1;
            }
        }
    }
}

double gauss_sei(double Matrix1[][9], double Matrix2[], int NUM)
{
    double Matrix[NUM], mat[NUM];
    double sum = 0.0, def = 0.0, dx = 0.0;
    int m = 0, jdg1 = 1;

   for(int l = 0; l < NUM; l++){
        Matrix[l] = 0;
    }

    do{
        m++;
        printf("[round %d] \n", m);
        for(int n = 0; n < NUM; n++){
           sum = 0.0;
            for(int o = 0; o < NUM; o++){
                if(o != n) sum += Matrix1[n][o] * Matrix[o];
            } 
            sum = (Matrix2[n] - sum) / Matrix1[n][n];
            dx = fabs(Matrix[n] - sum);
            Matrix[n] = sum;
            printf("x[%d] = %lf ",n + 1,  sum);

            if(dx < EPS * fabs(Matrix[n])){
                jdg1 = 0;
            }else if(m >= 500){
                printf("Divergence\n");
                break;
            }   
        }  
        printf("\n");
    }while(jdg1 == 1);
}

int main(void)
{
    int num = 0;
    double matrix1[9][9], matrix2[9];
    FILE *fp;

    fp = fopen("matrix.txt", "r");
    fscanf(fp, "%d", &num);

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            fscanf(fp, "%lf", &matrix1[i][j]);
        }
    }

    for(int l = 0; l < num; l++){
        fscanf(fp, "%lf", &matrix2[l]);
    }

    fclose(fp);

    gauss_judg(matrix1, num);
    gauss_sei(matrix1, matrix2, num);
    
    return 0;
}