/*
        AtlasProtocolDecoder.h
        ----------------
        begin           : 1999.11.29
        copyright       : (C) 1999 by John Barrett (ZW)
        email           : jbarrett@box100.com
*/

#ifndef __AtlasProtocolDecoder_h_
#define __AtlasProtocolDecoder_h_

#include "AtlasObject.h"

class AProtocolDecoder
{
protected:
	string	buffer;
	string	name;
	int	type;
	string	sval;
	long	ival;
	double	fval;


public:
	AProtocolDecoder();

	string	getName();
	int	getType();
	string	getString();
	long	getInt();
	double	getFloat();


	virtual void	newStream();
	virtual void	feedStream(string& data);
	virtual int	hasTokens();
	virtual int	getToken();


};

#endif


