#ifndef _MColor
#define _MColor
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MColor
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MColor)
//
// This class provides a type used to get/set values of color attributes in
// dependency nodes.  It represents colors as an RGB triple.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MIOStreamFwd.h>

// *****************************************************************************

// CLASS DECLARATION (MColor)

/// A color math class. (OpenMaya) (OpenMaya.py)
/**
    This class is used to store values of color-related dependency graph node
    attributes.
*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MColor  
{
public:
	///
	enum MColorType {
		///
		kRGB,
		///
		kHSV,
		///
		kCMY,
		///
		kCMYK
	};

	///
					MColor();
	///
					MColor( const MColor& src);
	///
					MColor( float rr, float gg, float bb=0.0, float aa=1.0 );
	///
					MColor( const float d[3] );
	///
					MColor( float alpha );
	///
					MColor( MColorType colorModel,
							unsigned char c1, unsigned char c2, unsigned char c3,
							unsigned char alpha=255U );
	///
					MColor( MColorType colorModel,
							unsigned short c1, unsigned short c2, unsigned short c3,
							unsigned short alpha=65535U );
	///
					MColor( MColorType colorModel, float c1, float c2, float c3,
							float alpha=1.0 );
	///
					MColor( MColorType colorModel, double c1, double c2, double c3,
							double alpha=1.0 );

	///
					~MColor();
	///
 	MColor&		    operator= ( const MColor& src );
	///
 	float   		operator()( unsigned int i ) const;
	///
	float			operator[]( unsigned int i )const;
	///
 	MColor&   		operator/=( float scalar );
	///
 	MColor     	    operator/( float scalar ) const;
	///
 	MColor& 		operator*=( float scalar );
	///
 	MColor   		operator*( float scalar ) const;
	///
 	MColor   		operator+( const MColor& other) const;
	///
	MColor&		    operator+=( const MColor& other );
	///
 	MColor   		operator-() const;
	///
 	MColor   		operator-( const MColor& other ) const;
	///
 	MColor          operator*( const MColor& other ) const;
	///
	MColor&         operator*=( const MColor& other );
	///
 	bool          	operator!=( const MColor& other ) const;
	///
 	bool           	operator==( const MColor& other ) const;
	///
	bool			get( float d[3] ) const;
	///
	bool			get( MColorType colorModel, float&, float&, float& ) const;
	///
	bool			get( MColorType colorModel, float&, float&, float&, float& alpha ) const;
	///	
	bool			set( MColorType colorModel, float, float, float, float alpha = 1.0);

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
 	float&      	operator()( unsigned int i );
	///	NO SCRIPT SUPPORT
 	float&      	operator[]( unsigned int i );

	///	NO SCRIPT SUPPORT
 	friend OPENMAYA_EXPORT MColor	operator*( float scalar, const MColor& other);
	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT std::ostream& operator<<(std::ostream& os, const MColor& c);

END_NO_SCRIPT_SUPPORT:

    /// the red component of the color
	float r;
    /// the green component of the color
	float g;
    /// the blue component of the color
	float b;
	/// the alpha component of the color
	float a;


protected:
// No protected members

private:
// No private members

};

#ifdef WANT_GCC41_FRIEND
MColor operator*( float scalar, const MColor& other); 
#endif
 

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MColor */
