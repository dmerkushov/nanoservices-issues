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
 * File:   NsSkeleton.h
 * Author: dmerkushov
 *
 * Created on June 21, 2019, 4:03 PM
 */

#ifndef NSSKELETON_H
#define NSSKELETON_H

#include <memory>
#include <string>

// DEBUG
#include <iostream>

#include <cstdint>

#include "NsException.h"
#include "NsSkelRpcReplierInterface.h"
#include "NsSkelRpcServer.h"

namespace nanoservices {

class NsSkeleton {
public:

	/**
	 * Initialize NsSkeleton infrastructure for a given service name
	 * @param serviceName
	 */
	static void init (const std::string &serviceName, const std::string &configName = "") throw (NsException);

	/**
	 * Start the previously-initialized nanoservice
	 */
	static void startup () throw (NsException);

	/**
	 * Shut down the previously-initialized nanoservice
	 */
	static void shutdown () throw (NsException);

	/**
	 * Get the current service name
	 * @return
	 */
	static std::shared_ptr<std::string> serviceName () throw (NsException);

	/**
	 * Sleep while the current nanoservice is active
	 */
	static void sleepWhileActive () throw (NsException);

	/**
	 * Register a replier for a nanoservice method
	 */
	static void registerReplier (std::shared_ptr<NsSkelRpcReplierInterface> replier) throw (NsException);
	
	/**
	 * Unregister the replier previously registered for a nanoservice method
	 */
	static void unregisterReplier (std::shared_ptr<std::string> methodName) throw (NsException);

	template<typename Args, typename Result>
	static std::shared_ptr<Result> call (std::shared_ptr<std::string> serviceName, std::shared_ptr<std::string> methodName, std::shared_ptr<Args> args, bool waitForResponse) throw (NsException) {

		return nanoservices::sendRpcRequest<Args, Result> (serviceName, methodName, args, waitForResponse);
	}

	template<typename Args, typename Result>
	static std::shared_ptr<Result> call (const std::string &serviceName, const std::string &methodName, std::shared_ptr<Args> args, bool waitForResponse) throw (NsException) {

		std::shared_ptr<std::string> serviceNamePtr = std::make_shared<std::string> (serviceName);
		std::shared_ptr<std::string> methodNamePtr = std::make_shared<std::string> (methodName);

		return nanoservices::sendRpcRequest<Args, Result> (serviceNamePtr, methodNamePtr, args, waitForResponse);
	}

	template<typename Args, typename Result>
	static std::shared_ptr<Result> call (const char *serviceName, const char *methodName, std::shared_ptr<Args> args, bool waitForResponse) throw (NsException) {

		std::shared_ptr<std::string> serviceNamePtr = std::make_shared<std::string> (serviceName);
		std::shared_ptr<std::string> methodNamePtr = std::make_shared<std::string> (methodName);

		return nanoservices::sendRpcRequest<Args, Result> (serviceNamePtr, methodNamePtr, args, waitForResponse);
	}
};

}

#endif /* NSSKELETON_H */

