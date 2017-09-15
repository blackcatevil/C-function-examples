PROGRAM = popen_v1 pthread_v1
CC = $(CROSS_COMPILE)gcc
SRCS = popen_v1.c pthread_v1.c
OBJS = $(SRCS:.c=.o)

all: $(PROGRAM)
	@echo "make done!"

popen_v1: popen_v1.o
	$(CC) $< -o $@

pthread_v1: pthread_v1.o
	$(CC) $< -pthread -o $@

clean:
	@rm -rf *.o $(PROGRAM)
	@echo "clean done!"

.PHONY:all clean
