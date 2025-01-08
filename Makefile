PROG = main.exe 
SRC = main.cpp src/clinic.cpp src/clientStorage.cpp src/client.cpp src/terminalGUI.cpp
CFLAGS = -g -std=c++17 -Wall -Werror -I include
LIBS = 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean