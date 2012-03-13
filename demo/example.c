/**
 * A minimal hashmap example.
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

#include <stdlib.h>
#include <stdio.h>

#include <clibhashmap.h>

int main() {
	// Prepare the hashmap.
	CLHM *hashmap = NULL;
	hashmap = clhm_init(12);

	// Make up some data.
	char *one = "one";
	int one_int = 1;

	char *two = "two";
	int two_int = 2;

	char *three = "three";
	char *string = "STRING";

	char *four = "this_doesn't_exist";

	// Store some data.
	hashmap->put(hashmap, one, (void *)&one_int);
	hashmap->put(hashmap, two, (void *)&two_int);
	hashmap->put(hashmap, three, (void *)string);

	// Retrieving an item.
	// Do not forget to cast pointer to correct value.
	void *iptr = hashmap->get_key(hashmap, one);
	printf("iptr: %d\n", *(int *)iptr);

	void *sptr = hashmap->get_key(hashmap, three);
	printf("sptr: %s\n", (char *)sptr);

	void *nptr = hashmap->get_key(hashmap, four);

	if(nptr == NULL) {
		printf("nptr: NULL: not found\n");
	} else {
		// nptr == NULL when no entry is found.
		printf("nptr: This can't be reached.\n");
	}

	clhm_destroy(hashmap);
}
