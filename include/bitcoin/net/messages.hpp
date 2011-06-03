#ifndef LIBBITCOIN_NET_MESSAGES_H
#define LIBBITCOIN_NET_MESSAGES_H

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace libbitcoin {
namespace net {
namespace message {

typedef std::array<uint8_t, 32> hash_digest;
typedef std::array<uint8_t, 16> ip_address;

struct net_addr
{
    uint32_t timestamp;
    uint64_t services;
    ip_address ip_addr;
    uint16_t port;
};

enum class inv_type
{
    error,
    transaction,
    block,
    none
};

struct inv_vect
{
    inv_type type;
    hash_digest hash;
};

struct header
{
    uint32_t magic;
    std::string command;
    uint32_t payload_length;
    // Ignored by version and verack commands
    uint32_t checksum;
};

struct version
{
    uint32_t version;
    uint64_t services;
    uint64_t timestamp;
    net_addr addr_me;
    net_addr addr_you;
    uint64_t nonce;
    std::string sub_version_num;
    uint32_t start_height;
};

struct verack
{
};

struct getaddr
{
};

struct addr
{
    std::vector<net_addr> addr_list;
};

struct inv
{
    std::vector<inv_vect> inv_list;
};

} // message
} // net
} // libbitcoin

#endif

