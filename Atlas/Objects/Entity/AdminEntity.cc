// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#include "AdminEntity.h"

using Atlas::Message::Object;

namespace Atlas { namespace Objects { namespace Entity { 

AdminEntity::AdminEntity()
     : RootEntity()
{
    SetId(std::string("admin_entity"));
    Object::ListType parents;
    parents.push_back(string("root_entity"));
    SetParents(parents);
}

AdminEntity AdminEntity::Instantiate()
{
    AdminEntity value;

    Object::ListType parents;
    parents.push_back(std::string("admin_entity"));
    value.SetParents(parents);
    value.SetObjtype(std::string("object"));
    
    return value;
}

} } } // namespace Atlas::Objects::Entity
