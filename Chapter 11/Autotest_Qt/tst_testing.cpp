#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
};

Testing::Testing()
{

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

QTEST_MAIN(Testing)

#include "tst_testing.moc"
