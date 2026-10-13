// #define CROW_STATIC_DIRECTORY "./files/"

#include <crow.h>
#include <string>

using std::string;

int main() {
  crow::SimpleApp app;

  // Health check
  CROW_ROUTE(app, "/health")
  ([]() { return crow::response(200, "{\"status\":\"ok\"}"); });

  CROW_ROUTE(app, "/api/view/test")
  ([]() {
    crow::response res;

    res.set_static_file_info("build/files/test.png");

    return res;
  });

  app.port(80).multithreaded().run();
}
