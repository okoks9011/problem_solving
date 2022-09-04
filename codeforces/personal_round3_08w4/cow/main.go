package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type sec struct {
	x1, x2 byte
}

func main() {
	var s string
	fmt.Fscan(in, &s)

	secCnt := make(map[sec]int64)
	charCnt := make(map[byte]int64)
	for i := range s {
		for c := byte('a'); c <= byte('z'); c++ {
			if v, ok := charCnt[c]; ok {
				secCnt[sec{c, s[i]}] += v
			}
		}
		charCnt[s[i]]++
	}
	var maxV int64 = 0
	for _, v := range secCnt {
		if v > maxV {
			maxV = v
		}
	}
	for _, v := range charCnt {
		if v > maxV {
			maxV = v
		}
	}
	fmt.Println(maxV)
}
