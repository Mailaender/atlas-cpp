// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day, Dmitry Derevyanko

#ifndef ATLAS_NET_STREAM_H
#define ATLAS_NET_STREAM_H

#include "../Negotiate.h"
#include "../Filter.h"

namespace Atlas { namespace Net {

/** Negotiation of codecs and filters for an Atlas connection

non blocking negotiation of Codecs and Filters
requires a list of avalable Codecs and Filters,
along with the name of sender and a Socket

@see Connection
@see Codec
@see Filter
*/

template <class T>
class NegotiateHelper 
{
	typedef std::list<T*> Factories;
		
public:
	
	NegotiateHelper(std::list<std::string> *names, Factories *out_factories);
	
	bool get(std::string &buf, std::string header);
	void put(std::string &buf, std::string header);
	
private:
	
	std::list<std::string> *names;
	Factories *outFactories;
	
};

class StreamConnect : public Atlas::Negotiate<std::iostream>
{
    public:

	StreamConnect(const std::string& name, std::iostream*, Atlas::Bridge*);

    virtual ~StreamConnect() {}

    virtual void Poll(bool can_read = true);

    virtual State GetState();
    virtual Atlas::Codec<std::iostream>* GetCodec();

    private:

    enum
    {
	SERVER_GREETING,
	CLIENT_GREETING,
	CLIENT_CODECS,
	SERVER_CODECS,
	CLIENT_FILTERS,
	SERVER_FILTERS,
	DONE
    };

    int state;

    std::string outName;
    std::string inName;
	std::iostream& socket;
    Atlas::Bridge* bridge;
    std::list<std::string> inCodecs;
    std::list<std::string> inFilters;
  
	typedef std::list<Atlas::Factory*> FactoryCodecs;
    typedef std::list<Atlas::Factory*> FactoryFilters;

    FactoryCodecs outCodecs;
    FactoryFilters outFilters;
    NegotiateHelper<Atlas::Factory> codecHelper;
    NegotiateHelper<Atlas::Factory> filterHelper;
    
	std::string buf;

    void processServerCodecs();
    void processServerFilters();

    void processClientCodecs();
    void processClientFilters();
};
 
class StreamAccept : public Atlas::Negotiate<std::iostream>
{
    public:

	StreamAccept(const std::string& name, std::iostream&, Atlas::Bridge*);

    virtual ~StreamAccept() {}

    virtual void Poll(bool can_read = true);

    virtual State GetState();
    virtual Atlas::Codec<std::iostream>* GetCodec();

    private:

    enum
    {
	SERVER_GREETING,
	CLIENT_GREETING,
	CLIENT_CODECS,
	SERVER_CODECS,
	CLIENT_FILTERS,
	SERVER_FILTERS,
	DONE
    };

    int state;

    std::string outName;
    std::string inName;
	std::iostream& socket;
    Atlas::Bridge* bridge;
    std::list<std::string> inCodecs;
    std::list<std::string> inFilters;
  
	typedef std::list<Atlas::Factory*> FactoryCodecs;
    typedef std::list<Atlas::Factory*> FactoryFilters;

    FactoryCodecs outCodecs;
    FactoryFilters outFilters;
    NegotiateHelper<Atlas::Factory> codecHelper;
    NegotiateHelper<Atlas::Factory> filterHelper;
	
    std::string buf;

    void processServerCodecs();
    void processServerFilters();

    void processClientCodecs();
    void processClientFilters();
};

} } // Atlas::Net

#endif

