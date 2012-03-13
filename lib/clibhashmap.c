/**
 * Public API of the clibhashmap.
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

#include "clibhashmap.h"

#include <stdlib.h>

#include "include/clibhashmap_bucket.h"
#include "include/clibhashmap_data.h"
#include "include/clibhashmap_hash.h"
#include "include/clibhashmap_put.h"
#include "include/clibhashmap_retrieval.h"

CLHM *clhm_init(int size) {
	CLHM *ret = malloc(sizeof(CLHM));
	
	ret->put = clhm_put;
	ret->get_key = clhm_get_key;
	ret->remove_key = clhm_remove_key;
	ret->get_hashmap_size = clhm_get_hashmap_size;
	ret->get_no_entries = clhm_get_no_entries;

	HASHDATA *hd = clhm_init_private_data(size);
	ret->priv = hd;

	return ret;
}

void clhm_destroy(CLHM *map) {
	HASHDATA *hd = (HASHDATA *)map->priv;
	int i;

	// Iterate over all elements in the hashmap, and delet them.
	for(i = 0; i < hd->size; i++) {
		BUCKET *bucket = hd->bucket_list[i];
		BUCKET *b;
		while(bucket != NULL) {
			b = bucket;
			bucket = bucket->next;

			clhm_free_bucket(b);
		}
	}

	// Free the hashdata struct itself
	free(hd);

	//finally, free the map
	free(map);
}

