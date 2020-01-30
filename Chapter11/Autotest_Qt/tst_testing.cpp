#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();

	QSignalSpy* spy;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
	void test_signalslot();
};

Testing::Testing()
{
	QObject* object = new QObject(this);
	connect(object, &QObject::objectNameChanged, this, &Testing::test_signalslot);
	spy = new QSignalSpy(object, &QObject::objectNameChanged);
	object->setObjectName("New Name");
}

Testing::~Testing()
{

}

void Testing::initTestCase()
{

}

void Testing::cleanupTestCase()
{

}

void Testing::test_case1()
{
    QString str = "Testing";
    QVERIFY(str.toUpper() == "TESTING");
}

void Testing::test_case2()
{
    int a = 10;
    QCOMPARE(a, 10);
}

void Testing::test_signalslot()
{
	QCOMPARE(spy->count(), 1);
	QList<QVariant> arguments = spy->takeFirst();
	QVERIFY(arguments.at(0).toString() == "New Name");
}

QTEST_MAIN(Testing)

#include "tst_testing.moc"
