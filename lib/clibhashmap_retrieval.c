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
 * Return the bucket that's part of given key.
 * If no bucket is found, return NULL
 * @param CLHM *map The hashmap to use.
 * @param char *key The key to do the lookup with.
 * @param int remove If a node needs to be removed.
 */

BUCKET *clhm_get_bucket_from_key(CLHM *map, char *key, int remove) {
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
				if(remove) {
					clhm_free_bucket(b);
					hd->bucket_list[hash] = NULL;
				}
				return b;
			} else {
				return NULL;
			}
		} else {
			// More elements, loop until found.
			BUCKET *prev = NULL;
			while(b != NULL && (strcmp(b->key, key) != 0)) {
				prev = b;
				b = b->next;
			}
			if(b == NULL) {
				return NULL;
			} else if(strcmp(b->key, key) == 0) {
				if(remove) {
					BUCKET *tmp = b;
					// First element?
					if(strcmp(hd->bucket_list[hash]->key, key) == 0) {
						hd->bucket_list[hash] = b->next;
					} else {
						prev->next = b->next;
					}
					clhm_free_bucket(tmp);
				}
				return b;
			}
		}
	}

	return NULL;
}

/**
 * Return an item from the hashmap.
 * @param CLHM *map The hashmap to use.
 * @param char *key The key to do the lookup with.
 */

void *clhm_get_key(CLHM *map, char *key) {
	BUCKET *b = clhm_get_bucket_from_key(map, key, 0);
	if(b != NULL) {
		return b->content;
	}
	return NULL;
}

/**
 * Return an item from the hashmap, and delete it when found.
 * @param CLHM *map The hashmap to use.
 * @param char *key The key to do the lookup with.
 */

void *clhm_remove_key(CLHM *map, char *key) {
	BUCKET *b = clhm_get_bucket_from_key(map, key, 1);
	if(b != NULL) {
		// Decrease the number of entries.
		HASHDATA *hd = (HASHDATA *)map->priv;
		hd->entries--;
		return b->content;
	}
	return NULL;
}
