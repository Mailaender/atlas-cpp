// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Create.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Operation { 

Create::Create()
     : Action()
{
    SetId(string("create"));
    Object::ListType parents;
    parents.push_back(string("action"));
    SetParents(parents);
}

Create Create::Instantiate()
{
    Create value;

    Object::ListType parents;
    parents.push_back(string("create"));
    value.SetParents(parents);
    value.SetObjtype(string("op"));
    
    return value;
}

} } } // namespace Atlas::Objects::Operation
