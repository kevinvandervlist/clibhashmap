/**
 * Private data of a hashmap.
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

#include "include/clibhashmap_data.h"

#include <stdlib.h>
#include <string.h>

#include "include/clibhashmap_bucket.h"

HASHDATA *clhm_init_private_data(int hashsize) {
	HASHDATA *hd = NULL;
	/* Allocate enough memory for HASHDATA + (hashsize * bucketsize) */
	hd = malloc(sizeof(*hd) + (hashsize * sizeof(*hd->bucket_list)));
	int i;
	
	hd->size = hashsize;
	hd->entries = 0;

	for (i = 0; i < hashsize; i++) {
		hd->bucket_list[i] = NULL;
	}

	return hd;
}

/**
 * Return the size of the hashmap
 * @param CLHM *map The hashmap.
 * @param int *size The size can be stored here.
 */

void clhm_get_hashmap_size(CLHM *map, unsigned int *size) {
	HASHDATA *hd = (HASHDATA *)map->priv;
	*size = hd->size;
}

/**
 * Return the no entries in the hashmap.
 * @param CLHM *map The hashmap.
 * @param int *size The entries can be stored here.
 */
		
void clhm_get_no_entries(CLHM *map, unsigned int *entries) {
	HASHDATA *hd = (HASHDATA *)map->priv;
	*entries = hd->entries;
}

BUCKET *clhm_get_new_bucket(char *key, void *ptr) {
	BUCKET *b = malloc(sizeof(struct _bucket));

	b->next = NULL;
	b->content = ptr;

	b->key = malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(b->key, key);
	return b;
}

void clhm_free_bucket(BUCKET *b) {
	free(b->key);
	free(b);
}
