# Set all sourcefiles, and store them in CHASHMAP_LIB_SRC
SET(CHASHMAP_LIB_SRC 
	clibhashmap.c 
	clibhashmap_data.c
	clibhashmap_hash.c
	clibhashmap_iterator.c
	clibhashmap_put.c
	clibhashmap_retrieval.c
) 

ADD_LIBRARY(chashmap SHARED ${CHASHMAP_LIB_SRC})
