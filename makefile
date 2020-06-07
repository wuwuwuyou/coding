ALL:encoder decoder 
encoder: encoder.c fun.h timing.h lteration3.h lteration4.h lteration5.h 
	g++ -o encoder encoder.c
decoder: decoder.c fun.h timing.h lteration3.h lteration4.h lteration5.h
	gcc -o decoder decoder.c -lm
