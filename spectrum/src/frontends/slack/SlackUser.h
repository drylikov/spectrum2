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

#include "transport/User.h"

#include <time.h>

namespace Transport {

class Component;
class RosterManager;
class ConversationManager;
class UserManager;
class PresenceOracle;
struct UserInfo;
class SlackSession;

class SlackUser : public User {
	public:
		SlackUser(const Swift::JID &jid, UserInfo &userInfo, Component * component, UserManager *userManager);

		virtual ~SlackUser();

		void disconnectUser(const std::string &error, Swift::SpectrumErrorPayload::Error e);

		SlackSession *getSession() {
			return m_session;
		}

	private:
		Swift::JID m_jid;
		Component *m_component;
		UserManager *m_userManager;
		UserInfo m_userInfo;
		SlackSession *m_session;
};

}
