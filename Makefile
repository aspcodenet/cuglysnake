PROG=main.exe
# CC=gcc
DEPS=test.h
SOURCES=main.c test.c
CFLAGS=-Wall -Werror -g
OUTPUTDIR=obj
OBJS = $(addprefix $(OUTPUTDIR)/, $(SOURCES:.c=.o))

all: $(OUTPUTDIR) $(PROG)

$(PROG): $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)


.PHONY: prep clean
