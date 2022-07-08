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

#include "purple.h"
#include <string>

#ifndef WIN32
void spectrum_sigchld_handler(int sig);
#endif

int create_socket(const char *host, int portno);
GHashTable *spectrum_ui_get_info(void);

void execute_purple_plugin_action(PurpleConnection *gc, const std::string &name);

#ifdef _WIN32
	std::wstring utf8ToUtf16(const std::string& str);
#endif
