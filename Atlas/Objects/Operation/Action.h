// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_ACTION_H
#define ATLAS_OBJECTS_OPERATION_ACTION_H

#include "RootOperation.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** This is base operator for operations that might have effects.

This is base operation for all other
    operations and defines basic attributes. You can use this as
    starting point for browsing whole operation hiearchy. refno refers
    to operation this is reply for. In examples all attributes that
    are just as examples (and thus world specific) are started with 'e_'.

*/
class Action : public RootOperation
{
public:
    /// Construct a Action class definition.
    Action();
  protected:
    Action(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Action() { }

    /// Create a new instance of Action.
    static Action Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_ACTION_H
