CC= g++
CFLAGS = -o
LEX= flex
YACC = bison
YFLAGS = -d -v -t
BIN = parcer
YFILE= grammar.y
LFILE = sintax.l
YOUT = grammar.tab.c grammar.tab.h
LOUT = lex.yy.c

.PHONY : all

all : $(BIN)
	./$(BIN)
$(BIN) : $(LOUT) $(YOUT)
	$(CC) $^ $(CFLAGS) $@
$(LOUT) : $(LFILE)
	$(LEX) $^
$(YOUT) : $(YFILE)
	$(YACC) $(YFLAGS) $^
