#define BOOST_TEST_MODULE Simple testcases

//#define HEADER_ONLY_MODE

#ifdef HEADER_ONLY_MODE
    #include<boost/test/included/unit_test.hpp>
#else
    #include<boost/test/unit_test.hpp>
#endif


BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(suite1_1) {
    BOOST_CHECK_EQUAL(2+2, 4);
}

BOOST_AUTO_TEST_CASE(suite1_2) {
    BOOST_CHECK_EQUAL(2+2, 4);
}

BOOST_AUTO_TEST_CASE(suite1_3) {
    BOOST_CHECK_EQUAL(2+2, 5);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(suite2)

BOOST_AUTO_TEST_CASE(suite2_1) {
    BOOST_CHECK_EQUAL(2+2, 4);
}

BOOST_AUTO_TEST_CASE(suite2_3) {
    BOOST_CHECK_EQUAL(2+2, 5);
}

BOOST_AUTO_TEST_SUITE_END()