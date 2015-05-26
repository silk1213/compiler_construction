CC = g++
CCFLAGS = -g
FLEX = flex
BISON = bison
all: TestCPP

clean:
	rm -f *.o CPP.dvi CPP.aux CPP.log 
	rm -f CPP.pdf TestCPP

distclean:
	 rm -f *.o Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H CPP.l CPP.y CPP.tex CPP.dvi CPP.aux CPP.log CPP.ps TestCPP Makefile

TestCPP: Absyn.o Lexer.o Parser.o Printer.o Skeleton.o Test.o TypeChecker.o
	@echo "Linking TestCPP..."
	${CC} ${CCFLAGS} *.o -o TestCPP

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

Skeleton.o: Skeleton.C Skeleton.H Absyn.H TypeChecker.H
	${CC} ${CCFLAGS} -c Skeleton.C

TypeChecker.o: TypeChecker.H TypeChecker.C Env.C
	${CC} ${CCFLAGS} -c TypeChecker.C

Test.o: Test.C Parser.H Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Test.C

