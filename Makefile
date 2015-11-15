project: main.o random.o sudoko.o
	cc main.o random.o sudoko.o -Wall -o project
main.o: main.c
	cc main.c -c
random.o: random.c
	cc random.c -c 
sudoko.o: sudoko.c
	cc sudoko.c -c
