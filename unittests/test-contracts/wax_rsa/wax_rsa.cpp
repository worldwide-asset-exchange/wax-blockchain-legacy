#include <eosio/eosio.hpp>

#include <string>
#include <string_view>

// WAX specific APIs
extern "C" {
    __attribute__((eosio_wasm_import))
    int verify_rsa_sha256_sig(const char* message, uint32_t message_len,
                              const char* signature, uint32_t signature_len,
                              const char* exponent, uint32_t exponent_len,
                              const char* modulus, uint32_t modulus_len);
}

// C++ helper wrappers
inline bool verify_rsa_sha256_sig(std::string_view message,
                                  std::string_view signature,
                                  std::string_view exponent,
                                  std::string_view modulus) {
    return verify_rsa_sha256_sig(
        message.data(), message.size(),
        signature.data(), signature.size(),
        exponent.data(), exponent.size(),
        modulus.data(), modulus.size());
}

using namespace eosio;

CONTRACT wax_rsa: public contract {
public:
    wax_rsa(name receiver, name code, datastream<const char*> ds)
        : contract(receiver, code, ds)
        , results_table(receiver, receiver.value) {
    }

    ACTION verrsasig(const std::string& message,
                     const std::string& signature,
                     const std::string& exponent,
                     const std::string& modulus)
    {
        print("verrsasig called!\n");
        
        set_last_result(
            verify_rsa_sha256_sig(message, signature, exponent, modulus));
    }

private:
    TABLE results {
        uint64_t id;
        bool     value;

        auto primary_key() const { return id; }
    };

    eosio::multi_index<"results"_n, results> results_table;

    void set_last_result(bool value) {
        auto it = results_table.find(0);

        if (it == results_table.end()) {
            results_table.emplace(get_self(), [&](auto& rec) {
                rec.id = 0;
                rec.value = value;
            });
        } else {
            results_table.modify(it, get_self(), [&](auto& rec) {
                rec.value = value;
            });
        }
    }
   
};

EOSIO_DISPATCH(wax_rsa, (verrsasig))
