// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_DELETE_H
#define ATLAS_OBJECTS_OPERATION_DELETE_H

#include "Action.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Delete something.

This is base operation for all other
    operations and defines basic attributes. You can use this as
    starting point for browsing whole operation hiearchy. refno refers
    to operation this is reply for. In examples all attributes that
    are just as examples (and thus world specific) are started with 'e_'.

*/
class Delete : public Action
{
public:
    /// Construct a Delete class definition.
    Delete();
  protected:
    Delete(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Delete() { }

    /// Create a new instance of Delete.
    static Delete Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_DELETE_H
