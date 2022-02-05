package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n int64
	fmt.Fscan(in, &n)

	var digits []int
	for n > 0 {
		di := int(n % 3)
		digits = append(digits, di)
		n /= 3
	}
	digits = append(digits, 0)

	for i := 0; i < len(digits)-1; i++ {
		if digits[i] == 2 {
			digits[i]++
			// We don't need lower digits
			for j := 0; j < i; j++ {
				digits[j] = 0
			}
		}
		if digits[i] == 3 {
			digits[i] = 0
			digits[i+1]++
		}
	}

	result := int64(0)
	for i := len(digits) - 1; i >= 0; i-- {
		result *= 3
		result += int64(digits[i])
	}
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		solve()
	}
}
