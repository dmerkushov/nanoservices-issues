/*
 * Copyright 2019 dmerkushov.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * File:   NsRpcResponse.h
 * Author: dmerkushov
 *
 * Created on May 14, 2019, 3:31 PM
 */

#ifndef NSRPCRESPONSE_H
#define NSRPCRESPONSE_H

#include <memory>

#include "NsSerializer.h"

namespace nanoservices {

	class NsRpcResponse {
	public:
		NSSERIALIZER_PREPARE_SYS (_success, _result);

		NsRpcResponse();

		NsRpcResponse(const NsRpcResponse &orig);

		virtual ~NsRpcResponse();

		bool success();

		void setSuccess(bool success);

		NsSerialized &result();

		void setResult(NsSerialized &result);

	private:
		bool _success;
		NsSerialized _result;
	};
}

#endif /* NSRPCRESPONSE_H */

