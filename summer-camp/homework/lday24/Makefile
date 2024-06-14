Srcs := $(wildcard *.c)
Outs := $(patsubst %.c, %, $(Srcs))

CC := gcc
CFLAGS = -Wall -g
MYSQL_LIB = /usr/lib64/mysql/libmysqlclient.so

ALL: $(Outs)

%: %.c
	$(CC) $< -o $@ $(CFLAGS) $(MYSQL_LIB)

.PHONY: clean rebuild ALL

clean:
	-$(RM) $(Outs)

rebuild: clean ALL
