/* packet-dvb-tdt.c
 * Routines for DVB (ETSI EN 300 468) Time and Date Table (TDT) dissection
 * Copyright 2012, Guy Martin <gmsoft@tuxicoman.be>
 *
 * $Id: packet-dvb-tdt.c 41766 2012-03-26 14:08:39Z morriss $
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; tdther version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <glib.h>

#include <epan/packet.h>
#include <epan/dissectors/packet-mpeg-sect.h>

static int proto_dvb_tdt = -1;
static int hf_dvb_tdt_utc_time = -1;

static gint ett_dvb_tdt = -1;

#define DVB_TDT_TID	0x70

static void
dissect_dvb_tdt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{

	guint offset = 0;

	proto_item *ti = NULL;
	proto_tree *dvb_tdt_tree = NULL;

	nstime_t utc_time;

	col_clear(pinfo->cinfo, COL_INFO);
	col_set_str(pinfo->cinfo, COL_INFO, "Time and Date Table (TDT)");

	if (!tree)
		return;

	ti = proto_tree_add_item(tree, proto_dvb_tdt, tvb, offset, -1, ENC_NA);
	dvb_tdt_tree = proto_item_add_subtree(ti, ett_dvb_tdt);

	offset += packet_mpeg_sect_header(tvb, offset, dvb_tdt_tree, NULL, NULL);

	if (packet_mpeg_sect_mjd_to_utc_time(tvb, offset, &utc_time) < 0) {
		proto_tree_add_text(dvb_tdt_tree, tvb, offset, 5, "Unparseable time");
	} else {
		proto_tree_add_time_format(dvb_tdt_tree, hf_dvb_tdt_utc_time, tvb, offset, 5, &utc_time,
			"UTC Time : %s UTC", abs_time_to_str(&utc_time, ABSOLUTE_TIME_UTC, FALSE));
	}
}


void
proto_register_dvb_tdt(void)
{

	static hf_register_info hf[] = {

		{ &hf_dvb_tdt_utc_time, {
			"UTC Time", "dvb_tdt.utc_time",
			FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL
		} }
	};

	static gint *ett[] = {
		&ett_dvb_tdt
	};

	proto_dvb_tdt = proto_register_protocol("DVB Time and Date Table", "DVB TDT", "dvb_tdt");

	proto_register_field_array(proto_dvb_tdt, hf, array_length(hf));
	proto_register_subtree_array(ett, array_length(ett));

}


void proto_reg_handoff_dvb_tdt(void)
{
	dissector_handle_t dvb_tdt_handle;

	dvb_tdt_handle = create_dissector_handle(dissect_dvb_tdt, proto_dvb_tdt);

	dissector_add_uint("mpeg_sect.tid", DVB_TDT_TID, dvb_tdt_handle);
}
