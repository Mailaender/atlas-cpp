// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Touch.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Touch::Touch()
     : Perceive()
{
    SetId(string("touch"));
    Object::ListType parents;
    parents.push_back(string("perceive"));
    SetParents(parents);
}

Touch Touch::Instantiate()
{
    Touch value;

    Object::ListType parents;
    parents.push_back(string("touch"));
    value.SetParents(parents);
    value.SetObjtype(string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
