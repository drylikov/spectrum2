#ifndef DIRECT_MESSAGE
#define DIRECT_MESSAGE

#include "transport/ThreadPool.h"
#include "../TwitterResponseParser.h"
#include "../libtwitcurl/twitcurl.h"
#include "transport/Logging.h"
#include <string>
#include <boost/function.hpp>
#include <iostream>

using namespace Transport;

class DirectMessageRequest : public Thread
{
	twitCurl *twitObj;
	std::string data;
	std::string user;
	std::string username;
	std::string replyMsg;
	boost::function< void (std::string&, std::string &, std::vector<DirectMessage>&, Error&) > callBack;
	std::vector<DirectMessage> messages;
	bool success;

	public:
	DirectMessageRequest(twitCurl *obj, const std::string &_user, const std::string & _username, const std::string &_data,
			     		boost::function< void (std::string&, std::string &, std::vector<DirectMessage>&, Error&) >  cb) {
		twitObj = obj->clone();
		data = _data;
		user = _user;
		username = _username;
		callBack = cb;
	}

	~DirectMessageRequest() {
		delete twitObj;
	}

	void run();
	void finalize();
};

#endif
