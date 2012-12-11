/*
 * brickd
 * Copyright (C) 2012 Matthias Bolte <matthias@tinkerforge.com>
 *
 * packet.c: Packet definiton for protocol version 2
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "packet.h"

#include "log.h"

int packet_header_is_valid_for_request(PacketHeader *header,
                                       const char **message) {
	if (header->length < (int)sizeof(PacketHeader)) {
		*message = "Length is too small";

		return 0;
	}

	if (header->function_id == 0) {
		*message = "Invalid function ID";

		return 0;
	}

	if (header->sequence_number == 0) {
		*message = "Invalid sequence number";

		return 0;
	}

	return 1;
}
