// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2005 Alistair Riddoch.
// Automatically generated using gen_cpp.py.

#include <Atlas/Objects/Operation.h>

using Atlas::Message::Element;
using Atlas::Message::MapType;

namespace Atlas { namespace Objects { namespace Operation { 

Allocator<LogoutData> LogoutData::allocator;

void LogoutData::free()
{
    attr_args.clear();
    allocator.free(this);
}

LogoutData::~LogoutData()
{
}

LogoutData * LogoutData::copy() const
{
    LogoutData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool LogoutData::instanceOf(int classNo) const
{
    if(LOGOUT_NO == classNo) return true;
    return LoginData::instanceOf(classNo);
}

void LogoutData::fillDefaultObjectInstance(LogoutData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "logout");
    LoginData::allocator.getDefaultObjectInstance();
}

Allocator<ImaginaryData> ImaginaryData::allocator;

void ImaginaryData::free()
{
    attr_args.clear();
    allocator.free(this);
}

ImaginaryData::~ImaginaryData()
{
}

ImaginaryData * ImaginaryData::copy() const
{
    ImaginaryData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool ImaginaryData::instanceOf(int classNo) const
{
    if(IMAGINARY_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

void ImaginaryData::fillDefaultObjectInstance(ImaginaryData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "imaginary");
    ActionData::allocator.getDefaultObjectInstance();
}

Allocator<UseData> UseData::allocator;

void UseData::free()
{
    attr_args.clear();
    allocator.free(this);
}

UseData::~UseData()
{
}

UseData * UseData::copy() const
{
    UseData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool UseData::instanceOf(int classNo) const
{
    if(USE_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

void UseData::fillDefaultObjectInstance(UseData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "use");
    ActionData::allocator.getDefaultObjectInstance();
}

Allocator<InfoData> InfoData::allocator;

void InfoData::free()
{
    attr_args.clear();
    allocator.free(this);
}

InfoData::~InfoData()
{
}

InfoData * InfoData::copy() const
{
    InfoData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool InfoData::instanceOf(int classNo) const
{
    if(INFO_NO == classNo) return true;
    return RootOperationData::instanceOf(classNo);
}

void InfoData::fillDefaultObjectInstance(InfoData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "info");
    RootOperationData::allocator.getDefaultObjectInstance();
}

Allocator<PerceptionData> PerceptionData::allocator;

void PerceptionData::free()
{
    attr_args.clear();
    allocator.free(this);
}

PerceptionData::~PerceptionData()
{
}

PerceptionData * PerceptionData::copy() const
{
    PerceptionData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool PerceptionData::instanceOf(int classNo) const
{
    if(PERCEPTION_NO == classNo) return true;
    return InfoData::instanceOf(classNo);
}

void PerceptionData::fillDefaultObjectInstance(PerceptionData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "perception");
    InfoData::allocator.getDefaultObjectInstance();
}

Allocator<SightData> SightData::allocator;

void SightData::free()
{
    attr_args.clear();
    allocator.free(this);
}

SightData::~SightData()
{
}

SightData * SightData::copy() const
{
    SightData * copied = allocator.alloc();
    *copied = *this;
    copied->m_refCount = 0;
    return copied;
}

bool SightData::instanceOf(int classNo) const
{
    if(SIGHT_NO == classNo) return true;
    return PerceptionData::instanceOf(classNo);
}

void SightData::fillDefaultObjectInstance(SightData& data, std::map<std::string, int>& attr_data)
{
    data.attr_objtype = "op";
    data.attr_serialno = 0;
    data.attr_refno = 0;
    data.attr_seconds = 0.0;
    data.attr_future_seconds = 0.0;
    data.attr_stamp = 0.0;
    data.attr_parents = std::list<std::string>(1, "sight");
    PerceptionData::allocator.getDefaultObjectInstance();
}

} } } // namespace Atlas::Objects::Operation
