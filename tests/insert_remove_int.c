/**
 * A test to insert items in the hashmap, and check if they can be removed.
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
	int one = 1;
	char *a = "First string";

	int two = 2;
	char *b = "Second string";

	int three = 3;
	char *c = "Third string";


	// Store some data.
	hashmap->put_int(hashmap, &one, (void *)a);
	hashmap->put_int(hashmap, &two, (void *)b);
	hashmap->put_int(hashmap, &three, (void *)c);

	// Retrieving items : ints
	void *sptr = hashmap->remove_key_int(hashmap, &one);
	assert(strcmp((char*)sptr, a) == 0);
	sptr = hashmap->remove_key_int(hashmap, &one);
	assert(sptr == NULL);

	sptr = hashmap->remove_key_int(hashmap, &two);
	assert(strcmp((char*)sptr, b) == 0);
	sptr = hashmap->remove_key_int(hashmap, &two);
	assert(sptr == NULL);

	sptr = hashmap->remove_key_int(hashmap, &three);
	assert(strcmp((char*)sptr, c) == 0);
	sptr = hashmap->remove_key_int(hashmap, &three);
	assert(sptr == NULL);



	clhm_destroy(hashmap);
	return 0;
}
