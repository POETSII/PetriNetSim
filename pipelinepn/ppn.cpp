#include "ppn.h"

#include <tinsel.h>
#include <POLite.h>

typedef PThread<
		PPNDevice,
		PPNState,
		None,
		PPNMessage
	> PPNThread;

int main()
{
	PPNThread* thread = (PPNThread*) tinselHeapBaseSRAM();
	thread->run();
	return 0;
}
