ALL:Mystdio.c Test.c

Mystdio.c:mystdio.c
	gcc -o $@ $^ -std=c99
Test.c:test.c
	gcc -o $@ $^ -std=c99
.PHONY:clean
clean:
	rm -rf Test.c Mystdio.c