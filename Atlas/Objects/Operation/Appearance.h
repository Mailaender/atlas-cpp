// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000 Stefanus Du Toit.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_APPEARANCE_H
#define ATLAS_OBJECTS_OPERATION_APPEARANCE_H

#include "Sight.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Character sees something appearing: it literally appears or has it come in visible range

Base operator for all kind of perceptions

*/
class Appearance : public Sight
{
public:
    /// Construct a Appearance class definition.
    Appearance();
  protected:
    Appearance(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Appearance() { }

    /// Create a new instance of Appearance.
    static Appearance Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_APPEARANCE_H
