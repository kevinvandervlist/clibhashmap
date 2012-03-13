 # Makefile to compile clibhashmap
 # Copyright (C) 2012 Kevin van der Vlist
 #
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program. If not, see <http://www.gnu.org/licenses/>.
 #
 # Kevin van der Vlist - kevin@kevinvandervlist.nl

#CFLAGS = -Wall -Werror -Wextra 
CFLAGS =

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

CC=gcc
LN=ln
LIBNAME=libhashmap
RM=rm -f

all: clibhashmap

debug: CFLAGS += -DDEBUG -g -ggdb
debug: clibhashmap

clibhashmap: clean
	$(CC) -c -fPIC $(SOURCES) $(CFLAGS)
	$(CC) -shared -Wl,-soname,$(LIBNAME).so.1 -o $(LIBNAME).so.1.0.1 $(OBJECTS)
	$(LN) -s $(LIBNAME).so.1.0.1 $(LIBNAME).so
	$(LN) -s $(LIBNAME).so.1.0.1 $(LIBNAME).so.1

clean: 
	@$(RM) $(LIBNAME).so
	@$(RM) $(LIBNAME).so.1
	@$(RM) $(LIBNAME).so.1.0.1
	@$(RM) $(wildcard *.o)
