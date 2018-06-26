# watchdoggie EOS contract

This is a simple contract that helps verifying that the watch script is
monitoring the network and sending notifications.

So, if you need to create a dummy transaction without sending any
tokens, just do:

```
cleos -u https://eu1.eosdac.io push action watchdoggiee ping '["FROMACCOUNT", "TOACCOUNT", "hello world"]' -p FROMACCOUNT
```

As a result, both accounts will have this "ping" transaction in their
history of actions.



## Copyright and License

Copyright 2018 cc32d9@gmail.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
