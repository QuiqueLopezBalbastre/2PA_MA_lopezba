#ifndef ESAT_NETWORK_H
#define ESAT_NETWORK_H 1

#include <stdlib.h>

namespace esat {

  struct NetworkMessage {
    const void *mem;
    size_t size;
  };

  struct NetworkAddress {
    const char *address;
    unsigned int port;
  };
  
  bool NetworkStart(const NetworkAddress &n = NetworkAddress{nullptr, 1234});

  void NetworkStop();

  // sends a message through the network, returns true on success. 
  bool NetworkSendMessage(const NetworkAddress &to,const NetworkMessage &msg);

  // Message returned will be available until RecvMessage is called again.
  // Message might be null, signaling there is no message awaiting to be processed
  // RecvMessage must be called frequently in order to excute internal networking
  // process. This method will never block the calling thread.
  const NetworkMessage* NetworkRecvMessage(NetworkAddress *from_optional = nullptr);

}

#endif
