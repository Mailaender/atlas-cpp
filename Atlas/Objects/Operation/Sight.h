// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_SIGHT_H
#define ATLAS_OBJECTS_OPERATION_SIGHT_H

#include "Perception.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Character sees something

Base operator for all kind of perceptions

*/
class Sight : public Perception
{
public:
    /// Construct a Sight class definition.
    Sight();
  protected:
    Sight(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Sight() { }

    /// Create a new instance of Sight.
    static Sight Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_SIGHT_H
