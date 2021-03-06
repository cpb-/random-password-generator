
EXE = random-pwd

OBJ = random-pwd.o

CROSS_COMPILE ?=
CC             = gcc
CFLAGS         = -Wall -W
LDFLAGS        = 

.PHONY: all

all: $(EXE)

$(EXE): $(OBJ)
	$(CROSS_COMPILE)$(CC) -o $(EXE) $(OBJ) $(LDFLAGS)

%.o:%.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c  $<

.PHONY: clean

clean:
	rm -f $(EXE) $(OBJ) *~

