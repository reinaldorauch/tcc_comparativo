const MAX_ITEMS = 10000;

const arr = Array.from(Array(MAX_ITEMS));

for (let i = 0; i < MAX_ITEMS; i++) {
  for (let j = 0; j < MAX_ITEMS; j++) {
    arr[j] = randomString();
  }

  const index = randomInt(MAX_ITEMS);
  const key = arr[index];

  const start = process.hrtime.bigint();
  linearSearch(key, arr);
  const finish = process.hrtime.bigint();
  console.log(`${index};${finish - start}`);
}

function linearSearch(key, arr) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === key) {
      return true;
    }
  }
  return false;
}

function randomString() {
  return Array.from(Array(10))
    .map(() => String.fromCharCode(randomInt(127, 32)))
    .join("");
}

function randomInt(max, min = 0) {
  max = Math.floor(max);
  min = Math.ceil(min);
  return Math.floor(Math.random() * (max - min)) + min;
}
