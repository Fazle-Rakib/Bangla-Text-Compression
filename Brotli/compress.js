const fs = require("fs");
const zlib = require("zlib");
const { performance } = require('perf_hooks');

const READ_FILE_NAME = "input.txt";
const WRITE_FILE_NAME = "compressedData.txt.br";

// Create read and write streams
const readStream = fs.createReadStream(READ_FILE_NAME);
const writeStream = fs.createWriteStream(WRITE_FILE_NAME);

// Create brotli compress object

var timer = -performance.now();
const brotli = zlib.createBrotliCompress();
// Pipe the read and write operations with brotli compression
const stream = readStream.pipe(brotli).pipe(writeStream);
stream.on("finish", () => {
  console.log("Done compressing 😎");
});

timer += performance.now();
console.log("Time: " + (timer/1000).toFixed(5) + " sec.");
console.log('Execution time: ' + timer + ' ms');






/*var hrTime = process.hrtime();
console.log((hrTime[0] * 1000000 + hrTime[1] / 1000)*0.000001);*/

/*var a = performance.now();
const brotli = zlib.createBrotliCompress();
// Pipe the read and write operations with brotli compression
const stream = readStream.pipe(brotli).pipe(writeStream);
stream.on("finish", () => {
  console.log("Done compressing 😎");
});
var b = performance.now();
console.log('It took ' + (b - a) + ' ms.');*/

