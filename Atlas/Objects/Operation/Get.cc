// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Get.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Get::Get()
     : Action()
{
    SetId(string("get"));
    Object::ListType parents;
    parents.push_back(string("action"));
    SetParents(parents);
}

Get Get::Instantiate()
{
    Get value;

    Object::ListType parents;
    parents.push_back(string("get"));
    value.SetParents(parents);
    value.SetObjtype(string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
