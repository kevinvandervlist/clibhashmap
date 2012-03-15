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
 * This header defines the whole public API of clibhashmap. 
 * All than can be done from outside the library is listed 
 * in the following definitions. 
 *
 * The hasmap can be used to store items, using a (key,value) 
 * pair. The key should be a standard C-string and will be hashed.
 * The value can be an arbitrary pointer. The caller of the library 
 * (henceforth callee) should take note of the original datatype,
 * so it can be casted back.
 *
 * The callee is also responsible for free() and malloc()'ing of the 
 * memory regions the pointers in the hashmap point to.
 * In other words, when the callee puts a pointer in the hashmap, 
 * then free()'s it's memory region, and requests the pointer again,
 * the pointer will be roque.
 * 
 * Also, putting a lot of pointers in the hashmap, and then finish 
 * using the hashmap with a call to clhm_destroy() will NOT free any 
 * data put into the hashmap by the callee. It will just be lost.
 *
 * Last but not least - this hashmap is currently NOT thread safe.
 *
 * To finish up, here is a small example of the hashmap:
 *
 * CLHM *hashmap = NULL;
 * hashmap = clhm_init(15);
 *
 * char *one = "one";
 * int one_int = 1;
 * char *two = "two";
 * int two_int = 2;
 *
 * hashmap->put(hashmap, one, (void *)&one_int);
 * hashmap->put(hashmap, two, (void *)&two_int);
 * 
 * void *iptr = hashmap->get_key(hashmap, one);
 * printf("One: %d\n", *(int *)iptr);
 *
 */

/**
 * First of all, the CLHM typedef'd struct is the hashmap itself.
 * It is made up from a few function pointers, defining the api, 
 * and a void *priv pointer to internal data. Needless to say, 
 * users can't interact with this information.
 */

typedef struct _clhm_hashmap CLHM;

/**
 * The CLHM_ITR struct is used to iterate over the elements of a hashmap.
 * Essentially, this iterator will consist of a collection of pointers available
 * in the hashmap at the precise moment the iterator was created.
 * In other words, it is a kind of snapshot. Changes in the hashmap will NOT
 * be reflected inside the iterator.
 */

typedef struct _clhm_iterator CLHM_ITR;

/**
 * Initialize a new hashmap.
 * 
 * This method should always be the first call when a callee
 * wants to use the hashmap. It should be given a parameter, 
 * @param unsigned int n The number of buckets to use in the hashmap.
 * @return CLHM * Pointer to a new hashmap.
 */

CLHM *clhm_init(unsigned int n);

/**
 * Destroy a given hashmap.
 * 
 * Destroying make sure that all internal data will bee free()'d.
 * After this call, the parametrized pointer can be discarded, all memory is 
 * given back to the OS.
 * @param CLHM * map Pointer to the existing new hashmap, so it will be freed.
 */

void clhm_destroy(CLHM *map);

/**
 * The Hashmap struct itself is used almost as some sort of object.
 * Next to the init and destroy functions, interaction with the hashmap 
 * is done via the following function pointers.
 */

typedef struct _clhm_hashmap {
	/**
	 * To 'put', or insert a new item (key,value) in the hashmap, this function
	 * needs to be called. 
	 * The key value will be used to create a hash from.
	 * @param CLHM *map The hashmap itself.
	 * @param char *key The key of the item to store.
	 * @param void *ptr A pointer to an object to store.
	 */

	void (*put)(CLHM *map, char *key, void *ptr);

	/**
	 * Retrieve an item from the hashmap, locating it via it's key.
	 * @param CLHM *map The hashmap itself.
	 * @param char *key The key of the item to find.
	 * @return void * A pointer to the stored value. Callee is responsible
	 * for issuing a correct cast.
	 */

	void* (*get_key)(CLHM *map, char* key);

	/**
	 * The same as get_key(), but also deletes the entry from the hashmap.
	 * @param CLHM *map The hashmap itself.
	 * @param char *key The key of the item to find.
	 * @return void * A pointer to the stored value. Callee is responsible
	 * for issuing a correct cast.
	 */

	void* (*remove_key)(CLHM *map, char* key);

	/**
	 * Return the size (in buckets) of the given hashmap.
	 * @param CLHM *map The hashmap itself.
	 * @param unsigned int *size A pointer to store the size in.
	 */

	void (*get_hashmap_size)(CLHM *map, unsigned int *size);

	/**
	 * Return the number of entries (data) in the given hashmap.
	 * @param CLHM *map The hashmap itself.
	 * @param unsigned int *size A pointer to store the number of entries in.
	 */

	void (*get_no_entries)(CLHM *map, unsigned int *entries);

	/**
	 * Return an iterator to walk over all items that are currently in the hashmap.
	 * This iterator is like a snapshot of hashmap.
	 * @param CLHM *map The hashmap itself.
	 * @return CLHM_ITR * A pointer to the iterator, set at the first item.
	 */

	CLHM_ITR* (*get_iterator)(CLHM *map);

	/**
	 * Private data of the hashmap. This should not be touched.
	 */

	void *priv;

} CLHM;

/**
 * The iterator to use on the hashmap.
 * Use it to simply iterate over the complete
 * hashmap. The order of items is an arbitrary sequence.
 *
 * A little demo: 
 *	CLHM_ITR *itr = hashmap->get_iterator(hashmap);
 *
 * while(itr != NULL) {
 *   printf("(key,value)::(%s,%d)\n", itr->key, *(int *)itr->value);
 *   itr = itr->next(itr);
 * }
 * 
 * In other words, use the itr->next() call to move to the next item.
 * Cleanup is handled by the library.
 */

typedef struct _clhm_iterator {

	/**
	 * Get the next CLHM_ITR element in line.
	 * If this is the last one, NULL will be returned.
	 * @param GLHM_ITR *itr A pointer to the current iterator.
	 * @return GLHM_ITR *itr A pointer to the next iterator.
	 */

	CLHM_ITR* (*next)(CLHM_ITR *itr);

	/**
	 * The key of the current item in the hashmap.
	 */

	char *key;

	/**
	 * The value of the current item. 
	 * Callee is responsible for correct casting again.
	 */

	void *value;

	/**
	 * Private data of the iterator. This should not be touched.
	 */

	void *priv;
} CLHM_ITR;

#endif
