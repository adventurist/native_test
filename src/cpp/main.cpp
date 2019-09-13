#include <node_api.h>
#include <unistd.h>
#include <iostream>
#include <vector>

napi_value start_server(napi_env env, napi_callback_info cb) {
  std::cout << "Starting socket server" << std::endl;

  pid_t ws_pid = fork();

  if (ws_pid >= 0) {
    // char* argvx[3];
    // argvx[0] = "-";
    // argvx[1] = "-";
    // argvx[2] = "h";
    std::vector<char*> argvx{};
    argvx.push_back(const_cast<char*>("--help"));
    auto returned = execv("./bin/ws_server", &argvx[0]);
    std::cout << "Returned from exec: " << returned << std::endl;
    std::cout << "executed WebSocket server";
  }

  napi_value result = nullptr;

  napi_create_string_utf8(env, "This is the thing", NAPI_AUTO_LENGTH, &result);

  return result;
}

napi_value Init(napi_env env, napi_value value) {
  napi_value exports = nullptr;
  napi_status status = napi_create_object(env, &exports);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to initialize object");
  }

  napi_value func = nullptr;
  status = napi_create_function(env, "startServer", NAPI_AUTO_LENGTH, start_server,
                                nullptr, &func);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to initialize function.");
  }

  status = napi_set_named_property(env, exports, "startServer", func);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to set function on exports object.");
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
