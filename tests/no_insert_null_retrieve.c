/**
 * Check if items that aren't inserted result in NULL.
 * Copyright (C) 2012 Kevin van der Vlist
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Kevin van der Vlist - kevin@kevinvandervlist.nl
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <clibhashmap.h>

int main() {
	// Prepare the hashmap.
	CLHM *hashmap = NULL;
	hashmap = clhm_init(15);

	// Make up some data.
	char *one = "one";

	char *two = "two";

	char *three = "three";

	// Retrieving items : ints
	void *iptr = hashmap->get_key(hashmap, one);
	assert(iptr == NULL);

	iptr = hashmap->get_key(hashmap, two);
	assert(iptr == NULL);

	// Retrieving items : string
	void *sptr = hashmap->get_key(hashmap, three);
	assert(sptr == NULL);

	clhm_destroy(hashmap);
	return 0;
}
