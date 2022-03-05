package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

const kMod int64 = 1000000007

func calGCD(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return calGCD(b, a%b)
	}
}

func calLCM(a, b int64) int64 {
	gcd := calGCD(a, b)
	return (a / gcd) * b
}

func solve() {
	var n int64
	fmt.Fscan(in, &n)

	var result int64 = 0
	var lcm int64 = 1
	remain := n
	for i := int64(2); remain > 0; i++ {
		lcm = calLCM(lcm, i)
		next := n / lcm
		result += (((remain - next) % kMod) * i) % kMod
		result %= kMod
		remain = next
	}
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
