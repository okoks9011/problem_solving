package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	var s string
	fmt.Fscan(in, &s)

	wordCnt := n / k
	result := 0
	for i := 0; i < k/2; i++ {
		freq := make(map[byte]int)
		sym := k - 1 - i
		for j := 0; j < wordCnt; j++ {
			freq[s[j*k+i]]++
			freq[s[j*k+sym]]++
		}

		maxV := 0
		for _, v := range freq {
			if maxV < v {
				maxV = v
			}
		}
		result += 2*wordCnt - maxV
	}
	if k%2 == 1 {
		mid := k / 2
		freq := make(map[byte]int)
		for j := 0; j < wordCnt; j++ {
			freq[s[j*k+mid]]++
		}

		maxV := 0
		for _, v := range freq {
			if maxV < v {
				maxV = v
			}
		}
		result += wordCnt - maxV
	}

	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Scanln(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}
