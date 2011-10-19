// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2005 Alistair Riddoch.
// Automatically generated using gen_cpp.py.

#include <Atlas/Objects/Operation.h>

using Atlas::Message::Element;
using Atlas::Message::MapType;

namespace Atlas { namespace Objects { namespace Operation { 

Allocator<DeleteData> DeleteData::allocator;

void DeleteData::free()
{
    attr_args.clear();
    allocator.free(this);
}

DeleteData::~DeleteData()
{
}

DeleteData * DeleteData::copy() const
{
    DeleteData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool DeleteData::instanceOf(int classNo) const
{
    if(DELETE_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

void DeleteData::fillDefaultObjectInstance(DeleteData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "delete");
    ActionData::allocator.getDefaultObjectInstance();
}

Allocator<SetData> SetData::allocator;

void SetData::free()
{
    attr_args.clear();
    allocator.free(this);
}

SetData::~SetData()
{
}

SetData * SetData::copy() const
{
    SetData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool SetData::instanceOf(int classNo) const
{
    if(SET_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

void SetData::fillDefaultObjectInstance(SetData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "set");
    ActionData::allocator.getDefaultObjectInstance();
}

Allocator<AffectData> AffectData::allocator;

void AffectData::free()
{
    attr_args.clear();
    allocator.free(this);
}

AffectData::~AffectData()
{
}

AffectData * AffectData::copy() const
{
    AffectData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool AffectData::instanceOf(int classNo) const
{
    if(AFFECT_NO == classNo) return true;
    return SetData::instanceOf(classNo);
}

void AffectData::fillDefaultObjectInstance(AffectData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "affect");
    SetData::allocator.getDefaultObjectInstance();
}

Allocator<MoveData> MoveData::allocator;

void MoveData::free()
{
    attr_args.clear();
    allocator.free(this);
}

MoveData::~MoveData()
{
}

MoveData * MoveData::copy() const
{
    MoveData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool MoveData::instanceOf(int classNo) const
{
    if(MOVE_NO == classNo) return true;
    return SetData::instanceOf(classNo);
}

void MoveData::fillDefaultObjectInstance(MoveData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "move");
    SetData::allocator.getDefaultObjectInstance();
}

Allocator<WieldData> WieldData::allocator;

void WieldData::free()
{
    attr_args.clear();
    allocator.free(this);
}

WieldData::~WieldData()
{
}

WieldData * WieldData::copy() const
{
    WieldData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool WieldData::instanceOf(int classNo) const
{
    if(WIELD_NO == classNo) return true;
    return SetData::instanceOf(classNo);
}

void WieldData::fillDefaultObjectInstance(WieldData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "wield");
    SetData::allocator.getDefaultObjectInstance();
}

Allocator<GetData> GetData::allocator;

void GetData::free()
{
    attr_args.clear();
    allocator.free(this);
}

GetData::~GetData()
{
}

GetData * GetData::copy() const
{
    GetData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool GetData::instanceOf(int classNo) const
{
    if(GET_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

void GetData::fillDefaultObjectInstance(GetData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "get");
    ActionData::allocator.getDefaultObjectInstance();
}

} } } // namespace Atlas::Objects::Operation
