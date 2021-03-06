/*
* Copyright (C) 1998, 2000-2007, 2010, 2011, 2012, 2013 SINTEF ICT,
* Applied Mathematics, Norway.
*
* Contact information: E-mail: tor.dokken@sintef.no                      
* SINTEF ICT, Department of Applied Mathematics,                         
* P.O. Box 124 Blindern,                                                 
* 0314 Oslo, Norway.                                                     
*
* This file is part of GoTools.
*
* GoTools is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version. 
*
* GoTools is distributed in the hope that it will be useful,        
* but WITHOUT ANY WARRANTY; without even the implied warranty of         
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public
* License along with GoTools. If not, see
* <http://www.gnu.org/licenses/>.
*
* In accordance with Section 7(b) of the GNU Affero General Public
* License, a covered work must retain the producer line in every data
* file that is created or manipulated using GoTools.
*
* Other Usage
* You can be released from the requirements of the license by purchasing
* a commercial license. Buying such a license is mandatory as soon as you
* develop commercial activities involving the GoTools library without
* disclosing the source code of your own applications.
*
* This file may be used in accordance with the terms contained in a
* written agreement between you and SINTEF ICT. 
*/

#include "GoTools/geometry/GoTools.h"
#include "GoTools/geometry/ObjectHeader.h"
#include "GoTools/geometry/BoundedSurface.h"
#include <fstream>
#include <iostream>
#include "time.h"

using namespace Go;
using std::vector;

int main(int argc, char** argv)
{
    if ((argc < 2) || (argc > 3))
    {
      std::cout << "Usage: spline_sf.g2 (tol)" << std::endl;
      return -1;
    }

  GoTools::init();

  std::ifstream infile(argv[1]);
  double tol = 1e-6;
  if (argc == 3)
      tol = atof(argv[2]);

  double ti;
  double area;

  GoTools::init();

  ObjectHeader head;
  head.read(infile);
  if (head.classType() == SplineSurface::classType())
    {
      shared_ptr<SplineSurface> surf(new SplineSurface());
      surf->read(infile);

      ti = -(double)clock();
      area = surf->area(tol);
      ti += (double)clock();
    }
  else if (head.classType() == BoundedSurface::classType())
    {
      shared_ptr<BoundedSurface> surf(new BoundedSurface());
      surf->read(infile);

      ti = -(double)clock();
      area = surf->area(tol);
      ti += (double)clock();

      shared_ptr<ParamSurface> underlying_sf = surf->underlyingSurface();
      double area_underlying = underlying_sf->area(tol);
      std::cout << "Surface area underlying: " << area_underlying << std::endl;
    }
  else
    THROW("Not a spline surface");

  std::cout << "Time used is " << double(ti)/1000.0 << " ms" << std::endl;
  std::cout << std::setprecision(20);
  std::cout << "Estimated area is " << area << std::endl;

}
