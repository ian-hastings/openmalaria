/* This file is part of OpenMalaria.
 * 
 * Copyright (C) 2005-2014 Swiss Tropical and Public Health Institute
 * Copyright (C) 2005-2014 Liverpool School Of Tropical Medicine
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


#ifndef MULTITEX_HELPER_H
#define MULTITEX_HELPER_H

typedef enum
{
	PLAIN, NORMAL_MAPPED, AMBIENT, DIFFUSE, SUNRISE, 
	SUNSET, SHADOWS, HAZE, SKY, SUN, GLOW, NORMALS,
	HAZE_ON_SKY, STARS, MOON, MOON_SHADOW, AFTERGLOW,
	PRE_RENDERED
}
CubeMode;

class SkyBox;

class MultiTextureHelper
{
	public: 
		
		MultiTextureHelper(SkyBox* skyBox);

		SkyBox* skyBox;
		float alphaClamp;

		void setUp(CubeMode mode);
		void reset();
};


#endif
