#include "config-f90.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// most of the file is not compiled if not using MPI
#ifdef WITH_MPI
#include <mpi.h>

int numroc_(int*, int*, int*, int*, int*);

//***********************************************************************************************************

#define REALCASE 1
#define DOUBLE_PRECISION 1
#include "../general/precision_macros.h"
#include "cannon_forw_template.c"
#include "cannon_back_template.c"
#undef DOUBLE_PRECISION
#undef REALCASE

/*
!f> interface
!f>   subroutine cannons_reduction_d(A, U, local_rows, local_cols, a_desc, Res, toStore, row_comm, col_comm) &
!f>                             bind(C, name="cannons_reduction_c_d")
!f>     use, intrinsic :: iso_c_binding
!f>     real(c_double)                        :: A(local_rows, local_cols), U(local_rows, local_cols), Res(local_rows, local_cols)
!f>     !type(c_ptr), value                   :: A, U, Res
!f>     integer(kind=c_int)                   :: a_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value     ::  row_comm, col_comm, ToStore
!f>   end subroutine
!f> end interface
*/
void cannons_reduction_c_d(double* A, double* U, int local_rows, int local_cols, int* a_desc,
                         double *Res, int ToStore, int row_comm, int col_comm);

/*
!f> interface
!f>   subroutine cannons_triang_rectangular_d(U, B, local_rows, local_cols, u_desc, b_desc, Res, row_comm, col_comm) &
!f>                             bind(C, name="cannons_triang_rectangular_c_d")
!f>     use, intrinsic :: iso_c_binding
!f>     real(c_double)                        :: U(local_rows, local_cols), B(local_rows, local_cols), Res(local_rows, local_cols)
!f>     integer(kind=c_int)                   :: u_desc(9), b_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value             :: row_comm, col_comm
!f>   end subroutine
!f> end interface
*/
void cannons_triang_rectangular_c_d(double* U, double* B, int local_rows, int local_cols,
                                    int* u_desc, int* b_desc, double *Res, int row_comm, int col_comm);

//***********************************************************************************************************

#define REALCASE 1
#define SINGLE_PRECISION 1
#include "../general/precision_macros.h"
#include "cannon_forw_template.c"
#include "cannon_back_template.c"
#undef SINGLE_PRECISION
#undef REALCASE

/*
!f> interface
!f>   subroutine cannons_reduction_f(A, U, local_rows, local_cols, a_desc, Res, toStore, row_comm, col_comm) &
!f>                             bind(C, name="cannons_reduction_c_f")
!f>     use, intrinsic :: iso_c_binding
!f>     real(c_float)                        :: A(local_rows, local_cols), U(local_rows, local_cols), Res(local_rows, local_cols)
!f>     !type(c_ptr), value                   :: A, U, Res
!f>     integer(kind=c_int)                   :: a_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value     ::  row_comm, col_comm, ToStore
!f>   end subroutine
!f> end interface
*/
void cannons_reduction_c_f(float* A, float* U, int local_rows, int local_cols, int* a_desc,
                         float *Res, int ToStore, int row_comm, int col_comm);

/*
!f> interface
!f>   subroutine cannons_triang_rectangular_f(U, B, local_rows, local_cols, u_desc, b_desc, Res, row_comm, col_comm) &
!f>                             bind(C, name="cannons_triang_rectangular_c_f")
!f>     use, intrinsic :: iso_c_binding
!f>     real(c_float)                        :: U(local_rows, local_cols), B(local_rows, local_cols), Res(local_rows, local_cols)
!f>     integer(kind=c_int)                   :: u_desc(9), b_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value             :: row_comm, col_comm
!f>   end subroutine
!f> end interface
*/
void cannons_triang_rectangular_c_f(float* U, float* B, int local_rows, int local_cols,
                                    int* u_desc, int* b_desc, float *Res, int row_comm, int col_comm);

//***********************************************************************************************************

