var brotli = require('brotli');
var decompress = require('brotli/decompress');
const fs = require('fs');


// encode some data with options (default options shown)
var data = brotli.compress(fs.readFileSync("input.txt"), {
  mode: 0, // 0 = generic, 1 = text, 2 = font (WOFF2)
  quality: 11, // 0 - 11
  lgwin: 22 // window size
});
console.log(data);