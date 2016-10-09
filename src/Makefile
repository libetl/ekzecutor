CC   = gcc.exe
WINDRES = windres.exe
RES  = ../res/ek_private.res
OBJ  = ../obj/affect.o ../obj/args.o ../obj/interpret.o ../obj/tads.o ../obj/ek.o ../obj/ide.o ../obj/convert.o ../obj/display.o ../obj/k.o $(RES)
LIBS =  -mwindows -lcomctl32
BIN  = ekzecuteur.exe
OPTS = -pedantic -Wall -ansi

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o "../bin/$(BIN)" $(LIBS)

../obj/ide.o: ide/ide.h ide/ide.c
	$(CC) -c ide/ide.c -o ../obj/ide.o $(OPTS)

../obj/tads.o: scm2C/tads.h scm2C/tads.c
	$(CC) -c scm2C/tads.c -o ../obj/tads.o $(OPTS)

../obj/ek.o: ek.c ek.h
	$(CC) -c ek.c -o ../obj/ek.o $(OPTS)

../obj/args.o: k/args.h k/args.c
	$(CC) -c k/args.c -o ../obj/args.o $(OPTS)

../obj/affect.o: k/affect.h k/affect.c
	$(CC) -c k/affect.c -o ../obj/affect.o $(OPTS)

../obj/convert.o: k/convert.h k/convert.c
	$(CC) -c k/convert.c -o ../obj/convert.o $(OPTS)

../obj/display.o: k/display.h k/display.c
	$(CC) -c k/display.c -o ../obj/display.o $(OPTS)

../obj/interpret.o: k/interpret.h k/interpret.c
	$(CC) -c k/interpret.c -o ../obj/interpret.o $(OPTS)

../obj/k.o: k/k.h k/k.c
	$(CC) -c k/k.c -o ../obj/k.o $(OPTS)

../res/ek_private.res: rsrc.rc 
	$(WINDRES) -i rsrc.rc --input-format=rc -o ../res/ek_private.res -O coff 

clean: 
	rm -f $(OBJ) $(RES)
