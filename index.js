const bindings = require('bindings')
try {
  nativeLib = bindings('lerna_test.node')
  console.log(nativeLib)
  if (nativeLib) {
    const thing = nativeLib.doThing()
    console.log('The thing in JS is:')
    console.log(thing)
  }
} catch (e) {
  console.log('Failed to load the native native bindings. Error:', e)
}

