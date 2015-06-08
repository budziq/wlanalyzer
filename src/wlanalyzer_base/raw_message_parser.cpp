/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Samsung Electronics
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "common.h"
#include "raw_message.h"
#include "raw_message_parser.h"
#include "message_aggregator.h"
#include <cstring>

namespace WlAnalyzer {

RawMessageParser::RawMessageParser()
{

}

void RawMessageParser::processMessage(const shared_ptr<const RawMessage> &message)
{
	auto &data = message->data();

	if (!message_complete_)
	{
		/** @todo finish this part
		 */
	}

	uint32_t obj_id;
	memcpy(&obj_id, &data[0], sizeof(obj_id));
	uint16_t msg_size;
	memcpy(&msg_size, &data[6], sizeof(msg_size));

	MessageAggregator::instance()->addObject(obj_id);
}

}
