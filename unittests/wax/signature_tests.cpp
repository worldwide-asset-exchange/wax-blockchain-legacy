#include <boost/test/unit_test.hpp>

#include <eosio/chain/types.hpp>
#include <eosio/testing/tester.hpp>

#include <boost/multiprecision/cpp_int.hpp>

#include <cstdint>
#include <iterator>
#include <string>
#include <vector>

#include <contracts.hpp>
#include "rsa_signer.hpp"

using namespace eosio;
using namespace eosio::chain;
using namespace fc;

using mvo = fc::mutable_variant_object;

#ifdef NON_VALIDATING_TEST  // see tester.hpp
#  define EOSIO_FIXTURE eosio::testing::tester
#else
#  define EOSIO_FIXTURE eosio::testing::validating_tester
#endif

const name account_n = N(wax.test);

const std::string public_exponent_1024 = "3";

const std::string private_exponent_1024 = 
    "00954e45c37dca926fcbde438a9f8df39643133e4877151a2d423da2a87c54a681cc3c27b6970e7289c67191f596ea5caed709d762b4c937d95da9279bb32292a344c57631a3adfa8d1a837699908861dfe108d9bd37184b3f8b3810e13f183382c497b424b4530b56bdfb6c97e0c74b9dec7558425221e2e4ba3a2737aa3e2f53";

const std::string modulus_1024 =           
    "dff568a53cafdba7b1cd654fef54ed61649cdd6cb29fa743e35c73fcba7ef9c2b25a3b91e295abcea9aa5af0625f8b06428ec3140f2dd3c60c7dbb698cb3dbf6c64b1160daec4eb7d6deca1dfc45b83d5f30e5398f6f737ee394d57c8d2bf412f056c2e8a54d9bf554149c0da31346e31f23ffb516b1f9797d650169199b7add";

struct __attribute((packed)) results_entry {
    std::uint64_t id;
    bool          value;
};
FC_REFLECT(results_entry, (id)(value));


BOOST_AUTO_TEST_SUITE(wax_tests)
BOOST_AUTO_TEST_SUITE(signature_tests)

// Custom fixture
struct wax_fixture: public EOSIO_FIXTURE {
    wax::rsa_signer signer;

    wax_fixture(): signer(private_exponent_1024, modulus_1024) {
        try {
            create_accounts({ account_n });

            set_code(account_n, eosio::testing::contracts::wax_rsa_wasm());
            set_abi(account_n, eosio::testing::contracts::wax_rsa_abi().data());

            produce_block();
        }
        FC_LOG_AND_RETHROW();
    }

    bool get_last_result() {
        results_entry entry;
        get_table_entry(entry, account_n, account_n, N(results), 0, false);
        return entry.value;
    }

    void action_verrsasig(const std::string& message,
                          const std::string& signature,
                          const std::string& exponent,
                          const std::string& modulus) {
        push_action(
            account_n,
            N(verrsasig),
            account_n,
            mvo() ("message", message)("signature", signature)
                  ("exponent", exponent)("modulus", modulus));
    }

}; // struct wax_fixture


BOOST_FIXTURE_TEST_CASE(check_invalid_lengths, wax_fixture) {
    try {
        action_verrsasig("", "abcd", "abcd", "abcd");
        BOOST_REQUIRE(!get_last_result());

        action_verrsasig("abcd", "", "abcd", "abcd");
        BOOST_REQUIRE(!get_last_result());

        action_verrsasig("abcd", "abcd", "", "abcd");
        BOOST_REQUIRE(!get_last_result());

        action_verrsasig("abcd", "abcd", "abcd", "");
        BOOST_REQUIRE(!get_last_result());
    }
    FC_LOG_AND_RETHROW();
}

BOOST_FIXTURE_TEST_CASE(check_invalid_hex_strings, wax_fixture) {
    try {
        action_verrsasig("foo", "XXXX", "abcd", "abcd");
        BOOST_REQUIRE(!get_last_result());

        action_verrsasig("foo", "abcd", "XXXX", "abcd");
        BOOST_REQUIRE(!get_last_result());

        action_verrsasig("foo", "abcd", "abcd", "XXXX");
        BOOST_REQUIRE(!get_last_result());
    }
    FC_LOG_AND_RETHROW();
}

BOOST_FIXTURE_TEST_CASE(signing_happy_path, wax_fixture) {
    try {
        const std::string msg = "message to sign";

        std::string signature = signer.sign(msg);

        BOOST_REQUIRE_EQUAL(signature.size(), modulus_1024.size());

        action_verrsasig(msg, signature, public_exponent_1024, modulus_1024);
        BOOST_REQUIRE(get_last_result());
    }
    FC_LOG_AND_RETHROW();
}

BOOST_FIXTURE_TEST_CASE(minimal_message_len, wax_fixture) {
    try {
        const std::string msg = "1";

        std::string signature = signer.sign(msg);

        action_verrsasig(msg, signature, public_exponent_1024, modulus_1024);
        BOOST_REQUIRE(get_last_result());
    }
    FC_LOG_AND_RETHROW();
}

BOOST_FIXTURE_TEST_CASE(malformed_parameter_len, wax_fixture) {
    try {
        const std::string msg = "message to sign";

        std::string signature = signer.sign(msg);

        action_verrsasig(msg, signature, "A", "B");
        BOOST_REQUIRE(!get_last_result());
    }
    FC_LOG_AND_RETHROW();
}

BOOST_FIXTURE_TEST_CASE(corrupted_sginature, wax_fixture) {
    try {
        const std::string msg = "message to sign";

        std::string signature = signer.sign(msg);
        BOOST_REQUIRE(!signature.empty());

        // Corrupt the signature
        auto last = signature.end() - 1;
        (*last)++;
        if (*last > '9') *last = '0';

        action_verrsasig(msg, signature, public_exponent_1024, modulus_1024);
        BOOST_REQUIRE(!get_last_result());
    }
    FC_LOG_AND_RETHROW();
}


BOOST_AUTO_TEST_SUITE_END() // signature_tests
BOOST_AUTO_TEST_SUITE_END() // wax_tests
