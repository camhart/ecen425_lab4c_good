#include "clib.h"
#include "yakk.h"

extern int KeyBuffer;

void resetHandler() {
       exit(0);
}

void keyHandler() {
    char key = (char) KeyBuffer;
    int c = 0;
    if(key == 'd') {
        printString("\nDELAY KEY PRESSED\n");
        while (c < 5000)
            c++;
        printString("\nDELAY COMPLETE\n");

    } else {
        printString("\nKEYPRESS (");
        printChar(key);
        printString(") IGNORED\n");
    }
}

void YKTickHandler() {
    TCB* cur = delayedHead;
    TCB* nextDelayed = null;

    YKEnterMutex();
    YKTickNum++;
    printString("\nTICK ");
    printInt(YKTickNum);
    printNewLine();

    while(cur != null) {
        nextDelayed = cur->next;
        cur->delay--;
        if(cur->delay <= 0) {
            cur->state = READY;
            cur->delay = 0;

	    
            delayedHead = removeFromQueue(cur, delayedHead);
            readyHead = addToQueue(cur, readyHead);
	    
        }
        cur = nextDelayed;
    }
    YKExitMutex();
}
