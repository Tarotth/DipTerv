#include <QThread>
#include "BodyProcess.h"

class WorkerClass : public QThread
{
	Q_OBJECT
private:
	BodyProcess* bp;
public:
	bool rendered;

	WorkerClass();

	void run();

public slots:
	void recieveRender();
signals:
	void processReady(JointOrientation* joints, Joint* jointPos, int size);
};