// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_NEGOTIATE_H
#define ATLAS_NEGOTIATE_H

#include "Codec.h"

#define Debug(prg) { if (debug_flag) { prg } }

namespace Atlas {

/** Negotiation of codecs and filters for an Atlas connection

non blocking negotiation of Codecs
requires a list of avalable Codecs,
along with the name of sender and a Socket

@see Connection
@see Codec
*/

template <typename Stream>
class Negotiate : public Task
{
    public:

    enum State
    {
	IN_PROGRESS,
	SUCCEEDED,
	FAILED,
    };

    virtual State GetState() = 0;
    virtual Codec<Stream>* GetCodec() = 0;
};

} // Atlas namespace

#endif
