/**
 * Retrieval functions of the hashmap.
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

#include "include/clibhashmap_retrieval.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#include "include/clibhashmap_bucket.h"
#include "include/clibhashmap_data.h"
#include "include/clibhashmap_hash.h"

/**
 * Return an item from the hashmap.
 * @param CLHM *map The hashmap to use.
 * @param char *key The key to do the lookup with.
 */

void *clhm_get_key(CLHM *map, char *key) {
	HASHDATA *hd = (HASHDATA *)map->priv;

	int hash = clibhashmap_hash(key, hd->size);
	
	// Not found - return
	if(hd->bucket_list[hash] == NULL) {
		return NULL;
	} else {
		BUCKET *b = hd->bucket_list[hash];
		if(b->next == NULL) {
			// Only one element in list - return it if key is equal.
			if (strcmp(b->key, key) == 0) {
				return b->content;
			} else {
				return NULL;
			}

		} else {

			// More elements, loop until found.
			while(b != NULL && (strcmp(b->key, key) != 0)) {
				b = b->next;
			}
			if(b == NULL) {
				return NULL;
			} else if(strcmp(b->key, key) == 0) {
				return b->content;
			}
		}
	}

	return NULL;
}

void *clhm_remove_key(CLHM *map, char *key) {

}
