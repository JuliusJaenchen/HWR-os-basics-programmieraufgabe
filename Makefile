BINARY = main.exe

run:
	gcc -o $(BINARY) main.c threadfunc.c -I. && ./$(BINARY)

clean:
	rm $(BINARY)
