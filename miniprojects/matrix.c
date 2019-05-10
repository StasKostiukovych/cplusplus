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


vector * newVector(int num) {
    if (num <= 0) return NULL;

    // allocate a vector structure
    vector* v = (vector *)malloc(sizeof(vector));

    // set size
    v->n = num;

    // allocate a double array of size
    v->data = (double *) malloc(num*sizeof(double));
    // set all data to 0
    for (int i = 0; i < num; i++)
        v->data[i] = 0.0;
    return v;
}

void setVector(vector *vec, int size){
    int i=0;
    double num=0;
    for (i = 0; i < size; i++) {
        printf("Vector[%i]: ", i + 1);
        scanf("%lf", &num);
        vec->data[i] = num;
    }
}


void printVector(vector *vec){
    for (int i =0; i < vec->n; i++){
        printf("| %lf |", vec->data[i]);
    }

}


int deleteVector(vector * v) {
    if (!v) return -1;
    free(v->data);
    free(v);
    return 0;
}


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

void setMatrixString(matrix* A, int n, int m){
    double num =0;

    printf("Enter the elements of matrix: \n");
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) {
            scanf("%lf", &num);
            setElement(A, i, j, num);
        }
    }

}


void setMatrixByCoefficients(matrix* A,int  n,int m){
    double num=0;

    printf("Enter the elements of matrix: \n");
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            printf("Matrix[%i][%i]: ", i, j);
            scanf("%lf", &num);
            setElement(A, i, j, num);
        }
    }
}



/* Prints the matrix to stdout.  Returns 0 if successful
 * and -1 if mtx is NULL.
 */
