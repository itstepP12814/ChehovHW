#include "Client.h"
Client::Client() {
    prior=0;
    pages=0;
    //ctor
}
Client::Client(int pr, int pg) {
    prior=pr;
    pages=pg;
}
Client::~Client() {
    //dtor
}
