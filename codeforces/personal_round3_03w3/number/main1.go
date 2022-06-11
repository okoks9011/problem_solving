package main

import (
	"bufio"
	"fmt"
	"os"
)

func getPrimes() ([]int, []bool) {
	isPrime := make([]bool, kMax+1)
	for i := 2; i < len(isPrime); i++ {
		isPrime[i] = true
	}
	for i := 2; i*i <= len(isPrime); i++ {
		if !isPrime[i] {
			continue
		}
		for j := i * i; j < len(isPrime); j += i {
			isPrime[j] = false
		}
	}

	var result []int
	for i, p := range isPrime {
		if p {
			result = append(result, i)
		}
	}
	return result, isPrime
}

func getFactorAccs() []int64 {
	primes, isPrime := getPrimes()
	factors := make([]int64, kMax+1)
	for i := 2; i < len(factors); i++ {
		if isPrime[i] {
			factors[i] = 1
			continue
		}
		for j := 0; j < len(primes) && primes[j] <= i; j++ {
			if i%primes[j] == 0 {
				pre := i / primes[j]
				factors[i] = factors[pre] + 1
				break
			}
		}
	}

	factorAccs := make([]int64, len(factors))
	for i := 2; i < len(factorAccs); i++ {
		factorAccs[i] = factorAccs[i-1] + factors[i]
	}
	return factorAccs
}

var factors []int64

func solve1() {
	var a, b int
	fmt.Fscan(in, &a)
	fmt.Fscan(in, &b)

	fmt.Fprintln(out, factors[a]-factors[b])
}

func main1() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	factors = getFactorAccs()

	var t int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		solve1()
	}
}
