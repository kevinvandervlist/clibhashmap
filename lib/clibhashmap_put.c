/**
 * Put an it em with a given key in the given hashmap.
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

#include "include/clibhashmap_put.h"

#include <stdlib.h>

#include "include/clibhashmap_bucket.h"
#include "include/clibhashmap_data.h"
#include "include/clibhashmap_hash.h"

/**
 * Insert an item into the hashmap.
 * @param CLHM *map The hashmap to use.
 * @param char *key The key to use for the hashmap.
 * @param void *ptr Pointer to the data to store.
 */

void clhm_put(CLHM *map, char *key, void *ptr) {

	HASHDATA *hd = (HASHDATA *)map->priv;

	int hash = clibhashmap_hash(key, hd->size);
	
	// Empty bucket - create one.
	if(hd->bucket_list[hash] == NULL) {
		hd->bucket_list[hash] = clhm_get_new_bucket(key, ptr);
	} else {
		// Use a chain.
		BUCKET *b = hd->bucket_list[hash];
		BUCKET *cur;

		do {
			cur = b;
			b = b->next;
		} while(b != NULL);

		// Appand it at the right place.
		cur->next = clhm_get_new_bucket(key, ptr);
	}
	return;
}
