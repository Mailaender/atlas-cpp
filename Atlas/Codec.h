// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Michael Day, Stefanus Du Toit

#ifndef ATLAS_CODEC_H
#define ATLAS_CODEC_H

#include "Bridge.h"
#include "Task.h"

namespace Atlas {

/** Atlas stream codec

This class presents an interface for sending and receiving Atlas messages.
Each outgoing message is converted to a byte stream and piped through an
optional chain of filters for compression or other transformations, then
passed to a socket for transmission. Incoming messages are read from the
socket, piped through the filters in the opposite direction and passed to
a user specified Bridge callback class.

@see Bridge
@see Task
@see Negotiate
*/

template <class Stream>
class Codec : public Bridge, public Task
{
    public:

    virtual ~Codec();

};

} // Atlas namespace

#endif
