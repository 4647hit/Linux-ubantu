


.PHONY:clean
clean:z
	rm -rf *.o libmymath.so mylib mylib.tgz

.PHONY:ouput
output:
	mkdir -p mylib/include
	mkdir -p mylib/lib
	cp -rf *.h mylib/include
	cp -rf *.so mylib/lib\
	tar czf mylib.tgz mylib
