/**
 * A test to determine of the size of the hashmap is correct.
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

#define SIZE 15

int main() {
	// Prepare the hashmap.
	CLHM *hashmap = NULL;
	hashmap = clhm_init(SIZE);

	unsigned int size = 0;
	hashmap->get_hashmap_size(hashmap, &size);
	assert(size == SIZE);

	clhm_destroy(hashmap);
	return 0;
}
