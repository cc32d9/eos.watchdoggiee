#include <eosiolib/eosio.hpp>
#include <string>

using namespace eosio;
using std::string;

class watchdoggiee : public eosio::contract {
public:
  watchdoggiee(account_name self):
    contract(self), _counters(self, self)
  {}

  /// @abi table counters
  struct counter {
    account_name   sender;
    uint64_t       remaining;
    auto primary_key()const { return sender; }
  };

  typedef eosio::multi_index<N(counters), counter> counters;  
  
  /// @abi action 
  void ping( account_name from,
             account_name to,
             string memo )
  {
    eosio_assert( from != to, "cannot ping self" );
    require_auth( from );
    eosio_assert( is_account( to ), "to account does not exist");

    // sender is paying for RAM in counters table
    
    auto cntr = _counters.find(from);
    
    if( cntr == _counters.end() ) {
      // New sender: let them send 1000 messages
      _counters.emplace(from, [&]( auto& ce ) {
          ce.sender = from;
          ce.remaining = 999;
        });
    }
    else {
      // Please stop you dirty spammer!
      eosio_assert(cntr->remaining > 0,
                   "Your sending limit is run out. Contact Telegram: @cc32d9 for extension");
      _counters.modify( *cntr, from, [&]( auto& ce ) {
          ce.remaining--;
        });
    }

    // This is what they all want
    require_recipient( to );
  }


  /// @abi action 
  void setlimit( account_name sender, uint64_t limit )
  {
    require_auth( _self );
    eosio_assert(is_account( sender ), "sender does not exist");

    auto cntr = _counters.find( sender );
    eosio_assert( cntr != _counters.end(), "No such counter");
    // cannot charge the sender for RAM this time
    _counters.modify( *cntr, _self, [&]( auto& ce ) {
        ce.remaining = limit;
      });
  }
  
private:
  counters _counters;
  
};

EOSIO_ABI( watchdoggiee, (ping)(setlimit) )
