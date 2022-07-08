/**
 * libtransport -- C++ library for easy XMPP Transports development
 *
 * Copyright (C) 2011, Jan Kaluza <hanzz.k@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#pragma once

#include <string>
#include <map>

#include "Swiften/Elements/Message.h"

namespace Transport {

class Component;
class StorageBackend;
class UserManager;
class NetworkPluginServer;
class UserRegistration;
class AdminInterfaceCommand;

class AdminInterface {
	public:
		AdminInterface(Component *component, UserManager *userManager, NetworkPluginServer *server = NULL, StorageBackend *storageBackend = NULL, UserRegistration *userRegistration = NULL);

		~AdminInterface();

		void handleQuery(Swift::Message::ref message);

		void addCommand(AdminInterfaceCommand *command);

		void handleMessageReceived(Swift::Message::ref message);

	private:

		Component *m_component;
		StorageBackend *m_storageBackend;
		UserManager *m_userManager;
		NetworkPluginServer *m_server;
		UserRegistration *m_userRegistration;
		std::map<std::string, AdminInterfaceCommand *> m_commands;
};

}
