/* This file is part of OpenMalaria.
 * 
 * Copyright (C) 2005-2013 Swiss Tropical and Public Health Institute 
 * Copyright (C) 2005-2013 Liverpool School Of Tropical Medicine
 * 
 * OpenMalaria is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "WithinHost/Diagnostic.h"
#include "util/random.h"
#include "util/errors.h"

namespace OM { namespace WithinHost {

Diagnostic Diagnostic::default_;

void Diagnostic::setDeterministic(double limit){
    assert( density != density );       // multiple initialisations
    specificity = numeric_limits<double>::quiet_NaN();
    density = limit;
}

void Diagnostic::setXml( const scnXml::HSDiagnostic& elt ){
    if( elt.getDeterministic().present() ){
        specificity = numeric_limits<double>::quiet_NaN();
        density = elt.getDeterministic().get().getMinDensity();
    }else if( elt.getStochastic().present() ){
        specificity = elt.getStochastic().get().getSpecificity();
        density = elt.getStochastic().get().getDens_50();
    }else{
        // This should be impossible since according to schema one of these
        // elements must be present.
        assert(false);
    }
}

bool Diagnostic::isPositive( double x ) const {
    if( specificity != specificity ){	// is NaN
        // use deterministic test
        return x >= density;
    }else{
        double pPositive = 1.0 + specificity * (x / (x + density) - 1.0);
        return util::random::bernoulli( pPositive );
    }
}

} }
