#cmake_minimum_required(VERSION 3.10)

if( EOSIO_COMPILE_TEST_CONTRACTS )
    #find_package(eosio.cdt REQUIRED)
    add_contract( wax_rsa wax_rsa wax_rsa.cpp )
else()
    configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/wax_rsa.wasm ${CMAKE_CURRENT_BINARY_DIR}/wax_rsa.wasm COPYONLY )
    configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/wax_rsa.abi ${CMAKE_CURRENT_BINARY_DIR}/wax_rsa.abi COPYONLY )
endif()
