// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Alistair Riddoch.
// Automatically generated using gen_cc.py.

#ifndef ATLAS_OBJECTS_OPERATION_LOGOUT_H
#define ATLAS_OBJECTS_OPERATION_LOGOUT_H

#include "Login.h"


namespace Atlas { namespace Objects { namespace Operation { 

/** Operation for logging out

For more about <a href="login.html">out of game atlas here</a>

*/
class Logout : public Login
{
public:
    /// Construct a Logout class definition.
    Logout();
  protected:
    Logout(const std::string&,const std::string&);
  public:
    /// Default destructor.
    virtual ~Logout() { }

    /// Create a new instance of Logout.
    static Logout Instantiate();

protected:

};

} } } // namespace Atlas::Objects::Operation

#endif // ATLAS_OBJECTS_OPERATION_LOGOUT_H
