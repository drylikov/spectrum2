/**
 * Spectrum 2 Slack Frontend
 *
 * Copyright (C) 2015, Jan Kaluza <hanzz.k@gmail.com>
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

#include "transport/RosterManager.h"

#include <string>
#include <algorithm>
#include <map>

#include "Swiften/Network/Timer.h"

namespace Transport {

class Buddy;
class User;
class Component;
class StorageBackend;
class RosterStorage;

class SlackRosterManager : public RosterManager {
	public:
		SlackRosterManager(User *user, Component *component);

		virtual ~SlackRosterManager();

		virtual void doRemoveBuddy(Buddy *buddy);
		virtual void doAddBuddy(Buddy *buddy);
		virtual void doUpdateBuddy(Buddy *buddy);

		void sendOnlineBuddies();

	private:
		RosterStorage *m_rosterStorage;
		User *m_user;
		Component *m_component;
		Swift::Timer::ref m_onlineBuddiesTimer;
		std::string m_onlineBuddies;
};

}
