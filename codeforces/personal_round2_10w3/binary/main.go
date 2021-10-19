package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var in *bufio.Reader

func solve() {
	var n0, n1, n2 int
	fmt.Fscan(in, &n0)
	fmt.Fscan(in, &n1)
	fmt.Fscan(in, &n2)

	if n1 == 0 && n2 == 0 {
		fmt.Println(strings.Repeat("0", n0+1))
		return
	}
	if n0 == 0 && n1 == 0 {
		fmt.Println(strings.Repeat("1", n2+1))
		return
	}

	var result []string
	result = append(result, strings.Repeat("0", n0))
	result = append(result, "0")
	result = append(result, strings.Repeat("10", (n1-1)/2))
	result = append(result, "1")
	result = append(result, strings.Repeat("1", n2))
	if n1%2 == 0 && n1 > 0 {
		result = append(result, "0")
	}
	fmt.Println(strings.Join(result, ""))
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
