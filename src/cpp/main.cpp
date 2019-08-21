#include <node_api.h>
#include <iostream>

napi_value do_thing(napi_env env, napi_callback_info cb) {
  std::cout << "This is the stream" << std::endl;

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
  status = napi_create_function(env, "doThing", NAPI_AUTO_LENGTH, do_thing,
                                nullptr, &func);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to initialize function.");
  }

  status = napi_set_named_property(env, exports, "doThing", func);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to set function on exports object.");
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
