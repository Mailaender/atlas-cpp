// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_CREATE_H
#define ATLAS_OBJECTS_OPERATION_CREATE_H

#include "Action.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Create new things from nothing using this operator.

Map editor is main user for this in client side. Server uses this inside "info" operation to tell client about new things.

*/
class Create : public Action
{
public:
    /// Construct a Create class definition.
    Create();
  protected:
    Create(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Create() { }

    /// Create a new instance of Create.
    static Create Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_CREATE_H
