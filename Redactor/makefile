SOURCES=$(wildcard ./src/*.c)
LDFLAGS:=
CFLAGS:=-no-pie
TARGET:=public/redactor
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCES) $(LDFLAGS)