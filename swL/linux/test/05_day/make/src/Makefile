TARGET = bbb
OBJS = main.o add.o
CC = gcc
CFLAGS = -g -c -I../include

$(TARGET) : $(OBJS) 
	$(CC) $(OBJS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< 

clean :
	rm -f $(OBJS) $(TARGET)
