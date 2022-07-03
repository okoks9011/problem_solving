package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func another(a, b byte) byte {
	for _, si := range []byte("SET") {
		if a != si && b != si {
			return si
		}
	}
	panic("impossible")
}

func main() {
	var n, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &k)

	cards := make([]string, n)
	for i := range cards {
		fmt.Fscan(in, &cards[i])
	}

	cardCnt := make(map[string]int)
	if len(cards) <= 0 {
		panic("impossible")
	}
	cardCnt[cards[0]] = 1

	var result int64 = 0
	for l := 1; l < n; l++ {
		cl := cards[l]

		for r := l + 1; r < n; r++ {
			cr := cards[r]

			var match []byte
			for i := 0; i < k; i++ {
				if cl[i] == cr[i] {
					match = append(match, cl[i])
				} else {
					match = append(match, another(cl[i], cr[i]))
				}
			}
			cnt, ok := cardCnt[string(match)]
			if ok {
				result += int64(cnt)
			}
		}
		cardCnt[cl]++
	}
	fmt.Println(result)
}
