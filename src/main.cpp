#include <crow.h>
#include <string>

using std::string;

int main() {
  crow::SimpleApp app;

  // Health check
  CROW_ROUTE(app, "/health")
  ([]() { return crow::response(200, "{\"status\":\"ok\"}"); });

  app.port(8080).multithreaded().run();
}
