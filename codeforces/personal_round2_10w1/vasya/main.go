package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	in = bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)

	result := 0
	aCnt, bCnt := 0, 0
	aLast, bLast := 0, 0
	for i, c := range s {
		switch c {
		case 'a':
			aCnt++
		case 'b':
			bCnt++
		default:
			panic("invaid character")
		}
		for aCnt > k {
			if s[aLast] == 'a' {
				aCnt--
			}
			aLast++
		}
		for bCnt > k {
			if s[bLast] == 'b' {
				bCnt--
			}
			bLast++
		}
		if i-aLast+1 > result {
			result = i - aLast + 1
		}
		if i-bLast+1 > result {
			result = i - bLast + 1
		}
	}

	fmt.Println(result)
}
