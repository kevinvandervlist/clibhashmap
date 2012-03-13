/**
 * Hash a key (char*) to a certain value.
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

#include "include/clibhashmap_hash.h"

#include <stdint.h>
#include <stdlib.h>

/* https://en.wikipedia.org/wiki/Jenkins_hash_function */
int jenkins_one_at_a_time(char *key, size_t len) {
	uint32_t hash, i;
	for(hash = i = 0; i < len; ++i) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (int)hash;
}

/**
 * Return a hash, based on key and (bucket)length.
 */

int clibhashmap_hash(char *key, int len) {
	return jenkins_one_at_a_time(key, 32) & (len - 1);
}
