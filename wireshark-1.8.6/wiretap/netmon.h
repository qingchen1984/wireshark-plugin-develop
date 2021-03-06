/* netmon.h
 *
 * $Id: netmon.h 40495 2012-01-14 10:31:25Z guy $
 *
 * Wiretap Library
 * Copyright (c) 1998 by Gilbert Ramirez <gram@alumni.rice.edu>
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __NETMON_H__
#define __NETMON_H__

#include <glib.h>
#include <wtap.h>

int netmon_open(wtap *wth, int *err, gchar **err_info);
gboolean netmon_dump_open(wtap_dumper *wdh, int *err);
int netmon_dump_can_write_encap_1_x(int encap);
int netmon_dump_can_write_encap_2_x(int encap);

#endif
