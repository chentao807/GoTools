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

#include "GoTools/geometry/SplineCurve.h"
#include "GoTools/geometry/SplineSurface.h"
#include "GoTools/geometry/ObjectHeader.h"
#include <fstream>

using namespace std;
using namespace Go;


int main(int argc, char** argv)
{
    ASSERT(argc >= 2);
    ifstream file(argv[1]);
    ObjectHeader head;
    SplineSurface sf;
    SplineCurve cv;
    file >> head;
    if (head.classType() == SplineSurface::classType()) { 
	file >> sf;
    } else if (head.classType() == SplineCurve::classType()) {
	file >> cv;
    } else {
	THROW("Unrecognized object type.");
    }
    
    double x, y, z;
    cin >> x >> y >> z;
    Point p(x, y, z);
    double clo_u;
    double clo_v;
    Point clo_pt(3);
    double clo_dist;
    double epsilon = 1e-8;

    if (head.classType() == SplineSurface::classType()) {
	sf.closestPoint(p, clo_u, clo_v, clo_pt, clo_dist, epsilon);
    } else { // curve
	cv.closestPoint(p, cv.startparam(), cv.endparam(), clo_u, clo_pt, clo_dist);
    }

    cout << clo_pt << endl;
}










