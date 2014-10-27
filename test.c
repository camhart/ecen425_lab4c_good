#include <stdio.h>

typedef struct {
	int a;
} stuff;


void somefunc(stuff* thing) {
	stuff* anotherThing = thing;
	anotherThing->a = 9;
}


int main(void) {
	stuff* stuffHead;
	stuff asdf = { .a = -1 };
	stuffHead = &asdf;
	printf("%d\n", stuffHead->a);
	somefunc(stuffHead);
	printf("%d\n", stuffHead->a);
}