#define BOOST_TEST_MODULE TestSuite
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( testCase )
{
    int a = 5;
    int b = 6;
    BOOST_TEST(a != b - 1);
}
