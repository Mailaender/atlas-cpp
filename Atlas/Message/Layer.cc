// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day, Stefanus Du Toit

#include <Atlas/Message/Layer.h>

namespace Atlas { namespace Message {
    
Layer::Layer(Atlas::Bridge* bridge) : Encoder(bridge), DecoderBase()
{
}

} } // namespace Atlas::Message
