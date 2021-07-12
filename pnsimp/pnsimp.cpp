#include "pnsimp.h"

#include <tinsel.h>
#include <POLite.h>

typedef PThread<
		PNDevice,
		PNState,
		None,
		PNMessage
	> PNThread;

int main()
{
	PNThread* thread = (PNThread*) tinselHeapBaseSRAM();
	thread->run();
	return 0;
}
