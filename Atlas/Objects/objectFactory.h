// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Aloril

#ifndef ATLAS_OBJECTS_OBJECTFACTORY_H
#define ATLAS_OBJECTS_OBJECTFACTORY_H

#include <string>
#include <list>
#include <map>

#include "Root.h"

namespace Atlas { namespace Objects {

class NoSuchFactoryException
{
public:
    NoSuchFactoryException(const std::string& name) : name(name) {}
    std::string name;
};

typedef Root (*FactoryMethod)();
typedef std::map<const std::string, FactoryMethod> FactoryMap;

class Factories 
{
public:
    bool hasFactory(const std::string& name);
    Root createObject(const std::string& name);
    std::list<std::string> getKeys();
    void addFactory(const std::string& name, FactoryMethod method);
private:
    FactoryMap m_factories;
};
    
extern std::map<const std::string, Root> objectDefinitions;
extern Factories objectFactory;
//extern Factories objectInstanceFactory;

Root messageObject2ClassObject(const Atlas::Message::Object& mobj);

} } // namespace Atlas::Objects

#endif
