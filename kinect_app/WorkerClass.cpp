#include "WorkerClass.h"

WorkerClass::WorkerClass()
{
	bp = new BodyProcess();
	rendered = 1;
}

void WorkerClass::run()
{
	while (true)
	{
		if (rendered) {
			rendered = 0;
			bp->Update();
			emit processReady(bp->processedBodyOrient, bp->processedBody, bp->size);
		}
		QThread::msleep(30);
	}
}

void WorkerClass::recieveRender()
{
	rendered = 1;
}