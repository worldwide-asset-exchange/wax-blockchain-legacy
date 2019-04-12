# use eosiocpp -g  wax_test.abi wax_test.cpp to generate the ABI file
file(GLOB ABI_FILES "*.abi")
configure_file("${ABI_FILES}" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)

add_wast_executable(TARGET wax_test
  INCLUDE_FOLDERS "${STANDARD_INCLUDE_FOLDERS}" ${Boost_INCLUDE_DIR}
  LIBRARIES libc++ libc eosiolib
  DESTINATION_FOLDER ${CMAKE_CURRENT_BINARY_DIR}
)
