// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_TOUCH_H
#define ATLAS_OBJECTS_OPERATION_TOUCH_H

#include <Atlas/Objects/Operation/Perceive.h>


namespace Atlas { namespace Objects { namespace Operation { 

/** Touch something

This is base operation for all other
    operations and defines basic attributes. You can use this as
    starting point for browsing whole operation hiearchy. refno refers
    to operation this is reply for. In examples all attributes that
    are just as examples (and thus world specific) are started with 'e_'.

*/
class Touch : public Perceive
{
public:
    /// Construct a Touch class definition.
    Touch();
  protected:
    Touch(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Touch() { }

    /// Create a new instance of Touch.
    static Touch Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_TOUCH_H
