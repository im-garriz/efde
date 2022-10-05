#include "functional_test_2.hpp"

int _functional_test_2_1(void) {
    return 5;
}

int _functional_test_2_2(void) {
    return 5;
}

int _functional_test_2_3(void) {
    return 8;
}

BOOST_AUTO_TEST_SUITE(functional_test_2_name)

BOOST_AUTO_TEST_CASE(functional_test_2_name_1) {
    BOOST_CHECK_EQUAL(_functional_test_2_1(), 8);
}

BOOST_AUTO_TEST_CASE(functional_test_2_name_2) {
    BOOST_CHECK_EQUAL(_functional_test_2_2(), 8);
}

BOOST_AUTO_TEST_CASE(functional_test_2_name_3) {
    BOOST_CHECK_EQUAL(_functional_test_2_3(), 8);
}

BOOST_AUTO_TEST_SUITE_END()
