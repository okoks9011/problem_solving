package main

import "fmt"

const kMod int64 = 1_000_000_007

// return a^b
func pow(a, b int64) int64 {
	if b == 0 {
		return 1
	}
	if b == 1 {
		return a
	}

	half := pow(a, b/2)
	result := (half * half) % kMod
	if b%2 == 1 {
		result *= a
		result %= kMod
	}
	return result
}

func main() {
	var n, m int64
	fmt.Scan(&n)
	fmt.Scan(&m)

	t := pow(2, m)
	if t == 0 {
		t += kMod
	}
	t--

	fmt.Println(pow(t, n))
}
