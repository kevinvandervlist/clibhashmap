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

#ifndef CLIBHASHMAP_DATA_H
#define CLIBHASHMAP_DATA_H

#include <clibhashmap.h>
#include "clibhashmap_bucket.h"

typedef struct _hashdata {
	unsigned int size;
	unsigned int entries;
	BUCKET *bucket_list[];
} HASHDATA;

BUCKET *clhm_get_new_bucket(char *key, void *ptr);
HASHDATA *clhm_init_private_data(int hashsize);
void clhm_free_bucket(BUCKET *b);
void clhm_get_hashmap_size(CLHM *map, unsigned int *size);
void clhm_get_no_entries(CLHM *map, unsigned int *entries);

#endif
