/*****************************************************************************/
/*                                                                           */
/*                                                                           */
/* (c) Copyright 1997 by                                                     */
/*     SINTEF, Oslo, Norway.                                                 */
/*     All rights reserved. See the copyright.h for more details.            */
/*                                                                           */
/*****************************************************************************/

#ifndef PRFABER_F_H
#define PRFABER_F_H

#include "GoTools/parametrization/PrFilterbank.h"

/*<PrFaber_F-syntax: */

/** - Implements algorithms for composing and decomposing piecewise
 * linear functions over nested triangulations, using Faber decomposition.
 * For a comparison with prewavelets, see
       
                   M. S. Floater, E. G. Quak and M. Reimers,
                   Filter Bank Algorithms for Piecewise Linear
                   Prewavelets on Arbitrary Triangulations,
                   J. Comp. Appl. Math. \e 119 (2000), 185--207.
*/

class PrFaber_F : public PrFilterbank
{
private:

public:
  /// Constructor
  PrFaber_F() {}
  /// Destructor
  virtual ~PrFaber_F() {};

  // derived from base class...
                   
  /** The nodes in the triangulation belonging to \f$V^j\f$
   * form a piecewise linear function \f$f^j\f$ in the space \f$S^j\f$
   * (where j = level).
   * This routines decomposes \f$f^j\f$
   * into \f$f^{j-1} + g^{j-1}\f$ where
   * \f$f^{j-1} \in S^{j-1}\f$ and \f$g^{j-1} \in W^{j-1}\f$.
   * Use dim = 1 for explicit triangulations and
   * dim = 3 for non-explicit. Default is dim = 1.
   */
  virtual void       decompose(int jlev, int dim = 1);
                       // 1 <= jlev <= finest level

  /** The nodes in the triangulation belonging to \f$V^j\f$
   * form a piecewise linear function \f$f^j\f$ in the space \f$S^j\f$.
   * This routines composes \f$f^j\f$
   * from \f$f^{j-1}\f$ + \f$g^{j-1}\f$ where
   * \f$f^{j-1} \in S^{j-1}\f$ and \f$g^{j-1} \in W^{j-1}\f$.
   * Use dim = 1 for explicit triangulations and
   * dim = 3 for non-explicit. Default is dim = 1.
   */
  virtual void       compose(int jlev, int dim = 1);
                       // 1 <= jlev <= finest level

};

/*>PrFaber_F-syntax: */

/*Class:PrFaber_F

Name:              PrFaber_F
Syntax:	           @PrFaber_F-syntax
Keywords:
Description:       This class implements algorithms for decomposing
                   and decomposing piecewise linear functions over nested
                   triangulations, using Faber decomposition.
                   For a comparison with prewavelets, see
       
                   M. S. Floater, E. G. Quak and M. Reimers,
                   Filter Bank Algorithms for Piecewise Linear
                   Prewavelets on Arbitrary Triangulations,
                   J. Comp. Appl. Math. {\bf 119} (2000), 185--207.

Member functions:
                   "decompose(int level, int dim)" --\\
                   The nodes in the triangulation belonging to V^j
                   form a piecewise linear function f^j in the space S^j
                   (where j = level).
                   This routines decomposes f^j
                   into f^{j-1} + g^{j-1} where
                   f^{j-1} \in S^{j-1} and g^{j-1} \in W^{j-1}.
                   Use dim = 1 for explicit triangulations and
                   dim = 3 for non-explicit. Default is dim = 1.
                   
                   "compose(int level, int dim)" --\\
                   The nodes in the triangulation belonging to V^j
                   form a piecewise linear function f^j in the space S^j.
                   This routines composes f^j
                   from f^{j-1} + g^{j-1} where
                   f^{j-1} \in S^{j-1} and g^{j-1} \in W^{j-1}.
                   Use dim = 1 for explicit triangulations and
                   dim = 3 for non-explicit. Default is dim = 1.
                   
Constructors:
Files:
Example:

See also:
Developed by:      SINTEF Applied Mathematics, Oslo, Norway
Author:	           Michael Floater, SINTEF
Date:              Dec. 98
*/

#endif // PRFABER_F_H
