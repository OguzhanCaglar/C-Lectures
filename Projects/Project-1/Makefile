# Derleyici ve ayarlar?
CC = gcc
CFLAGS = -Wall -std=c99

#Hedef Program Adı
TARGET = notepad

#Kaynak Dosyalar
SRCS = main.c notepad.c password.c

# Header dosyaları otomatik bulduralım
OBJS = $(SRCS:.c=.o)

#Varsayılan hedef
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#Temizlik
clean:
	rm -f *.o $(TARGET)