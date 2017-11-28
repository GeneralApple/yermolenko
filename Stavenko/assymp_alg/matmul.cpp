#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>


/**
 * @brief      Print matrix to stdin.
 *
 * @param      matrix  The matrix
 * @param[in]  size    The size of matrix
 */
void print_mat(double **matrix, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%lf \t", matrix[i][j]);
        printf("\n");
    }
}

/**
 * @brief      Creates a matrix of doubles on heap.
 *
 * @param[in]  size  The size of matrix to create
 *
 * @return     pointer to array of pointers to rows (2D pointer)
 */
double** create_matrix(int size){
    double **matrix = new double*[size];
    matrix[0] = new double[size * size];
    for(int i=1; i < size; ++i)
        matrix[i] = matrix[0] + i * size;

    return matrix;
}

/**
 * @brief      Fill a matrix with random values in-place.
 *
 * @param      matrix  matrix
 * @param[in]  size    The size of matrix
 */
void fill_rand(double** matrix, int size){
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            matrix[i][j] = (double)rand();
}

/**
 * @brief      Fill a matrix with zeros in place
 *
 * @param      matrix  The matrix
 * @param[in]  size    The size of matrix
 */
void fill_zero(double** matrix, int size){
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            matrix[i][j] = 0.;
}

/**
 * @brief      Multiply two matrices in place. Use OpenMP "paralell for"
 * to speed up computation/
 *
 * @param      a     first matrix
 * @param      b     second matrix
 * @param      c     result
 * @param[in]  size  The size
 *
 */
void matmul(double** a, double** b, double** c, int size){
    // using another pass route because of number allocation in memory
    // this way matrices are passed row-by-row, which allows better
    // cache optimization compared to row-by-column
    for(int i=0; i<size; i++){
        for(int k=0; k<size; k++){
            double r = a[i][k];
            for(int j=0; j<size; j++)
                c[i][j] += r * b[k][j];
        }
    };
}

int main(int argc, char **argv)
{
    int N;
    printf("%d\n", argc);

    // parse from command line
    if (argc == 2) {
        N = strtol(argv[1], NULL, 10);
        printf("Done.\nSize of matrix %d.\n", N);
    } else {
        N = 100;
        printf("Done.Size of matrix %d. (All default values).\n", N);
    };

    printf("Init matrices. ");
    // allocate memory for matrices and fill them with random values
    double **a = create_matrix(N); fill_rand(a, N);
    double **b = create_matrix(N); fill_rand(b, N);
    double **c = create_matrix(N); fill_zero(c, N);

    printf("Done.\nStart multiplication. \n");

    auto start = std::chrono::high_resolution_clock::now();
    // multiply in-place for c
    matmul(a, b, c, N);

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = finish-start;
    std::cout << "Elapsed time: " << diff.count() << " s\n";

    print_mat(a, N); printf("\n");
    print_mat(b, N); printf("\n");
    print_mat(c, N); printf("\n");

    return 0;
}
