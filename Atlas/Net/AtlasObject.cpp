/*
	AtlasObject.cpp
	----------------
	begin: 1999.11.29
	copyright: (C) 1999 by John Barrett (ZW)
	email: jbarrett@box100.com
*/

#include "AtlasObject.h"

int AObject::AScalar		= 0;
int AObject::AIntList		= 1;
int AObject::AUriList		= 2;
int AObject::AFloatList		= 3;
int AObject::AStringList	= 4;
int AObject::AObjList		= 5;

AObject &AObject::operator=(const AObject& src)
{
	if (this == &src) return (*this);
	nam = src.nam;
	obj = src.obj;
	typ = src.typ;
	Py_XINCREF(obj);
	return (*this);
}

AObject::AObject()
{
	obj = PyDict_New();
}

AObject::AObject(const AObject& src)
{
	nam = src.nam;
	obj = src.obj;
	typ = src.typ;
	Py_XINCREF(obj);
}

AObject::AObject(const string& name, PyObject* src)
{
	nam = name;
	obj = src;
	Py_XINCREF(obj);
}

AObject::AObject(const string& name, AObject& src)
{
	nam = name;
	obj = src.obj;
	typ = src.typ;
	Py_XINCREF(obj);
}

AObject::AObject(const string& name, const string& src)
{
	nam = name;
	char* tmp = strdup(src.c_str());
	obj = PyString_FromString(tmp);
	free(tmp);
}

AObject::AObject(const string& name, double src)
{
	nam = name;
	obj = PyFloat_FromDouble(src);
}

AObject::AObject(const string& name, long src)
{
	nam = name;
	obj = PyLong_FromLong(src);
}

AObject::AObject(const string& src)
{
	nam = string("str");
	char* tmp = strdup(src.c_str());
	obj = PyString_FromString(tmp);
	free(tmp);
}

AObject::AObject(double src)
{
	nam = string("flt");
	obj = PyFloat_FromDouble(src);
}

AObject::AObject(long src)
{
	nam = string("int");
	obj = PyLong_FromLong(src);
}

AObject::AObject(const string& name, int len, long src, ...)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AIntList;

	PyList_SetItem(obj, 0, PyLong_FromLong(src));
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		long tmp = va_arg(va,long);
		PyList_SetItem(obj, i, PyLong_FromLong(src));
	}
	va_end(ap);
}

AObject::AObject(const string& name, int len, double src, ...)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AFloatList;

	PyList_SetItem(obj, 0, PyFloat_FromDouble(src));
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		double tmp = va_arg(va,double);
		PyList_SetItem(obj, i, PyFloat_FromDouble(src));
	}
	va_end(ap);
}

AObject::AObject(const string& name, int len, string* src, ...)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AStringList;

	char* tmp = strdup(src->c_str());
	PyList_SetItem(obj, 0, PyString_FromString(tmp));
	free(tmp);
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		string* val = va_arg(va,string*);
		char* tmp = strdup(val->c_str());
		PyList_SetItem(obj, i, PyString_FromString(tmp));
		free(tmp);
	}
	va_end(ap);
}

AObject::AObject(const string& name, int len, long* src)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AIntList;

	for (int i=0; i<len; i++) {
		PyList_SetItem(obj, i, PyLong_FromLong(src[i]));
	}
}

AObject::AObject(const string& name, int len, double* src)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AFloatList;

	for (int i=0; i<len; i++) {
		PyList_SetItem(obj, i, PyFloat_FromDouble(src[i]));
	}
}

AObject::AObject(const string& name, int len, string* src)
{
	nam = name;
	obj = PyList_New(len);
	typ = AObject::AStringList;

	for (int i=0; i<len; i++) {
		char* tmp = strdup(src[i].c_str());
		PyList_SetItem(obj, i, PyString_FromString(tmp));
		free(tmp);
	}
}

AObject::AObject(int len, long src, ...)
{
	nam = string("");
	obj = PyList_New(len);
	typ = AObject::AIntList;

	PyList_SetItem(obj, 0, PyLong_FromLong(src));
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		long tmp = va_arg(va,long);
		PyList_SetItem(obj, i, PyLong_FromLong(src));
	}
	va_end(ap);
}

AObject::AObject(int len, double src, ...)
{
	nam = string("");
	obj = PyList_New(len);
	typ = AObject::AFloatList;

	PyList_SetItem(obj, 0, PyFloat_FromDouble(src));
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		double tmp = va_arg(va,double);
		PyList_SetItem(obj, i, PyFloat_FromDouble(src));
	}
	va_end(ap);
}

