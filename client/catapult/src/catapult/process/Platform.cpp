/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#include "Platform.h"
#include "catapult/utils/Logging.h"

#ifndef _WIN32
#include <sys/stat.h>
#include <sys/types.h>
#endif

namespace catapult { namespace process {

	void PlatformSettings() {
#ifndef _WIN32
		constexpr auto Required_Umask = S_IRWXG | S_IRWXO;
		auto previousUmask = umask(Required_Umask);

		// check group and other mask
		if (Required_Umask != previousUmask) {
			CATAPULT_LOG(warning)
					<< std::endl << "\tCurrent user umask settings are too wide '" << std::oct << previousUmask << "'."
					<< std::endl << "\tIt's strongly suggested to use umask value '077' when starting symbol software.";
		}
#endif
	}
}}