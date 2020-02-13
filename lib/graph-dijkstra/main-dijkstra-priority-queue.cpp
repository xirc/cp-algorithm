#include <map>
#include <string>
#include "./template-main-dijkstra-interp.hpp"
#include "./dijkstra-priority-queue.hpp"

Interp<Dijkstra>* interp = new Interp<Dijkstra>();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}