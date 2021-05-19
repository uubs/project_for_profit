ALL:queue

list: input_key.c list_init.c list_sort.c variant.c list_print.c main.c variant.h list.h
	gcc input_key.c list_init.c list_sort.c list_print.c variant.c main.c -o list_variant -g

queue: list_queue.c list_queue.h list_init.c list.h variant_4.c
	gcc list_init.c list_queue.c variant_4.c -o variant_4 -g
