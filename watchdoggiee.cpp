#include <eosiolib/eosio.hpp>
#include <string>

using namespace eosio;
using std::string;

class watchdoggiee : public eosio::contract {
public:
  using contract::contract;
  
  /// @abi action 
  void ping( account_name from,
             account_name to,
             string memo ) {
    
    eosio_assert( from != to, "cannot transfer to self" );
    require_auth( from );
    eosio_assert( is_account( to ), "to account does not exist");
    require_recipient( from );
    require_recipient( to );
  }
};

EOSIO_ABI( watchdoggiee, (ping) )
