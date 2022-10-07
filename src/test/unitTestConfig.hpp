#ifndef UNIT_TEST_CONFIG_HPP
#define UNIT_TEST_CONFIG_HPP

#define USE_BOOST_PRECOMPILED_LIBRARY

#ifndef USE_BOOST_PRECOMPILED_LIBRARY
    #include<boost/test/included/unit_test.hpp>
#else
    #include<boost/test/unit_test.hpp>
#endif

#endif /* UNIT_TEST_CONFIG_HPP */