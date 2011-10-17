// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2005 Alistair Riddoch.
// Automatically generated using gen_cpp.py.

#include <Atlas/Objects/RootEntity.h>

using Atlas::Message::Element;
using Atlas::Message::MapType;

namespace Atlas { namespace Objects { namespace Entity { 

const std::string LOC_ATTR = "loc";
const std::string POS_ATTR = "pos";
const std::string VELOCITY_ATTR = "velocity";
const std::string CONTAINS_ATTR = "contains";
const std::string STAMP_CONTAINS_ATTR = "stamp_contains";

int RootEntityData::getAttrClass(const std::string& name) const
{
    if (allocator.attr_flags_Data.find(name) != allocator.attr_flags_Data.end()) {
        return ROOT_ENTITY_NO;
    }
    return RootData::getAttrClass(name);
}

int RootEntityData::getAttrFlag(const std::string& name) const
{
    std::map<std::string, int>::const_iterator I = allocator.attr_flags_Data.find(name);
    if (I != allocator.attr_flags_Data.end()) {
        return I->second;
    }
    return RootData::getAttrFlag(name);
}

int RootEntityData::copyAttr(const std::string& name, Element & attr) const
{
    if (name == LOC_ATTR) { attr = getLoc(); return 0; }
    if (name == POS_ATTR) { attr = getPosAsList(); return 0; }
    if (name == VELOCITY_ATTR) { attr = getVelocityAsList(); return 0; }
    if (name == CONTAINS_ATTR) { attr = getContainsAsList(); return 0; }
    if (name == STAMP_CONTAINS_ATTR) { attr = getStampContains(); return 0; }
    return RootData::copyAttr(name, attr);
}

void RootEntityData::setAttr(const std::string& name, const Element& attr)
{
    if (name == LOC_ATTR) { setLoc(attr.asString()); return; }
    if (name == POS_ATTR) { setPosAsList(attr.asList()); return; }
    if (name == VELOCITY_ATTR) { setVelocityAsList(attr.asList()); return; }
    if (name == CONTAINS_ATTR) { setContainsAsList(attr.asList()); return; }
    if (name == STAMP_CONTAINS_ATTR) { setStampContains(attr.asFloat()); return; }
    RootData::setAttr(name, attr);
}

void RootEntityData::removeAttr(const std::string& name)
{
    if (name == LOC_ATTR)
        { m_attrFlags &= ~LOC_FLAG; return;}
    if (name == POS_ATTR)
        { m_attrFlags &= ~POS_FLAG; return;}
    if (name == VELOCITY_ATTR)
        { m_attrFlags &= ~VELOCITY_FLAG; return;}
    if (name == CONTAINS_ATTR)
        { m_attrFlags &= ~CONTAINS_FLAG; return;}
    if (name == STAMP_CONTAINS_ATTR)
        { m_attrFlags &= ~STAMP_CONTAINS_FLAG; return;}
    RootData::removeAttr(name);
}

inline void RootEntityData::sendLoc(Atlas::Bridge & b) const
{
    if(m_attrFlags & LOC_FLAG) {
        b.mapStringItem(LOC_ATTR, attr_loc);
    }
}

inline void RootEntityData::sendPos(Atlas::Bridge & b) const
{
    if(m_attrFlags & POS_FLAG) {
        b.mapListItem(POS_ATTR);
        const std::vector<double> & v = attr_pos;
        std::vector<double>::const_iterator I = v.begin();
        for(; I != v.end(); ++I) {
            b.listFloatItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendVelocity(Atlas::Bridge & b) const
{
    if(m_attrFlags & VELOCITY_FLAG) {
        b.mapListItem(VELOCITY_ATTR);
        const std::vector<double> & v = attr_velocity;
        std::vector<double>::const_iterator I = v.begin();
        for(; I != v.end(); ++I) {
            b.listFloatItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendContains(Atlas::Bridge & b) const
{
    if(m_attrFlags & CONTAINS_FLAG) {
        b.mapListItem(CONTAINS_ATTR);
        const std::list<std::string> & l = attr_contains;
        std::list<std::string>::const_iterator I = l.begin();
        for(; I != l.end(); ++I) {
            b.listStringItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendStampContains(Atlas::Bridge & b) const
{
    if(m_attrFlags & STAMP_CONTAINS_FLAG) {
        b.mapFloatItem(STAMP_CONTAINS_ATTR, attr_stamp_contains);
    }
}

void RootEntityData::sendContents(Bridge & b) const
{
    sendLoc(b);
    sendPos(b);
    sendVelocity(b);
    sendContains(b);
    sendStampContains(b);
    RootData::sendContents(b);
}

void RootEntityData::addToMessage(MapType & m) const
{
    RootData::addToMessage(m);
    if(m_attrFlags & LOC_FLAG)
        m[LOC_ATTR] = attr_loc;
    if(m_attrFlags & POS_FLAG)
        m[POS_ATTR] = getPosAsList();
    if(m_attrFlags & VELOCITY_FLAG)
        m[VELOCITY_ATTR] = getVelocityAsList();
    if(m_attrFlags & CONTAINS_FLAG)
        m[CONTAINS_ATTR] = getContainsAsList();
    if(m_attrFlags & STAMP_CONTAINS_FLAG)
        m[STAMP_CONTAINS_ATTR] = attr_stamp_contains;
    return;
}

void RootEntityData::iterate(int& current_class, std::string& attr) const
{
    // If we've already finished this class, chain to the parent
    if(current_class >= 0 && current_class != ROOT_ENTITY_NO) {
        RootData::iterate(current_class, attr);
        return;
    }

    static const char *attr_list[] = {"loc","pos","velocity","contains","stamp_contains",};
    static const unsigned n_attr = sizeof(attr_list) / sizeof(const char*);

    unsigned next_attr = n_attr; // so we chain to the parent if we don't find attr

    if(attr.empty()) // just staring on this class
        next_attr = 0;
    else {
      for(unsigned i = 0; i < n_attr; ++i) {
         if(attr == attr_list[i]) {
             next_attr = i + 1;
             break;
         }
      }
    }

    if(next_attr == n_attr) { // last one on the list
        current_class = -1;
        attr = "";
        RootData::iterate(current_class, attr); // chain to parent
    }
    else {
        current_class = ROOT_ENTITY_NO;
        attr = attr_list[next_attr];
    }
}

Allocator<RootEntityData> RootEntityData::allocator;

RootEntityData::~RootEntityData()
{
}

RootEntityData * RootEntityData::copy() const
{
    RootEntityData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool RootEntityData::instanceOf(int classNo) const
{
    if(ROOT_ENTITY_NO == classNo) return true;
    return RootData::instanceOf(classNo);
}

void RootEntityData::fillDefaultObjectInstance(RootEntityData& data, std::map<std::string, int>& attr_data)
{
        data.attr_objtype = "obj";
        data.attr_pos.clear();
        data.attr_pos.push_back(0.0);
        data.attr_pos.push_back(0.0);
        data.attr_pos.push_back(0.0);
        data.attr_velocity.clear();
        data.attr_velocity.push_back(0.0);
        data.attr_velocity.push_back(0.0);
        data.attr_velocity.push_back(0.0);
        data.attr_stamp_contains = 0.0;
        data.attr_stamp = 0.0;
        data.attr_parents = std::list<std::string>(1, "root_entity");
        attr_data[LOC_ATTR] = LOC_FLAG;
        attr_data[POS_ATTR] = POS_FLAG;
        attr_data[VELOCITY_ATTR] = VELOCITY_FLAG;
        attr_data[CONTAINS_ATTR] = CONTAINS_FLAG;
        attr_data[STAMP_CONTAINS_ATTR] = STAMP_CONTAINS_FLAG;
        RootData::allocator.getDefaultObjectInstance();
}

} } } // namespace Atlas::Objects::Entity
