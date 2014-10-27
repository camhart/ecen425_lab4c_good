
typedef enum  {FISH, HAPPY}State;

typedef struct TCB {
	unsigned short int context[5];//SS, SP, IP, CS and Flags register will be saved here.
	State state;// an enumerated type. blocked, delayed, ready
	struct TCB * previous; //used when inserting and removing from queue (our queue will be a double linked list)
	struct TCB * next; // same as above
	unsigned delay; //How much time to delay
	unsigned char priority; //priority value of the current task
	void (* taskFunction)(void);
} TCB;

TCB * head;

TCB tcb[5];

int main(int argc, char ** argv) {
	void * a;
	/*head = &tcb[0];
	head->context[0] = 12;
	head->context[1] = 13;
	head->context[2] = 14;
	a = head->context[1];*/
	a = (void *)head->taskFunction;
	return 0;
}
