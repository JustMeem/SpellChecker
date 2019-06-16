all: bin/SpellCh  bin/SpellCh-test


bin/SpellCh: build/src/main.o  build/src/SpellCh.o  build/src/dict.o
	gcc -Wall -Werror build/src/main.o build/src/SpellCh.o build/src/dict.o -o bin/SpellCh

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/dict.o: src/dict.c
	gcc -Wall -Werror -c src/dict.c -o build/src/dict.o

build/src/SpellCh.o: src/SpellCh.c
	gcc -Wall -Werror -c src/SpellCh.c -o build/src/SpellCh.o

bin/SpellCh-test: build/test/main.o build/test/testSC.o build/src/SpellCh.o
	gcc -Wall -Werror build/test/main.o build/test/testSC.o build/src/SpellCh.o -o bin/SpellCh-test

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/testSC.o: test/testSC.c
	gcc -I thirdparty -Wall -Werror -c test/testSC.c -o build/test/testSC.o


.PHONY: clean

clean:
	rm -rf build/*/*.o