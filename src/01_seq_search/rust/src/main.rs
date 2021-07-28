use std::char;
use rand;
use std::time::Instant;

fn main() {
    const MAX_ITEMS: usize = 10000;

    let mut arr: Vec<String> = vec!["".to_string(); MAX_ITEMS];

    for _ in 0..MAX_ITEMS {
        for i in 0..MAX_ITEMS {
            // Initializing
            arr[i] = random_string();
        }

        let index: usize = random_int(MAX_ITEMS);
        let key = arr[index].clone();

        let start = Instant::now();
        linear_search(&key, &arr);
        println!("{};{}", index, start.elapsed().as_nanos());
    }
}

fn linear_search(key: &String, arr: &Vec<String>) -> bool {
    for val in arr.iter() {
        if val == key {
            return true;
        }
    }

    false
}

fn random_string() -> String {
    let mut buf = String::new();

    for _ in 0..10 {
        buf.push(char::from_u32(random_u32(127-32)+32).unwrap());
    }

    buf
}

fn random_int(max: usize) -> usize {
    rand::random::<usize>() % max
}

fn random_u32(max: u32) -> u32 {
    rand::random::<u32>() % max
}
