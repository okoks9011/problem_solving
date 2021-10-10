package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)

	result := 0
	aCnt, bCnt := 0, 0
	last := 0
	for _, c := range s {
		switch c {
		case 'a':
			aCnt++
		case 'b':
			bCnt++
		default:
			panic("invalid character")
		}

		for min(aCnt, bCnt) > k {
			switch s[last] {
			case 'a':
				aCnt--
			case 'b':
				bCnt--
			default:
				panic("invalid character")
			}
			last++
		}

		if aCnt+bCnt > result {
			result = aCnt + bCnt
		}
	}

	fmt.Println(result)
}
