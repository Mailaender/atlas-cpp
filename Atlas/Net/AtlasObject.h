/*
        AtlasObject.h
        ----------------
        begin           : 1999.11.29
        copyright       : (C) 1999 by John Barrett (ZW)
        email           : jbarrett@box100.com
*/

#ifndef __AtlasObject_h_
#define __AtlasObject_h_

#ifdef _WIN32
#include <Python/python.h>
#else
#include <python.h>
#endif

#include <string>


/**
 * Atlas Base Object Structure
 *
 * AObject is an implementation of the Atlas
 * Object structure based on the Python PyObject
 * type. By relating all Atlas Object Structures
 * to the Python Object type, no conversion is
 * needed when transfering messages and data from
 * the network transports, to C++, and thence to
 * Python, or from Python to C++ to the network.
 *
 * AObject implements 5 basic data types:
 *
 * <pre>
 *@@	AObject		C/C++ Type
 *@@	==========================
 *@@	Int		long
 *@@	Float		double
 *@@	String		char *
 *@@	List		list<AObject*>
 *@@	Map		map<AObject*>
 * </pre>
 *
 * Atlas Typed Lists are supported by means
 * of the standard AObject List type and a
 * special type flag which enables type
 * checking of any data stored to a typed
 * list. Additionally, the ACodec object 
 * stream handler classes can use this flag
 * to produce more efficiently compacted
 * data streams from a given AObject message.
 *
 * Use of the AObject type flag by any specific
 * ACodec module is optional, as the essential
 * structure of the AObject will still be sent
 * correctly to the remote system even if the
 * flag is not used during encoding.
 *
 * @see ACodec
 * @author John Barrett (ZW) <a href="mailto:jbarrett@box100.com">jbarrett@box100.com</a>
 * @source AtlasObject.h
 */ 

