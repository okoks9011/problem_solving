package main

import "fmt"

func getFactors(x int64) map[int64]bool {
	result := make(map[int64]bool)
	for i := int64(2); i*i <= x; i++ {
		for x%i == 0 {
			x /= i
			result[i] = true
		}
	}
	if x != 1 {
		result[x] = true
	}
	return result
}

func max(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func solve() {
	var p, q int64
	fmt.Scan(&p)
	fmt.Scan(&q)

	if p%q != 0 {
		fmt.Println(p)
		return
	}

	var maxX int64 = 0
	for factor := range getFactors(q) {
		curX := p
		for curX%q == 0 {
			curX /= factor
		}
		maxX = max(maxX, curX)
	}
	fmt.Println(maxX)
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
