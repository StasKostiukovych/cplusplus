#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>


typedef struct {
    int rows;
    int cols;
    double* data;
} matrix;



typedef struct {
    int n;
    double* data;
} vector;





/* Creates a ``rows by cols'' matrix with all values 0.
 * Returns NULL if rows <= 0 or cols <= 0 and otherwise a
 * pointer to the new matrix.
 */


#define ELEM(mtx, row, col) mtx->data[(col-1) * mtx->rows + (row-1)]

matrix * newMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;

    // allocate a matrix structure
    matrix * m = (matrix *) malloc(sizeof(matrix));

    // set dimensions
    m->rows = rows;
    m->cols = cols;

    // allocate a double array of length rows * cols
    m->data = (double *) malloc(rows*cols*sizeof(double));
    // set all data to 0
    int i;
    for (i = 0; i < rows*cols; i++)
        m->data[i] = 0.0;
    return m;
}

matrix * copyMatrix(matrix * mtx) {
    if (!mtx) return NULL;

    // create a new matrix to hold the copy
    matrix * cp = newMatrix(mtx->rows, mtx->cols);

    for (int row = 1; row <= mtx->rows; row++)
        for (int col = 1; col <= mtx->cols; col++)
            ELEM(cp, col, row) = ELEM(mtx, col, row);

    return cp;
}

/* Deletes a matrix.  Returns 0 if successful and -1 if mtx
 * is NULL.
 */
int deleteMatrix(matrix * mtx) {
    if (!mtx) return -1;
    free(mtx->data);
    free(mtx);
    return 0;
}



int setElement(matrix * mtx, int row, int col, double val)
{
    if (!mtx) return -1;
    if (row <= 0 || row > mtx->rows ||
        col <= 0 || col > mtx->cols)
        return -2;

    ELEM(mtx, row, col) = val;
    return 0;
}



/* Prints the matrix to stdout.  Returns 0 if successful
 * and -1 if mtx is NULL.
 */
int printMatrix(matrix * mtx) {
    if (!mtx) return -1;

    int row, col;
    for (row = 1; row <= mtx->rows; row++) {
        for (col = 1; col <= mtx->cols; col++) {
            // Print the floating-point element with
            //  - either a - if negative or a space if positive
            //  - at least 3 spaces before the .
            //  - precision to the hundredths place
            printf("|% 6.2f |", ELEM(mtx, row, col));
        }
        // separate rows by newlines
        printf("\n");
    }
    return 0;
}


/* Writes the product of matrices mtx1 and mtx2 into matrix
 * prod.  Returns 0 if successful, -1 if any of the
 * matrices are NULL, and -2 if the dimensions of the
 * matrices are incompatible.
 */
int product(matrix * mtx1, matrix * mtx2, matrix * prod) {
    if (!mtx1 || !mtx2 || !prod) return -1;
    if (mtx1->cols != mtx2->rows ||
        mtx1->rows != prod->rows ||
        mtx2->cols != prod->cols)
        return -2;

    int row, col, k;
    for (col = 1; col <= mtx2->cols; col++)
        for (row = 1; row <= mtx1->rows; row++) {
            double val = 0.0;
            for (k = 1; k <= mtx1->cols; k++)
                val += ELEM(mtx1, row, k) * ELEM(mtx2, k, col);
            ELEM(prod, row, col) = val;
        }
    return 0;
}


void swap(double *a, double *b)
{
    double t;
    t  = *b;
    *b = *a;
    *a = t;
}


void transpose(matrix * in) {

    for (int row = 1; row <= in->rows; row++) {
        for (int col = 1; col <= in->cols; col++) {
            if (row < col) {
                swap(&ELEM(in, col, row), &ELEM(in, row, col));
            }
        }
    }

}



void swap_columns(matrix * in, int col1, int col2){

    for (int row = 1; row <= in->rows; row++){
        swap(&ELEM(in, row, col1), &ELEM(in, row, col2));
    }
}

void swap_rows(matrix * in, int row1, int row2){

    for (int col = 1; col <= in->cols; col++){
        swap(&ELEM(in, row1, col), &ELEM(in, row2, col));
    }

}

double det(matrix * in) {
    double det = 1;
    int oper = 1;

    if (in->cols != in->rows)
        return 0.0;

    for (int i=1; i <= in->rows; i++) {
        for (int k = i+1; k<= in->cols; k++){
            if (fabs(ELEM(in, i, i)) < fabs(ELEM(in, k, i))){
                for (int j=1; j <= in->cols; j++){
                    double templ = ELEM(in, i, j);
                    ELEM(in, i, j) = ELEM(in, k, j);
                    ELEM(in, k, j) = templ;
                    oper *= -1;
                }
            }

        }
    }

    for (int i=1; i <= in->rows; i++) {
        for (int j = i+1; j <= in->cols; j++) {
            double koef = -ELEM(in, j, i) / ELEM(in, i, i);
            for (int k=i; k <= in->cols; k++){
                ELEM(in, j, k) += ELEM(in, i, k) * koef;
            }
        }
        det *= ELEM(in, i, i);
    }

    det *= oper;

    return det;
}



matrix *GetMinor(matrix *src, int row, int col)
{


    matrix *dest = newMatrix(src->rows-1, src->cols-1);
    // indicate which col and row is being copied to dest

    int colCount = 1,rowCount = 1;
    int i,j;

    for(i = 1; i <= src->rows; i++ ){
        if( i != row )
        {
            colCount = 1;
            for( j = 1; j <= src->cols; j++ )
            {
                // when j is not the element
                if( j != col )
                {
                    ELEM(dest, rowCount, colCount) = ELEM(src, i,j);
                    colCount++;
                }
            }
            rowCount++;
        }
    }
    return dest;
}



void inverse(matrix *in){

    matrix *out = newMatrix(in->rows, in->cols);

    int sign = 1;
    for (int i=1; i <= in->cols; i++){
        for (int j=1; j <= in->rows; j++){
            sign = ((i+j)%2==0)? 1: -1;
            ELEM(out, i, j) = det(GetMinor(in, i, j)) * sign;
        }
    }

    transpose(out);

    for (int i=1; i <= in->cols; i++){
        for (int j=1; j <= in->rows; j++) {
            ELEM(out, i, j) *= 1/det(in);
        }
    }

    printMatrix(out);

    
}




int main() {
    matrix *A;
    int n =3, m=3;
//    double num=0;
//    printf("Enter n: ");
//    scanf("%d", &n);
//
//    printf("Enter m: ");
//    scanf("%d", &m);
//
    A = newMatrix(n, m);
//
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            printf("Matrix[%i][%i]: ", i, j);
//            scanf("%lf", &num);
//            setElement(A, i, j, num);
//        }
//    }

    setElement(A, 1, 1, -3);
    setElement(A, 1, 2, 2);
    setElement(A, 1, 3, -5);
    setElement(A, 2, 1, -1);
    setElement(A, 2, 2, 0);
    setElement(A, 2, 3, -2);
    setElement(A, 3, 1, 3);
    setElement(A, 3, 2, -4);
    setElement(A, 3, 3, 1);

    printf("Matrix A:\n");
    printMatrix(A);


    printf("\n");
    inverse(A);
//    matrix *B = newMatrix(2,2);
//    GetMinor(A,B, 1,1);
//    printMatrix(B);

//    getCofactor(A, 1,2);
//    adjoint(A);
//    transpose(A);

//    printf("%lf", det(A));

//    swap_columns(A, 1, 2);
//    printMatrix(A);


    deleteMatrix(A);

}
