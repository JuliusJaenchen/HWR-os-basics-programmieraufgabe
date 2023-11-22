BINARY = main.exe

run: 
	gcc *.c -o $(BINARY) && ./$(BINARY)

clean:
	rm $(BINARY)
