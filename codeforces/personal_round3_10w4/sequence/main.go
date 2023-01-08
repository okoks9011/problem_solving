package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func findDivisors(x int) []int {
	divSet := make(map[int]struct{})
	for x > 1 {
		i := 2
		for ; i*i <= x; i++ {
			if x%i == 0 {
				break
			}
		}
		if i*i > x {
			i = x
		}
		divSet[i] = struct{}{}
		x /= i
	}

	var result []int
	for v := range divSet {
		result = append(result, v)
	}
	return result
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	d := make(map[int]int)
	for _, ai := range a {
		divisors := findDivisors(ai)
		maxLen := 0
		for _, divisor := range divisors {
			maxLen = max(maxLen, d[divisor])
		}
		maxLen++
		for _, divisor := range divisors {
			d[divisor] = maxLen
		}
	}

	result := 1
	for _, v := range d {
		result = max(result, v)
	}
	fmt.Println(result)
}
