/* packetlogger.h
 *
 * $Id: packetlogger.h 37543 2011-06-04 21:20:57Z rbalint $
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 * 
 */

#ifndef __PACKETLOGGER_H__
#define __PACKETLOGGER_H__

#include <glib.h>
#include <wtap.h>

int packetlogger_open(wtap *wth, int *err, gchar **err_info _U_);

#endif /* __PACKETLOGGER_H__ */