class AObject
{
protected:

/** Typed List Flag */
	int		typ;

/** Name of this AObject */
	string		nam;

/** Python Object to hold the data */
	PyObject*	obj;

public:

/** Default "typ" value, not a typed list */
static	int AScalar;

/** "typ" value for a List of Integers */
static	int AIntList;

/** "typ" value for a List of URIs */
static	int AUriList;

/** "typ" value for a List of Floats */
static	int AFloatList;

/** "typ" value for a List of Strings */
static	int AStringList;

/** "typ" value for a List of Objects */
static	int AObjList;

/** overload assignment so copying works right */
	AObject &operator=(const AObject& src);

/** Construct an AObject */
	AObject();

/** Construct a copy of an existing AObject */
	AObject(const AObject& src);

/** Construct an AObject from an existing PyObject */
	AObject(const string& name, PyObject* src);

/** Construct an AObject from an existing AObject, but with a new name */
	AObject(const string& name, AObject& src);

/** Constuct an Int type AObject */
	AObject(const string& name, long val);

/** Contruct a Float type AObject */
	AObject(const string& name, double val);

/** Construct a String type AObject */
	AObject(const string& name, const string& val);


/** Construct a String typed list AObject */
	AObject(const string& name, int len, string* val, ...);

/** Construct a Float typed list AObject */
	AObject(const string& name, int len, double val, ...);

/** Construct a Long typed list AObject */
	AObject(const string& name, int len, long val, ...);


/** Construct a String typed list AObject from an array */
	AObject(const string& name, int len, string* val);

/** Construct a Float typed list AObject from an array */
	AObject(const string& name, int len, double *val);

/** Construct a Long typed list AObject from an array */
	AObject(const string& name, int len, long *val);


/** Construct an anonymous Int AObject */
	AObject(long val);

/** Construct an anonymous Float AObject */
	AObject(double val);

/** Construct an anonymous String AObject */
	AObject(const string& val);



/** Construct an anonymous String typed list AObject */
	AObject(int len, string* val, ...);

/** Construct an anonymous Float typed list AObject */
	AObject(int len, double val, ...);

/** Construct an anonymous Long typed list AObject */
	AObject(int len, long val, ...);



/** Construct an anonymous String typed list AObject from an array */
	AObject(int len, string* val);

/** Construct an anonymous Float typed list AObject from an array */
	AObject(int len, double* val);

/** Construct an anonymous Long typed list AObject from an array */
	AObject(int len, long* val);



/** Destroy an AObject */
	~AObject();



/** Get a pointer to this AObject's PyObject */
	PyObject* pyObject();



/** Get the name of this AObject */
	string		getName() const;

/** Change the name of this AObject */
	void		setName(const string& name);

/** get the data type for a typed list */
	int		getListType();

/** set the data type for a typed list */
	void		setListType(int atype);

/** (Map) test for named element of a map */
	int		has(const string& name);



/** (Map) get an AObject attribute */
	int		get(const string& name, AObject& val);

/** (Map) get an Int attribute */
	int		get(const string& name, long& val);

/** (Map) get a Float attribute */
	int		get(const string& name, double& val);

/** (Map) get a String attribute */
	int		get(const string& name, string& val);



/** (Map) set an Object attribute */
	int		set(const string& name, AObject& src);

/** (Map) set an Int attribute */
	int		set(const string& name, long src);

/** (Map) set a Float attribute */
	int		set(const string& name, double src);

/** (Map) set a String attribute */
	int		set(const string& name, const string& src);

/** (Map) set an AObject attribute using its stored name */
	int		set(AObject& src);



/** (Map) remove an attribute */
	int		del(const string& name);



/** return a hash value for this AObject */
	int		hash();

/** return if this AObject evaluates to True or False */
	int		isTrue();

/** return the length of this object */
	int		length();



/** return an empty map */
static	AObject	mkMap(const string& name);

/** return an empty list */
static	AObject	mkList(const string& name);

/** return an empty list with (len) elements */
static	AObject	mkList(const string& name, int len);

/** return an Int AObject */
static	AObject	mkLong(const string& name, long val);

/** return a Float AObject */
static	AObject	mkFloat(const string& name, double val);

/** return a String AObject */
static	AObject	mkString(const string& name, const string& val);



/** true if this AObject is a Map */
	int		isMap();

/** true if this AObject is a List */
	int 		isList();

/** true if this AObject is a Int */
	int		isLong();

/** true if this AObject is a Float */
	int		isFloat();

/** true if this AObject is a String */
	int		isString();



/** (Map) return a List of all keys for a Map */
	AObject		keys();

/** (Map) return a List of all values for a Map */
	AObject		vals();


/** (List) sort a List */
	int		sort();


/** (List) reverse the order of a list */
	int		reverse();

/** (List) insert an AObject at this index */
	int		insert(int ndx, AObject& val);
/** (List) insert an Int at this index */
	int		insert(int ndx, long val);
/** (List) insert a Float at this index */
	int		insert(int ndx, double val);
/** (List) insert a String at this index */
	int		insert(int ndx, const string& val);

/** (List) append an AObject */
	int		append(AObject& val);
/** (List) append an Int */
	int		append(long val);
/** (List) append a Float */
	int		append(double val);
/** (List) append a String */
	int		append(const string& val);

/** (List) replace an AObject at this index */
	int		set(int ndx, AObject& src);
/** (List) replace an Int at this index */
	int		set(int ndx, long val);
/** (List) replace a Float at this index */
	int		set(int ndx, double val);
/** (List) replace a String at this index */
	int		set(int ndx, const string& val);

/** (List) get an AObject from this index */
	int		get(int ndx, AObject& src);
/** (List) get an Int from this index */
	int		get(int ndx, long& val);
/** (List) get a Float from this index */
	int		get(int ndx, double& val);
/** (List) get a String from this index */
	int		get(int ndx, string& val);

	// typed returns
/** get an Int value from this AObject */
	long		asLong();
/** get a Float value from this AObject */
	double		asFloat();
/** get a String value from this AObject */
	string		asString();

};

#endif