int printMatrix(matrix * mtx) {
    if (!mtx) return -1;

    int row, col;
    for (row = 1; row <= mtx->rows; row++) {
        for (col = 1; col <= mtx->cols; col++) {

            // not printing minus zero
            if (ELEM(mtx, row, col) == 0) {
                ELEM(mtx, row, col) = 0;
            }
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
int multiply_by_matrix(matrix * mtx1, matrix * mtx2, matrix * prod) {
    if (!mtx1 || !mtx2 || !prod) return -1;
    if (mtx1->cols != mtx2->rows ||
        mtx1->rows != prod->rows ||
        mtx2->cols != prod->cols)
        return -2;

    int k;
    for (int col = 1; col <= mtx2->cols; col++)
        for (int row = 1; row <= mtx1->rows; row++) {
            double val = 0.0;
            for (k = 1; k <= mtx1->cols; k++)
                val += ELEM(mtx1, row, k) * ELEM(mtx2, k, col);
            ELEM(prod, row, col) = val;
        }
    return 0;
}


int multiply_by_vector(matrix *mtx, vector*vec, vector * res) {
    if (!mtx || !vec || !res) return -1;
//    if (mtx->cols != prod->rows ||
//        mtx->rows != prod->rows ||
//        mtx->cols != vec->n )
//        return -2;
    for (int col = 1; col <= mtx->cols; col++)
        for (int row = 1; row <= mtx->rows; row++) {
            res->data[col - 1] += vec->data[col] * ELEM(mtx, row, col);
        }

    printVector(res);
}


void swap(double *a, double *b){
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
                for (int j=1; j <= in->cols; j++) {
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
            if (ELEM(in, i, i) != 0){
                double koef = -ELEM(in, j, i) / ELEM(in, i, i);
                for (int k=i; k <= in->cols; k++) {
                    ELEM(in, j, k) += ELEM(in, i, k) * koef;


                    oper = ((i + j) % 2 == 0) ? 1 : -1;
                }
            }
        }
        det *= ELEM(in, i, i);
    }

    det *= oper;
    return det;
}

void GetMinor(matrix *src,matrix *dest, int row, int col){

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
}

int inverse(matrix *in, matrix *out){

    if (det(in) == 0){
        return 0;
    }

    matrix *temp = newMatrix(in->rows-1, in->cols-1);


    int sign = 1;
    for (int i=1; i <= in->cols; i++){
        for (int j=1; j <= in->rows; j++){
            sign = ((i+j)%2==0)? 1: -1;
            GetMinor(in, temp, i, j);
            ELEM(out, i, j) = det(temp) * sign;

        }
    }
    deleteMatrix(temp);

    transpose(out);

    for (int i=1; i <= in->cols; i++){
        for (int j=1; j <= in->rows; j++) {
            ELEM(out, i, j) *= 1/det(in);
        }
    }
    return 1;
//    printMatrix(out);
}

void matrix_and_vector(matrix *mtx, matrix *temp, vector* ans){
    // combine it to one matrix temp
    for (int i=1; i<=mtx->rows; i++){
        for (int j=1; j<=mtx->cols; j++)
            ELEM(temp, i, j) = ELEM(mtx, i, j);
    }

    for (int i=1; i<=temp->rows; i++){
        ELEM(temp, i, temp->cols) = ans->data[i-1];
    }
}

int solve(matrix *mtx, vector*ans){

    if (mtx->cols!= mtx->rows){
        return -1;
    }

    if (mtx->rows != ans->n){
        return -1;
    }


    if (det(mtx) == 0){
        return 0;
    }

    matrix* temp = newMatrix(mtx->rows,mtx->cols+1);

    matrix_and_vector(mtx, temp, ans);

    for (int i=1; i <= temp->rows; i++) {
        for (int j = i+1; j <= temp->rows; j++) {
            double koef = -ELEM(temp, j, i) / ELEM(temp, i, i);
            for (int k=i; k <= temp->cols; k++) {
                ELEM(temp, j, k) += ELEM(temp, i, k) * koef;

            }
        }
    }

    for (int i = temp->rows ; i >= 1; i--) {
        for (int j = i - 1; j >= 1; j--) {
            double koef = -ELEM(temp, j, i) / ELEM(temp, i, i);
            for (int k = temp->cols; k >= i; k--) {
                ELEM(temp, j, k) += ELEM(temp, i, k) * koef;
            }
        }
    }

    for (int i = 1; i <= temp->rows; i++) {
        ans->data[i-1] = ELEM(temp, i, temp->cols) / ELEM(temp, i, i);
    }

    deleteMatrix(temp);
}

void test_swap(){
    matrix *A;
    int n =3, m=3;

    A = newMatrix(n, m);

    for (int i = 1 ; i<=n; i++)
        for (int j = 1 ; j<=m; j++){
            setElement(A, i, j, i*j);
        }

    printf("\nYour matrix: \n");
    printMatrix(A);

    swap_columns(A, 2, 3);

    printf("\nYour matrix with swaping 2 and 3 columns: \n");
    printMatrix(A);

    deleteMatrix(A);
}

void test_determinant(){
    matrix *A;
    int n =3, m=3;

    A = newMatrix(n, m);

    setElement(A, 1, 1, 1);
    setElement(A, 1, 2, 2);
    setElement(A, 1, 3, 3);
    setElement(A, 2, 1, 4);
    setElement(A, 2, 2, 5);
    setElement(A, 2, 3, 6);
    setElement(A, 3, 1, 1);
    setElement(A, 3, 2, 8);
    setElement(A, 3, 3, 1);

    printf("\nYour matrix: \n");
    printMatrix(A);

    printf("\nDeterminant: ");
    printf("%lf", det(A));

    deleteMatrix(A);

}

void test_inverse(){
    matrix *A, *B;
    int n =3, m=3;

    A = newMatrix(n, m);

    setElement(A, 1, 1, 1);
    setElement(A, 1, 2, 2);
    setElement(A, 1, 3, 3);
    setElement(A, 2, 1, 4);
    setElement(A, 2, 2, 5);
    setElement(A, 2, 3, 6);
    setElement(A, 3, 1, 1);
    setElement(A, 3, 2, 8);
    setElement(A, 3, 3, 1);

    printf("\nYour matrix: \n");
    printMatrix(A);

    printf("\nThe inverse matrix is: \n");
    B = newMatrix(n,m);
    inverse(A, B);
    printMatrix(B);

    deleteMatrix(A);
    deleteMatrix(B);
}

void test_solve(){
    matrix *A;
    vector *v;
    int n =3, m=3;

    A = newMatrix(n, m);

    setElement(A, 1, 1, 1);
    setElement(A, 1, 2, 2);
    setElement(A, 1, 3, 3);
    setElement(A, 2, 1, 4);
    setElement(A, 2, 2, 5);
    setElement(A, 2, 3, 6);
    setElement(A, 3, 1, 1);
    setElement(A, 3, 2, 8);
    setElement(A, 3, 3, 1);

    v = newVector(n);
    v->data[0] = 1;
    v->data[1] = 2;
    v->data[2] = 1;

    matrix* temp = newMatrix(A->rows,A->cols+1);

    matrix_and_vector(A, temp, v);
    printf("\nYour matrix: \n");
    printMatrix(temp);
    deleteMatrix(temp);

    printf("\nAnswer: \n");
    solve(A, v);

    printVector(v);

    deleteMatrix(A);
    deleteVector(v);
}

void test_input_string(){
    matrix *A;
    int n=0 ,m =0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    A = newMatrix(n, m);
    setMatrixString(A, n, m);
    printMatrix(A);
    deleteMatrix(A);
}

void test_input_coefficients(){
    matrix *A;
    int n=0 ,m =0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    A = newMatrix(n, m);
    setMatrixByCoefficients(A, n, m);
    printMatrix(A);
    deleteMatrix(A);
}


int writeMatrixtoFile(matrix* mtx, char filename[30]){
    FILE *f = fopen(filename, "w");

    if (!f)
        return -1;

    for (int i =1; i<= mtx->rows;i++){
        for (int j =1; j<= mtx->cols;j++){
            fprintf(f, "%lf\t", ELEM(mtx, i ,j));
        }
    fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}


void test_matrix_txt(){
    matrix *A;
    int n=0 ,m =0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    A = newMatrix(n, m);
    setMatrixByCoefficients(A, n, m);
    writeMatrixtoFile(A, "matrix.txt");

    deleteMatrix(A);
}

int main() {
    
}