#define COMPLEXCASE 1
#define DOUBLE_PRECISION 1
#include "../general/precision_macros.h"
#include "cannon_forw_template.c"
#include "cannon_back_template.c"
#undef DOUBLE_PRECISION
#undef COMPLEXCASE

/*
!f> interface
!f>   subroutine cannons_reduction_dc(A, U, local_rows, local_cols, a_desc, Res, toStore, row_comm, col_comm) &
!f>                             bind(C, name="cannons_reduction_c_dc")
!f>     use, intrinsic :: iso_c_binding
!f>     complex(c_double)                     :: A(local_rows, local_cols), U(local_rows, local_cols), Res(local_rows, local_cols)
!f>     !type(c_ptr), value                   :: A, U, Res
!f>     integer(kind=c_int)                   :: a_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value     ::  row_comm, col_comm, ToStore
!f>   end subroutine
!f> end interface
*/
void cannons_reduction_c_dc(double complex* A, double complex* U, int local_rows, int local_cols, int* a_desc,
                         double complex *Res, int ToStore, int row_comm, int col_comm);

/*
!f> interface
!f>   subroutine cannons_triang_rectangular_dc(U, B, local_rows, local_cols, u_desc, b_desc, Res, row_comm, col_comm) &
!f>                             bind(C, name="cannons_triang_rectangular_c_dc")
!f>     use, intrinsic :: iso_c_binding
!f>     complex(c_double)                        :: U(local_rows, local_cols), B(local_rows, local_cols), Res(local_rows, local_cols)
!f>     integer(kind=c_int)                   :: u_desc(9), b_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value             :: row_comm, col_comm
!f>   end subroutine
!f> end interface
*/
void cannons_triang_rectangular_c_dc(double complex* U, double complex* B, int local_rows, int local_cols,
                                    int* u_desc, int* b_desc, double complex *Res, int row_comm, int col_comm);
//***********************************************************************************************************

#define COMPLEXCASE 1
#define SINGLE_PRECISION 1
#include "../general/precision_macros.h"
#include "cannon_forw_template.c"
#include "cannon_back_template.c"
#undef SINGLE_PRECISION
#undef COMPLEXCASE

/*
!f> interface
!f>   subroutine cannons_reduction_fc(A, U, local_rows, local_cols, a_desc, Res, toStore, row_comm, col_comm) &
!f>                             bind(C, name="cannons_reduction_c_fc")
!f>     use, intrinsic :: iso_c_binding
!f>     complex(c_float)                      :: A(local_rows, local_cols), U(local_rows, local_cols), Res(local_rows, local_cols)
!f>     !type(c_ptr), value                   :: A, U, Res
!f>     integer(kind=c_int)                   :: a_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value     ::  row_comm, col_comm, ToStore
!f>   end subroutine
!f> end interface
*/
void cannons_reduction_c_fc(float complex* A, float complex* U, int local_rows, int local_cols, int* a_desc,
                         float complex *Res, int ToStore, int row_comm, int col_comm);

/*
!f> interface
!f>   subroutine cannons_triang_rectangular_fc(U, B, local_rows, local_cols, u_desc, b_desc, Res, row_comm, col_comm) &
!f>                             bind(C, name="cannons_triang_rectangular_c_fc")
!f>     use, intrinsic :: iso_c_binding
!f>     complex(c_float)                      :: U(local_rows, local_cols), B(local_rows, local_cols), Res(local_rows, local_cols)
!f>     integer(kind=c_int)                   :: u_desc(9), b_desc(9)
!f>     integer(kind=c_int),value             :: local_rows, local_cols
!f>     integer(kind=c_int),value             :: row_comm, col_comm
!f>   end subroutine
!f> end interface
*/
void cannons_triang_rectangular_c_fc(float complex* U, float complex* B, int local_rows, int local_cols,
                                    int* u_desc, int* b_desc, float complex *Res, int row_comm, int col_comm);
#endif