const fs = require("fs");
const zlib = require("zlib");
const { performance } = require('perf_hooks');

const READ_FILE_NAME = "compressedData.txt.br";
const WRITE_FILE_NAME = "data.txt";

// Create read and write streams
const readStream = fs.createReadStream(READ_FILE_NAME);
const writeStream = fs.createWriteStream(WRITE_FILE_NAME);

var timer = -performance.now();
// Create brotli decompress object
const brotli = zlib.createBrotliDecompress();

const stream = readStream.pipe(brotli).pipe(writeStream); 
stream.on("finish", () => {
  console.log("Done decompressing 😎");
});

timer += performance.now();
console.log("Time: " + (timer/1000).toFixed(5) + " sec.");
console.log('Execution time: ' + timer + ' ms');