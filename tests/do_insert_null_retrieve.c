/**
 * Check if items that are inserted can be found, and 
 * non-inserted stuff is NULL
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
	int one_int = 1;

	char *two = "two";
	int two_int = 2;

	char *three = "three";
	char *string = "STRING";

	char *n_str = "BLA";

	hashmap->put(hashmap, one, (void *)&one_int);
	hashmap->put(hashmap, two, (void *)&two_int);
	hashmap->put(hashmap, three, (void *)string);

	// Retrieving items : ints
	void *iptr = hashmap->get_key(hashmap, one);
	assert(*(int *)iptr == one_int);

	iptr = hashmap->get_key(hashmap, two);
	assert(*(int *)iptr != one_int);
	assert(*(int *)iptr == two_int);

	// Retrieving items : string
	void *sptr = hashmap->get_key(hashmap, three);
	assert(strcmp((char*)sptr, string) == 0);

	// Retrieving non-existing key
	sptr = hashmap->get_key(hashmap, n_str);
	assert(sptr == NULL);

	clhm_destroy(hashmap);
	return 0;
}