AObject::AObject(int len, string* src, ...)
{
	nam = string("");
	obj = PyList_New(len);
	typ = AObject::AStringList;

	char* tmp = strdup(src->c_str());
	PyList_SetItem(obj, 0, PyString_FromString(tmp));
	free(tmp);
	len--;
	va_list	va;
	va_start(va,src);
	for (int i=1; i<len; i++) {
		string* val = va_arg(va,string*);
		char* tmp = strdup(val->c_str());
		PyList_SetItem(obj, i, PyString_FromString(tmp));
		free(tmp);
	}
	va_end(ap);
}

AObject::AObject(int len, double* src)
{
	nam = strdup("");
	obj = PyList_New(len);
	typ = AObject::AFloatList;

	for (int i=0; i<len; i++) {
		PyList_SetItem(obj, i, PyFloat_FromDouble(src[i]));
	}
}

AObject::AObject(int len, string* src)
{
	nam = strdup("");
	obj = PyList_New(len);
	typ = AObject::AStringList;

	for (int i=0; i<len; i++) {
		char* tmp = strdup(src[i].c_str());
		PyList_SetItem(obj, i, PyString_FromString(tmp));
		free(tmp);
	}
}

AObject::~AObject()
{
	Py_XDECREF(obj);
}

PyObject* AObject::pyObject()
{
	return obj;
}

string	AObject::getName() const
{
	return string(nam);
}

void	AObject::setName(const string& name)
{
	nam = name;
}

int	AObject::has(const string& name)
{
	char* tmp = strdup(name.c_str());
	bool res = PyObject_HasAttrString(obj, tmp);
	free(tmp);
	return res;
}

int	AObject::get(const string& name, AObject& val)
{
	char* tmp = strdup(name.c_str());
	val = AObject(name, PyDict_GetItemString(obj,tmp));
	free(tmp);
	return 1;
}

int	AObject::get(const string& name, long& val)
{
	if (!this->isLong()) return 0;
	char* tmp = strdup(name.c_str());
	val = PyLong_AsLong(PyDict_GetItemString(obj,tmp));
	free(tmp);
	return 1;
}

int	AObject::get(const string& name, double& val)
{
	if (!this->isFloat()) return 0;
	char* tmp = strdup(name.c_str());
	val = PyFloat_AsDouble(PyDict_GetItemString(obj,tmp));
	free(tmp);
	return 1;
}

int	AObject::get(const string& name, string& val)
{
	if (!this->isString()) return 0;
	char* tmp = strdup(val.c_str());
	val = PyString_AsString(PyDict_GetItemString(obj,tmp));
	free(tmp);
	return 1;
}

int	AObject::get(int ndx, AObject& val)
{
	char buf[20];
	sprintf(buf,"%i", ndx);
	val = AObject(buf, PyList_GetItem(obj,ndx));
	return 1;
}

int	AObject::get(int ndx, long& val)
{
	if (!this->isLong()) return 0;
	val = PyLong_AsLong(PyList_GetItem(obj,ndx));
	return 1;
}

int	AObject::get(int ndx, double& val)
{
	if (!this->isFloat()) return 0;
	val = PyFloat_AsDouble(PyList_GetItem(obj,ndx));
	return 1;
}

int	AObject::get(int ndx, string& val)
{
	if (!this->isString()) return 0;
	val = PyString_AsString(PyList_GetItem(obj,ndx));
	return 1;
}

int	AObject::set(const string& name, AObject& src)
{
	char* tmp = strdup(name.c_str());
	bool res = PyDict_SetItemString(obj,tmp,src.obj);
	free(tmp);
	return res;
}

int	AObject::set(const string& name, const string& src)
{
	char* var = strdup(name.c_str());
	char* tmp = strdup(src.c_str());
	bool res = PyDict_SetItemString(obj, var, PyString_FromString(tmp));
	free(tmp);
	free(var);
	return res;
}

int	AObject::set(const string& name, long src)
{
	char* tmp = strdup(name.c_str());
	bool res = PyDict_SetItemString(obj, tmp, PyLong_FromLong(src));
	free(tmp);
	return res;
}

int	AObject::set(const string& name, double src)
{
	char* tmp = strdup(name.c_str());
	bool res = PyDict_SetItemString(obj, tmp, PyFloat_FromDouble(src));
	free(tmp);
	return res;
}

