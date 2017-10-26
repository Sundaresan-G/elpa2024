#include <elpa/elpa_constants.h>

#define FORTRAN_CONSTANT(name, value, ...) \
        integer(kind=C_INT), parameter :: name = value !ELPA_C_DEFINE

! General constants
 ELPA_FOR_ALL_ERRORS(FORTRAN_CONSTANT)


! Solver constants
 ELPA_FOR_ALL_SOLVERS(FORTRAN_CONSTANT)
#undef ELPA_NUMBER_OF_SOLVERS
 FORTRAN_CONSTANT(ELPA_NUMBER_OF_SOLVERS, (0 ELPA_FOR_ALL_SOLVERS(ELPA_ENUM_SUM)))


! Real kernels
 ELPA_FOR_ALL_2STAGE_REAL_KERNELS_AND_DEFAULT(FORTRAN_CONSTANT)
#undef ELPA_2STAGE_NUMBER_OF_REAL_KERNELS
 FORTRAN_CONSTANT(ELPA_2STAGE_NUMBER_OF_REAL_KERNELS, & NEWLINE (0 ELPA_FOR_ALL_2STAGE_REAL_KERNELS(ELPA_ENUM_SUM)))


! Complex kernels
 ELPA_FOR_ALL_2STAGE_COMPLEX_KERNELS_AND_DEFAULT(FORTRAN_CONSTANT)
#undef ELPA_2STAGE_NUMBER_OF_COMPLEX_KERNELS
 FORTRAN_CONSTANT(ELPA_2STAGE_NUMBER_OF_COMPLEX_KERNELS, & NEWLINE (0 ELPA_FOR_ALL_2STAGE_COMPLEX_KERNELS(ELPA_ENUM_SUM)))


! Autotune
 ELPA_FOR_ALL_AUTOTUNE_LEVELS(FORTRAN_CONSTANT)
 ELPA_FOR_ALL_AUTOTUNE_DOMAINS(FORTRAN_CONSTANT)
