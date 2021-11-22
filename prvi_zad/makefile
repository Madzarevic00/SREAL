all: parsiranje
parsiranje: app.o opc1.o opc2.o opc3.o opc4.o
	gcc -o parsiranje app.o opc1.o opc2.o opc3.o opc4.o
app.o: app.c functions.h
	gcc -c app.c
opc1.o: opc1.c functions.h
	gcc -c opc1.c
opc2.o: opc2.c functions.h
	gcc -c opc2.c
opc3.o: opc3.c functions.h
	gcc -c opc3.c
opc4.o: opc4.c functions.h
	gcc -c opc4.c
.PHONY: clean
clean:
	rm -f parsiranje *.0
