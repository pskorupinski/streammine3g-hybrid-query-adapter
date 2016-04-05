/*
 * EndOfStreamHandler.h
 *
 *  Created on: Apr 27, 2013
 *      Author: ubuntu
 */

#ifndef ENDOFSTREAMHANDLER_H_
#define ENDOFSTREAMHANDLER_H_

#include <log4cxx/logger.h>
#include <streammine3G/Operator.hpp>
#include <string.h>

using streammine3G::Collector;

#define ENDOFSTREAM "[EOS]\0"
#define ENDOFSTREAM_L 6

class EndOfStreamHandler
{
public:
	static void sendEndOfStream(Collector* collector, int64_t timestamp, int key = -1);

	static bool checkEndOfStream(char* chBuff, int size);
	static void handleEndOfStream(Collector* collector);
};

#endif /* ENDOFSTREAMHANDLER_H_ */
