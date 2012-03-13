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

#ifndef CLIBHASHMAP_H
#define CLIBHASHMAP_H

/**
 * The hashmap itself.
 */

typedef struct _hashmap CLHM;

typedef struct _hashmap {
	/* Put a pointer in the map with the given key */
	void (*put)(CLHM *map, char *key, void *ptr);

	/* Get an entry from the hashmap by it's key */
	void* (*get_key)(CLHM *map, char* key);

	/* Remove an entry from the hashmap by it's key, and return it. */
	void* (*remove_key)(CLHM *map, char* key);

	/* Private data of the hashmap. Do not touch. */
	void* priv;

} CLHM;

/* Init a hashmap with size n */
CLHM *clhm_init(int n);

/* Destroy a hashmap. */
void clhm_destroy(CLHM *map);

#endif
