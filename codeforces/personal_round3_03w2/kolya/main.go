package main

import "fmt"

const kMod int64 = 1000000007

func main() {
	var n int
	fmt.Scan(&n)

	var (
		total int64 = 1
		sub   int64 = 1
	)
	for i := 0; i < n; i++ {
		total *= 27
		total %= kMod
		sub *= 7
		sub %= kMod
	}

	result := (total + kMod) - sub
	result %= kMod
	fmt.Println(result)
}
