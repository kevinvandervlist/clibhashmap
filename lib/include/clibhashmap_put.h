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

#ifndef CLIBHASHMAP_PUT_H
#define CLIBHASHMAP_PUT_H

#include <clibhashmap.h>

void clhm_put_str(CLHM *map, char *key, void *ptr);
void clhm_put_int(CLHM *map, int *key, void *ptr);

#endif
