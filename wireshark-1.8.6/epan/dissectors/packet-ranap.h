/* Do not modify this file.                                                   */
/* It is created automatically by the ASN.1 to Wireshark dissector compiler   */
/* packet-ranap.h                                                             */
/* ../../tools/asn2wrs.py -p ranap -c ./ranap.cnf -s ./packet-ranap-template -D . -O ../../epan/dissectors RANAP-CommonDataTypes.asn RANAP-Constants.asn RANAP-Containers.asn RANAP-IEs.asn RANAP-PDU-Contents.asn RANAP-PDU-Descriptions.asn */

/* Input file: packet-ranap-template.h */

#line 1 "../../asn1/ranap/packet-ranap-template.h"
/* packet-ranap-template.h
 * Routines for GSM Supplementary Services dissection
 * Copyright 2005, Anders Broman <anders.broman@ericsson.com>
 * $Id: packet-ranap.h 40119 2011-12-08 21:17:03Z etxrab $ *
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef PACKET_RANAP_H
#define PACKET_RANAP_H

/*--- Included file: packet-ranap-exp.h ---*/
#line 1 "../../asn1/ranap/packet-ranap-exp.h"
extern const value_string ranap_Service_Handover_vals[];
int dissect_ranap_EncryptionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_);
int dissect_ranap_IntegrityProtectionInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_);
int dissect_ranap_Service_Handover(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_);
int dissect_ranap_TargetRNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_);
int dissect_ranap_SourceCellID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_);
int dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_);
int dissect_ranap_TargetRNC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_);
int dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_);

/*--- End of included file: packet-ranap-exp.h ---*/
#line 27 "../../asn1/ranap/packet-ranap-template.h"

#endif  /* PACKET_RANAP_H */
