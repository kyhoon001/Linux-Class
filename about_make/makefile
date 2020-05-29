CC = gcc
CFLAGS = -W -Wall
OBJS = chicken.c bbq.c bhc.c kfc.c
TARGET = chicken_exe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o chicken_exe
