package main

import "fmt"

func calS(x int64) int64 {
	var result int64 = 0
	for x > 0 {
		result += x % 10
		x /= 10
	}
	return result
}

func main() {
	var a int
	var b, c int64
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	var result []int64
	for sx := int64(1); sx <= 81; sx++ {
		var x int64
		x = b
		for i := 0; i < a; i++ {
			x *= sx
		}
		x += c

		if 0 < x && x < 1000000000 && sx == calS(x) {
			result = append(result, x)
		}
	}
	fmt.Println(len(result))
	for _, ri := range result {
		fmt.Printf("%d ", ri)
	}
	fmt.Println()
}
