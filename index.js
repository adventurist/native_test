const bindings = require("bindings");
try {
  nativeLib = bindings("native_test.node");
  console.log(nativeLib);
  if (nativeLib) {
    const thing = nativeLib.startServer();
    console.log("The thing in JS is:");
    console.log(thing);
  }
} catch (e) {
  console.log("Failed to load the native bindings. Error:", e);
}