int	AObject::set(AObject& src)
{
	char* tmp = strdup(src.getName().c_str());
	bool res = PyDict_SetItemString(obj,tmp,src.obj);
	free(tmp);
	return res;
}

int	AObject::set(int ndx, AObject& src)
{
	return PyList_SetItem(obj, ndx, src.obj);
}

int	AObject::set(int ndx, long src)
{
	if (!this->isLong()) return 0;
	return PyList_SetItem(obj, ndx, PyLong_FromLong(src));
}

int	AObject::set(int ndx, double src)
{
	if (!this->isFloat()) return 0;
	return PyList_SetItem(obj, ndx, PyFloat_FromDouble(src));
}

int	AObject::set(int ndx, const string& src)
{
	if (!this->isString()) return 0;
	char* tmp = strdup(src.c_str());
	bool res = PyList_SetItem(obj, ndx, PyString_FromString(tmp));
	free(tmp);
	return res;
}

int	AObject::del(const string& name)
{
	char* tmp = strdup(name.c_str());
	bool res = PyDict_DelItemString(obj,tmp);
	free(tmp);
	return res;
}

int	AObject::hash()
{
	return PyObject_Hash(obj);	
}

int	AObject::isTrue()
{
	return PyObject_IsTrue(obj);	
}

int	AObject::length()
{
	return PyObject_Length(obj);	
}

int	AObject::reverse()
{
	return PyList_Reverse(obj);
}

int	AObject::append(AObject& src)
{
	return PyList_Append(obj, src.obj);
}

int	AObject::append(long src)
{
	return PyList_Append(obj, PyLong_FromLong(src));
}

int	AObject::append(double src)
{
	return PyList_Append(obj, PyFloat_FromDouble(src));
}

int	AObject::append(const string& src)
{
	char* tmp = strdup(src.c_str());
	bool res = PyList_Append(obj, PyString_FromString(tmp));
	free(tmp);
	return res;
}

int	AObject::insert(int ndx, AObject& src)
{
	return PyList_Insert(obj, ndx, src.obj);
}

int	AObject::insert(int ndx, const string& src)
{
	char* tmp = strdup(src.c_str());
	bool res = PyList_Insert(obj, ndx, PyString_FromString(tmp));
	free(tmp);
	return res;
}

int	AObject::insert(int ndx, double src)
{
	return PyList_Insert(obj, ndx, PyFloat_FromDouble(src));
}

int	AObject::insert(int ndx, long src)
{
	return PyList_Insert(obj, ndx, PyLong_FromLong(src));
}

AObject	AObject::keys()
{
	AObject res("list",PyDict_Keys(obj));
	return res;
}

AObject	AObject::vals()
{
	AObject res("list",PyDict_Values(obj));
	return res;
}

long	AObject::asLong()	{ return PyLong_AsLong(obj); }
double	AObject::asFloat()	{ return PyFloat_AsDouble(obj); }
string	AObject::asString()	{ return PyString_AsString(obj); }

int	AObject::isMap()	{ return PyMapping_Check(obj); }
int	AObject::isList()	{ return PyList_Check(obj); }
int	AObject::isLong()	{ return PyLong_Check(obj); }
int	AObject::isFloat()	{ return PyFloat_Check(obj); }
int	AObject::isString()	{ return PyString_Check(obj); }

AObject AObject::mkMap(const string& name)
{
	char* tmp = strdup(name.c_str());
	AObject res(tmp, PyDict_New());
	free(tmp);
	return res;
}

AObject AObject::mkList(const string& name, int size)
{
	char* tmp = strdup(name.c_str());
	AObject res(tmp, PyList_New(size));
	res.typ = AObject::AObjList;
	free(tmp);
	return res;
}

AObject AObject::mkLong(const string& name, long val)
{
	char* tmp = strdup(name.c_str());
	AObject res(tmp, PyLong_FromLong(val));
	free(tmp);
	return res;
}

AObject AObject::mkFloat(const string& name, double val)
{
	char* tmp = strdup(name.c_str());
	AObject res(tmp, PyFloat_FromDouble(val));
	free(tmp);
	return res;
}

AObject AObject::mkString(const string& name, const string& val)
{
	char* tmp = strdup(name.c_str());
	AObject res(tmp, PyString_FromString(val.c_str()));
	free(tmp);
	return res;
}


