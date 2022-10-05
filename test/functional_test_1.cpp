#include "functional_test_1.hpp"

int _functional_test_1_1(void) {
    return 5;
}

int _functional_test_1_2(void) {
    return 5;
}

int _functional_test_1_3(void) {
    return 8;
}

BOOST_AUTO_TEST_SUITE(functional_test_1_name)

BOOST_AUTO_TEST_CASE(functional_test_1_name_1) {
    BOOST_CHECK_EQUAL(_functional_test_1_1(), 5);
}

BOOST_AUTO_TEST_CASE(functional_test_1_name_2) {
    BOOST_CHECK_EQUAL(_functional_test_1_2(), 5);
}

BOOST_AUTO_TEST_CASE(functional_test_1_name_3) {
    BOOST_CHECK_EQUAL(_functional_test_1_3(), 5);
}

BOOST_AUTO_TEST_SUITE_END()
