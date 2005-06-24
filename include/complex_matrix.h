/* $Id: complex_matrix.h,v 1.1 2005-06-22 07:11:20 acs Exp $
   Written by Adam Siepel, Summer 2005
   Copyright 2005, Adam Siepel, University of California
*/

/** \file complex.h
    Matrices of complex numbers
    \ingroup base
*/

#ifndef ZMAT_H
#define ZMAT_H

#include <complex.h>
#include <complex_vector.h>

/** Structure for matrix of complex numbers -- 2d array of Complex
    objects and its dimensions */
typedef struct {
  Complex **data;
  int nrows;
  int ncols;
} Zmatrix;

Zmatrix *zmat_new(int nrows, int ncols);
void zmat_free(Zmatrix *m);
Complex zmat_get(Zmatrix *m, int row, int col);
Zvector *zmat_get_row(Zmatrix *m, int row);
Zvector *zmat_get_col(Zmatrix *m, int col);
void zmat_set(Zmatrix *m, int row, int col, Complex val);
void zmat_set_identity(Zmatrix *m);
void zmat_zero(Zmatrix *m);
void zmat_set_all(Zmatrix *m, Complex val);
void zmat_copy(Zmatrix *dest, Zmatrix *src);
Zmatrix *zmat_create_copy(Zmatrix *src);
void zmat_scale(Zmatrix *m, double scale_factor);
void zmat_print(Zmatrix *m, FILE *F);
void zmat_read(Zmatrix *m, FILE *F);
Zmatrix *zmat_new_from_file(FILE *F, int nrows, int ncols);
void zmat_mult(Zmatrix *prod, Zmatrix *m1, Zmatrix *m2);
void zmat_vec_mult(Zvector *prod, Zmatrix *m, Zvector *v);
void zmat_mult_real(Matrix *prod, Zmatrix *m1, Zmatrix *m2);
void zmat_plus_eq(Zmatrix *thism, Zmatrix *addm);
void zmat_minus_eq(Zmatrix *thism, Zmatrix *subm);

#endif