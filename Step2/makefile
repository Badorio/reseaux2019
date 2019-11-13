.SILENT:
# cphex\makefile

LIBS= -lsocket -lnsl
all:	admin	LibSerNMBB.o ser cli udplib.o


LibSerNMBB.o:	LibSerNMBB.c	LibSerNMBB.h	data.h	
	echo "compilation de LibSerNMBB"
	gcc -c LibSerNMBB.c

admin:	data.h	admin.c	LibSerNMBB.o			
	echo "Compilation de admin"
	gcc -o admin	admin.c	LibSerNMBB.o 

udplib.o:	../udplib/udplib.h	../udplib/udplib.c
	echo "Compilation de udplib.o"
	gcc -c ../udplib/udplib.c

cli: cli.c udplib.o
	echo "Compilation de cli.o"
	gcc -c cli cli.c udplib.o	$(LIBS)

ser:	ser.c	udplib.o
	echo "Compilation de ser.o"
	gcc -c ser ser.c udplib.o $(LIBS)