// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "Communicate.h"

using namespace std;
using namespace Atlas;
using namespace Atlas::Message;

namespace Atlas { namespace Objects { namespace Operation { 

Communicate::Communicate()
     : Create()
{
    SetAttr("id", string("communicate"));
    Object::ListType parent;
    parent.push_back(string("create"));
    SetAttr("parent", parent);
    SetAttr("specification", string("atlas-game"));
}

} } } // namespace Atlas::Objects::Operation
