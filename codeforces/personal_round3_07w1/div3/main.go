package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var s string
	fmt.Fscan(in, &s)

	markIdx := 0
	result := 0
	for i := range s {
		acc := 0
		for j := i; j >= markIdx; j-- {
			acc += int(s[j] - '0')
			if acc%3 == 0 {
				result++
				markIdx = i + 1
				break
			}
		}
	}
	fmt.Println(result)
}
