
CFLAGS=-ansi -pedantic -Wall -std=c89 
CC=gcc

all: analisis_ventas clear 

analisis_ventas: main.o funciones_archivo.o funciones_cadenas.o funciones_cliente.o funciones_impresion.o funciones_linea.o funciones_error.o
	$(CC) $(CFLAGS) -o analisis_ventas main.o funciones_archivo.o funciones_cadenas.o funciones_cliente.o funciones_impresion.o funciones_linea.o funciones_error.o

main.o: main.c funciones_archivo.h  funciones_cliente.h funciones_impresion.h  funciones_linea.h funciones_error.h
	$(CC) $(CFLAGS) -o main.o -c main.c

funciones_archivo.o: funciones_archivo.c funciones_archivo.h 
	$(CC) $(CFLAGS) -o funciones_archivo.o -c funciones_archivo.c 

funciones_cadenas.o: funciones_cadenas.c funciones_cadenas.h
	$(CC) $(CFLAGS) -o funciones_cadenas.o -c funciones_cadenas.c

funciones_impresion.o: funciones_impresion.c funciones_impresion.h
	$(CC) $(CFLAGS) -o funciones_impresion.o -c funciones_impresion.c

funciones_linea.o: funciones_linea.c funciones_linea.h 
	$(CC) $(CFLAGS) -o funciones_linea.o -c funciones_linea.c

funciones_cliente.o: funciones_cliente.c  funciones_cliente.h
	$(CC) $(CFLAGS) -o funciones_cliente.o -c funciones_cliente.c	

funciones_error.o: funciones_error.c  funciones_error.h
	$(CC) $(CFLAGS) -o funciones_error.o -c funciones_error.c		
	

clear:
	rm *.o

install: 
	cp analisis_ventas ../analisis_ventas