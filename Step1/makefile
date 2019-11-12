
# cphex\makefile

LIBS=
all:	admin	LibSerNMBB.o


LibSerNMBB.o:	LibSerNMBB.c	LibSerNMBB.h	data.h	
	echo "compilation de LibSerNMBB"
	gcc -c LibSerNMBB.c

admin:	data.h	admin.c	LibSerNMBB.o			
	echo "Compilation de admin"
	gcc -o admin	admin.c	LibSerNMBB.o 

