/**
 * Check if duplicates can be inserted.
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
	unsigned int entries = 0;

	// Make up some data.
	char *one = "one";
	int one_int = 1;

	char *two = "two";
	int two_int = 2;

	char *three = "three";
	char *string = "STRING";

	hashmap->put(hashmap, one, (void *)&one_int);
	hashmap->put(hashmap, two, (void *)&two_int);

	hashmap->get_no_entries(hashmap, &entries);
	assert(entries == 2);

	// trying to dup
	hashmap->put(hashmap, one, (void *)&one_int);
	hashmap->get_no_entries(hashmap, &entries);
	assert(entries == 2);

	// But new entries do work.
	hashmap->put(hashmap, three, (void *)string);
	hashmap->get_no_entries(hashmap, &entries);
	assert(entries == 3);

	clhm_destroy(hashmap);
	return 0;
}
