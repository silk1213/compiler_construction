CC = g++
CCFLAGS = -g
FLEX = flex
BISON = bison
all: lab3

clean:
	rm -f *.o CPP.dvi CPP.aux CPP.log 
	rm -f CPP.pdf lab2

distclean:
	 rm -f *.o Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H CPP.l CPP.y CPP.tex CPP.dvi CPP.aux CPP.log CPP.ps lab2 Makefile

lab3: Absyn.o Lexer.o Parser.o Printer.o Test.o TypeChecker.o Env.o Interpreter.o
	@echo "Linking lab3..."
	${CC} ${CCFLAGS} *.o -o lab3

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: CPP.l
	${FLEX} -oLexer.C CPP.l

Parser.C: CPP.y
	${BISON} CPP.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

Env.o: Env.C Env.H
	${CC} ${CCFLAGS} -c Env.C

TypeChecker.o: TypeChecker.H TypeChecker.C Env.H
	${CC} ${CCFLAGS} -c TypeChecker.C

Interpreter.o: Interpreter.H Interpreter.C Env.H
	${CC} ${CCFLAGS} -c Interpreter.C

Test.o: Test.C Parser.H Printer.H Absyn.H 
	${CC} ${CCFLAGS} -c Test.C

