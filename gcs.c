#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* function for geting max of 2 integers */
int get_max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

void print_gcs(int **L, char* X, char * Y, int i, int j, char* gcs, int indice);


int gcs(char* sequence, int sequence_count) 
{ 	
    //Create random sequence 
    int i, j;
    srand(time(NULL));
    int m = rand() % 100; 
    int n = m;
    char* X = (char*)malloc(m);
    char* Y = (char*)malloc(m);
    int random_index = 0;
    for(j = 0; j < m; j++) {
        random_index = rand() % sequence_count; 
        X[j] = sequence[random_index];
        Y[j] = X[j];
    }
    //Mutation
    double percentage = 0.7;   //percentage should be less than 1, because it shouldn't bigger than 1  
    for(j = 0; j < (int)(m * percentage); j++) {
        random_index = rand() % sequence_count;
        Y[j] = sequence[random_index];
    }
    int** L = (int**)malloc(sizeof(int*)*(m + 1));
    //fill matrix and compare two sequences 
    for (i = 0; i <= m; i++) 
    {
        L[i] = (int*)malloc(sizeof(int)*(n + 1));
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 

            else
                L[i][j] = get_max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    
    int indice = L[m][n] - 1;
    char* gcs = (char*)malloc(indice);

    i = m;
    j = n;

    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\nSecuencia 1: \n \t   %s \n", X);
    printf("\nSecuencia 2: \n \t   %s \n", Y);
    print_gcs(L, X, Y, i, j, gcs, indice);
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n*******\n \t gcs: %s\n*******\n \n", gcs);
    
    return 0;
} 

void print_gcs(int **L, char* X, char * Y, int i, int j, char* gcs, int indice){
    if ( i == 0 || j == 0){
        return;
    } else if (X[i-1] == Y[j-1]){
        gcs[indice] = X[i-1];
        i-=1;
        j-=1;
        indice-=1;
    }
    else if(L[i-1][j] > L[i][j-1]){
        i-=1;
    } else{
        j-=1;
    }
    print_gcs(L, X, Y, i, j, gcs, indice);
}

