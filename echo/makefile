SOURCES=$(wildcard ./src/*.c)
LDFLAGS:=
CFLAGS:=
TARGET:=public/echo
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCES) $(LDFLAGS)