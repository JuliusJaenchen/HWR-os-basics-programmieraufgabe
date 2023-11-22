#TODO test on windows


#
BINARY = main.exe
#


run: 
	gcc *.c -o $(BINARY) && ./$(BINARY)

clean:
	rm $(BINARY)
