package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in = bufio.NewReader(os.Stdin)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func calDivisors(x int) map[int]struct{} {
	result := make(map[int]struct{})
	for i := 2; i*i <= x; i++ {
		if x%i != 0 {
			continue
		}

		subResult := calDivisors(x / i)
		for k := range subResult {
			result[k] = struct{}{}
			result[k*i] = struct{}{}
		}
		return result
	}
	result[1] = struct{}{}
	result[x] = struct{}{}
	return result
}

func main() {
	var a, b, n int
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)
	fmt.Fscan(in, &n)

	common := gcd(a, b)
	var divisors []int
	for k := range calDivisors(common) {
		divisors = append(divisors, k)
	}
	sort.Ints(divisors)

	for i := 0; i < n; i++ {
		var lo, hi int
		fmt.Fscan(in, &lo)
		fmt.Fscan(in, &hi)

		if lo > divisors[len(divisors)-1] {
			fmt.Println(-1)
			continue
		}

		upperIdx := sort.Search(len(divisors), func(x int) bool {
			return divisors[x] > hi
		})
		upperIdx--
		lowerIdx := sort.Search(len(divisors), func(x int) bool {
			return divisors[x] >= lo
		})
		if lowerIdx > upperIdx {
			fmt.Println(-1)
		} else {
			fmt.Println(divisors[upperIdx])
		}
	}
}
