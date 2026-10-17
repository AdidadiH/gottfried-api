#include <crow.h>
#include <filesystem>
#include <string>

#define FILE_PREFIX "files/"

using std::string;

int main() {
  crow::SimpleApp app;

  // Health check
  CROW_ROUTE(app, "/api/health")
  ([]() { return crow::response(200, "{\"status\":\"ok\"}"); });

  CROW_ROUTE(app, "/api/view/test")
  ([]() {
    crow::response res;

    res.set_static_file_info((string)FILE_PREFIX + "test.png");

    return res;
  });

  CROW_ROUTE(app, "/api/view/<string>")
  ([](string dirString) {
    crow::response res;

    std::filesystem::path dir{FILE_PREFIX + dirString};

    if (!std::filesystem::exists(dir)) // check if directory exists
      return crow::response("Directory not found!");

    // get files in directory
    std::vector<std::filesystem::path> files;
    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
      files.push_back(entry.path());
    }

    // check if empty
    if (files.empty())
      return crow::response("Directory empty!");

    // select random file from <files>
    srand(time(0));
    string resFile = files.at(rand() % files.size());

    res.set_static_file_info(resFile);

    return res;
  });

  app.port(80).multithreaded().run();
}
