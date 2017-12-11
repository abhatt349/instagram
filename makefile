all:
	gcc -o control ctrl.c
	gcc -o phone phone.c

clean:
	rm control
	rm phone
	rm story.txt
	rm *~
	rm *#
