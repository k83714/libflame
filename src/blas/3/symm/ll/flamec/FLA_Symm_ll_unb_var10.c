/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

#ifdef FLA_ENABLE_NON_CRITICAL_CODE

FLA_Error FLA_Symm_ll_unb_var10( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, FLA_Obj beta, FLA_Obj C )
{
  FLA_Obj BL,    BR,       B0,  b1t,  B2;

  FLA_Obj CL,    CR,       C0,  c1t,  C2;

  FLA_Part_1x2( B,    &BL,  &BR,      0, FLA_RIGHT );

  FLA_Part_1x2( C,    &CL,  &CR,      0, FLA_RIGHT );

  while ( FLA_Obj_width( BR ) < FLA_Obj_width( B ) ){

    FLA_Repart_1x2_to_1x3( BL,  /**/ BR,        &B0, &b1t, /**/ &B2,
                           1, FLA_LEFT );

    FLA_Repart_1x2_to_1x3( CL,  /**/ CR,        &C0, &c1t, /**/ &C2,
                           1, FLA_LEFT );

    /*------------------------------------------------------------*/

    /* c1t = c1t + A * b1t */
    FLA_Symv_external( FLA_LOWER_TRIANGULAR, alpha, A, b1t, beta, c1t );

    /*------------------------------------------------------------*/

    FLA_Cont_with_1x3_to_1x2( &BL,  /**/ &BR,        B0, /**/ b1t, B2,
                              FLA_RIGHT );

    FLA_Cont_with_1x3_to_1x2( &CL,  /**/ &CR,        C0, /**/ c1t, C2,
                              FLA_RIGHT );

  }

  return FLA_SUCCESS;
}

#endif
