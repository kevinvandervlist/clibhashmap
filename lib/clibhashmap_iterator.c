/**
 * Iterator data.
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

#include "include/clibhashmap_iterator.h"

#include <stdlib.h>

#include "include/clibhashmap_bucket.h"
#include "include/clibhashmap_data.h"

CLHM_ITR *clhm_get_new_iterator(char *key, void *value) {
	CLHM_ITR *itr = malloc(sizeof(CLHM_ITR));
	itr->next = clhm_iterator_next;

	itr->key = key;
	itr->value = value;
	itr->priv = NULL;

	return itr;
}

CLHM_ITR* clhm_iterator_next(CLHM_ITR *itr) {
	if(itr == NULL) {
		return NULL;
	}
	CLHM_ITR *p = itr->priv;
	free(itr);
	return p;
}

CLHM_ITR* clhm_get_iterator(CLHM *map) {
	HASHDATA *hd = (HASHDATA *)map->priv;
	CLHM_ITR *head = NULL;
	CLHM_ITR *cur;
	unsigned int i;
	BUCKET *b;

	/**
	 * Create a linked list with all items in it.
	 */

	for(i = 0; i < hd->size; i++) {
		b = hd->bucket_list[i];
		while(b != NULL) {
			if(head  == NULL) {
				head = clhm_get_new_iterator(b->key, b->content);
				cur = head;
			} else {
				cur->priv = clhm_get_new_iterator(b->key, b->content);
				cur = cur->priv;
			}
			b = b->next;
		}
	}

	return head;
}


