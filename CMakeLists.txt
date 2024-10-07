cmake_minimum_required(VERSION 3.10)
project(cpp_pow_blockchain)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add source files
add_executable(cpp_pow_blockchain main.cpp src/Block.cpp src/Blockchain.cpp)

# Link OpenSSL libraries (for SHA-256)
find_package(OpenSSL REQUIRED)
target_link_libraries(cpp_pow_blockchain OpenSSL::SSL OpenSSL::Crypto)
