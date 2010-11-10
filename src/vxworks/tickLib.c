/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <copperplate/panic.h>
#include <vxworks/tickLib.h>
#include "tickLib.h"

struct clockobj wind_clock;

ULONG tickGet(void)
{
	ticks_t ticks;

	if (clockobj_get_date(&wind_clock, &ticks)) {
		warning("%s: failed to read clock", __FUNCTION__);
		return (ULONG)-1;
	}

	return (ULONG)ticks;
}

void tickSet(ULONG ticks)
{
	if (clockobj_set_date(&wind_clock, ticks, 0))
		warning("%s: failed to set clock", __FUNCTION__);
}