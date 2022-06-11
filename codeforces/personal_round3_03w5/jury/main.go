package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

const kMod int64 = 998_244_353

func factorialWithSkip(rawX, rawSkip int) int64 {
	x, skip := int64(rawX), int64(rawSkip)
	result := int64(1)
	for i := int64(1); i <= x; i++ {
		if i == skip {
			result *= i - 1
		} else {
			result *= i
		}
		result %= kMod
	}
	return result
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	aCnt := make(map[int]int)
	maxV := 0
	for i := 0; i < n; i++ {
		var ai int
		fmt.Fscan(in, &ai)

		aCnt[ai]++
		if ai > maxV {
			maxV = ai
		}
	}

	if aCnt[maxV] > 1 {
		fmt.Println(factorialWithSkip(n, 0))
		return
	}
	if aCnt[maxV] == 1 {
		secondFreq, ok := aCnt[maxV-1]
		if !ok {
			fmt.Println(0)
			return
		}
		fmt.Println(factorialWithSkip(n, secondFreq+1))
	} else {
		panic("impossible")
	}
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
